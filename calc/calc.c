
// Marcel Timm, RhinoDevel, 2018oct26

#include "calc.h"

static char calc_get_hex(uint8_t const n)
{
    if(n < 10)
    {
        return '0' + n;
    }
    if(n < 16)
    {
        return 'a' + n - 10;
    }
    return '?';
}

void calc_byte_to_hex(
    uint8_t const byte, char * const out_high, char * const out_low)
{
    uint8_t const high = byte / 16,
        low = byte - 16 * high;

    *out_high = calc_get_hex(high);
    *out_low = calc_get_hex(low);
}

void calc_word_to_hex(uint16_t const word, char * const out_four)
{
    uint8_t const high = word / 256,
        low = word - 256 * high;

    calc_byte_to_hex(high, out_four, out_four + 1);
    calc_byte_to_hex(low, out_four + 2, out_four + 3);
}

void calc_dword_to_hex(uint32_t const dword, char * const out_eight)
{
    uint16_t const high = dword / 65536,
        low = dword - 65536 * high;

    calc_word_to_hex(high, out_eight);
    calc_word_to_hex(low, out_eight + 4);
}
