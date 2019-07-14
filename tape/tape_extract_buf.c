
// Marcel Timm, RhinoDevel, 2019jul13

#include <stdbool.h>
#include <stdint.h>

#include "../alloc/alloc.h"
#include "../console/console.h"
#include "../mem/mem.h"
#include "tape_extract_buf.h"
#include "tape_input.h"
#include "tape_symbol.h"

// TODO: Replace!
//
//static int const header_data_byte_count = 192;

static void consume_sync(uint8_t const * const buf, int * const pos)
{
    while(buf[*pos] == tape_symbol_sync)
    {
        ++(*pos);
    }
}

static bool extract_byte(
    uint8_t const * const buf, int * const pos, uint8_t * const byte)
{
    uint8_t byte_buf = 0,
        parity = 1;

    // New data marker:

    if(buf[*pos] != tape_symbol_new)
    {
        return false;
    }
    ++(*pos);

    // Payload bits:

    for(int i = 0;i < 8;++i)
    {
        if(buf[*pos] == tape_symbol_zero)
        {
            parity ^= 0;

            ++(*pos);
            continue;
        }
        if(buf[*pos] == tape_symbol_one)
        {
            byte_buf &= (1 << i);
            parity ^= 1;

            ++(*pos);
            continue;
        }
        return false;
    }

    // Parity bit:
    //
    switch(buf[*pos])
    {
        case tape_symbol_zero:
        {
            if(parity != 0)
            {
                return false;
            }
            break;
        }
        case tape_symbol_one:
        {
            if(parity != 1)
            {
                return false;
            }
            break;
        }

        default:
        {
            return false; // Unexpected symbol.
        }
    }

    *byte = byte_buf;
    return true;
}

static bool consume_countdown(
    bool const second, uint8_t const * const buf, int * const pos)
{
    uint8_t c = second ? 9 : 0x89,
        lim = second ? 0 : 0x80;

    while(c > lim)
    {
        uint8_t byte;

        if(!extract_byte(buf, pos, &byte))
        {
            console_writeline(
                "consume_countdown : Error: Failed to extract byte value!");
            return false;
        }

        if(byte != c)
        {
            console_writeline(
                "consume_countdown : Error: Unexpected byte value received!");
            return false;
        }
        --c;
    }
    return true;
}

/**
 * - Caller takes ownership of return value.
 */
static uint8_t* get_payload_from_transmit_data(
    uint8_t const * const buf, int * const pos, int * const len)
{
    static int const byte_symbol_count = 10;
    //
    // Hard-coded, see extract_byte().

    int offset_end = 0,
        payload_byte_count;
    uint8_t *payload,
        byte,
        checksum = 0;

    while(true)
    {
        uint8_t const cur = buf[*pos + offset_end];

        if(cur == tape_symbol_done)
        {
            return 0; // Expected symbol could not be found.
        }

        if(cur == tape_symbol_end)
        {
            // Found optional end-of-data marker or transmit block gap start.

            break;
        }

        ++offset_end;
    }

    // offset_end == symbol count for payload bytes plus parity byte:
    //
    payload_byte_count = offset_end * byte_symbol_count - 1;

    // Payload:

    payload = alloc_alloc(payload_byte_count * sizeof *payload);
    if(payload == 0)
    {
        return 0;
    }

    for(int i = 0;i < payload_byte_count;++i)
    {
        if(!extract_byte(buf, pos, &byte))
        {
            alloc_free(payload);
            return 0;
        }
        payload[i] = byte;
        checksum ^= byte;
    }

    // Checksum:

    if(!extract_byte(buf, pos, &byte))
    {
        alloc_free(payload);
        return 0;
    }
    if(byte != checksum)
    {
        alloc_free(payload);
        return 0;
    }

    // Optional end-of-data marker:

    if(buf[*pos + offset_end + 1] == tape_symbol_end)
    {
        // This is the optional end-of-data marker:

        ++(*pos); // Consume optional end-of-data marker.
    }
    //
    // Otherwise: This is the start of transmit block gap.

    *len = payload_byte_count;
    return payload;
}

static uint8_t* get_data_from_transmit(
    bool const second,
    uint8_t const * const buf,
    int * const pos,
    int * const len)
{
    uint8_t* payload;

    // First countdown sequence:

    consume_countdown(second, buf, pos);

    // Data:

    payload = get_payload_from_transmit_data(buf, pos, len);
    if(payload == 0)
    {
        return 0;
    }

    // Transmit block gap:

    // TODO: Implement!
    //
    return 0;
}

/**
 * - Consumes leading sync symbols.
 * - Caller takes ownership of return value.
 */
static uint8_t* get_data_following_sync(
    uint8_t const * const buf, int * const pos, int * const len)
{
    uint8_t *data_first,
        *data_second;
    int len_first,
        len_second;

    // Synchronization:

    consume_sync(buf, pos);

    // Data:

    // 1st data transmit:
    //
    data_first = get_data_from_transmit(false, buf, pos, &len_first);
    if(data_first == 0)
    {
        return 0;
    }

    // 2nd data transmit:
    //
    data_second = get_data_from_transmit(true, buf, pos, &len_second);
    if(data_second == 0)
    {
        alloc_free(data_first);
        return 0;
    }

    if(len_first != len_second)
    {
        alloc_free(data_first);
        alloc_free(data_second);
        return 0;
    }
    if(!mem_cmp_byte(data_first, data_second, len_first))
    {
        alloc_free(data_first);
        alloc_free(data_second);
        return 0;
    }

    alloc_free(data_second);
    *len = len_first;
    return data_first;
}

static bool extract_headerdatablock(
    uint8_t const * const buf, int * const pos, struct tape_input * const input)
{
    (void)input; // TODO: Remove!

    int len;
    uint8_t* data = get_data_following_sync(buf, pos, &len);

    if(data == 0)
    {
        return false;
    }

    alloc_free(data);

    // TODO: Implement!
    //
    return false;
}

static bool extract_contentdatablock(
    uint8_t const * const buf, int * const pos, struct tape_input * const input)
{
    (void)input; // TODO: Remove!

    int len;
    uint8_t* data = get_data_following_sync(buf, pos, &len);

    if(data == 0)
    {
        return false;
    }

    alloc_free(data);

    // TODO: Implement!
    //
    return false;
}

struct tape_input * tape_extract_buf(uint8_t const * const buf)
{
    struct tape_input * const input = alloc_alloc(sizeof *input);
    int i = 0;

    if(input == 0)
    {
        console_writeline(
            "tape_extract_buf: Error: Failed to allocate input memory!");
        return 0;
    }

    if(!extract_headerdatablock(buf, &i, input))
    {
        alloc_free(input);
        return 0;
    }

    if(!extract_contentdatablock(buf, &i, input))
    {
        alloc_free(input);
        return 0;
    }

    return input;
}
