
// Marcel Timm, RhinoDevel, 2018nov16

#ifndef MT_CONFIG
#define MT_CONFIG

#define MT_HEAP_SIZE (32 * 1024 * 1024) // 32 MB.

#define MT_TAPE_GPIO_PIN_NR_READ 2
#define MT_TAPE_GPIO_PIN_NR_SENSE 3
#define MT_TAPE_GPIO_PIN_NR_MOTOR 4

// Set this additionally (for 32 bit):
//
// ./alloc/allocconf.h: #define MT_ALLOC_BITS MT_ALLOC_BITS_32

#endif //MT_CONFIG