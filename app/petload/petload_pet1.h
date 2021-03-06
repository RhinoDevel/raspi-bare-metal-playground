
// Marcel Timm, RhinoDevel, 2021feb21

#ifndef MT_PETLOAD_PET1
#define MT_PETLOAD_PET1

#include <stdint.h>

// How to get byte array from (PRG) file:
//
// xxd -i pet1.prg > pet1.h

static uint8_t const s_petload_pet1[325] = {
  0x8f, 0x02, 0xa9, 0x4c, 0x85, 0xc2, 0xa9, 0xb2, 0x85, 0xc3, 0xa9, 0x02,
  0x85, 0xc4, 0x78, 0xa0, 0xff, 0xad, 0x40, 0xe8, 0x49, 0x08, 0x8d, 0x40,
  0xe8, 0xa2, 0x2f, 0xca, 0xd0, 0xfd, 0x88, 0xd0, 0xf0, 0x58, 0x4c, 0x53,
  0xc5, 0xe6, 0xc9, 0xd0, 0x02, 0xe6, 0xca, 0x84, 0xc5, 0xa4, 0xca, 0xc0,
  0x00, 0xd0, 0x2c, 0xa4, 0xc9, 0xc0, 0x0a, 0xd0, 0x26, 0xa0, 0x00, 0xb1,
  0xc9, 0xc9, 0x21, 0xd0, 0x1e, 0xe6, 0xc9, 0xb1, 0xc9, 0xf0, 0x0c, 0x99,
  0xa2, 0x02, 0xc8, 0xc0, 0x10, 0xd0, 0xf4, 0xb1, 0xc9, 0xd0, 0x0c, 0xa9,
  0x20, 0xc0, 0x10, 0xf0, 0x0b, 0x99, 0xa2, 0x02, 0xc8, 0xd0, 0xf6, 0xa4,
  0xc5, 0x4c, 0xc8, 0x00, 0x78, 0xa9, 0x00, 0x85, 0xc6, 0x85, 0xc7, 0xaa,
  0xad, 0xa2, 0x02, 0xc9, 0x2b, 0xd0, 0x08, 0xa5, 0x7a, 0x85, 0xc6, 0xa5,
  0x7b, 0x85, 0xc7, 0x2c, 0x10, 0xe8, 0xbc, 0xa2, 0x02, 0x20, 0x85, 0x03,
  0xe8, 0xe0, 0x10, 0xd0, 0xf5, 0xa4, 0xc6, 0x20, 0x85, 0x03, 0xa4, 0xc7,
  0x20, 0x85, 0x03, 0xa5, 0xc6, 0xd0, 0x04, 0xa5, 0xc7, 0xf0, 0x22, 0xa4,
  0x7c, 0x20, 0x85, 0x03, 0xa4, 0x7d, 0x20, 0x85, 0x03, 0xb1, 0xc6, 0xa8,
  0x20, 0x85, 0x03, 0xe6, 0xc6, 0xd0, 0x02, 0xe6, 0xc7, 0xa5, 0xc6, 0xc5,
  0x7c, 0xd0, 0xee, 0xa5, 0xc7, 0xc5, 0x7d, 0xd0, 0xe8, 0x20, 0xad, 0x03,
  0x85, 0xc6, 0x20, 0xad, 0x03, 0x85, 0xc7, 0xd0, 0x04, 0xa5, 0xc6, 0xf0,
  0x21, 0x20, 0xad, 0x03, 0x85, 0x7c, 0x20, 0xad, 0x03, 0x85, 0x7d, 0x20,
  0xad, 0x03, 0x81, 0xc6, 0xe6, 0xc6, 0xd0, 0x02, 0xe6, 0xc7, 0xa5, 0xc6,
  0xc5, 0x7c, 0xd0, 0xef, 0xa5, 0xc7, 0xc5, 0x7d, 0xd0, 0xe9, 0x58, 0x20,
  0x67, 0xc5, 0x20, 0x33, 0xc4, 0x4c, 0x8b, 0xc3, 0x84, 0xc5, 0xa0, 0x08,
  0x46, 0xc5, 0xad, 0x40, 0xe8, 0x29, 0xf7, 0x90, 0x02, 0x09, 0x08, 0x8d,
  0x40, 0xe8, 0xad, 0x13, 0xe8, 0x49, 0x08, 0x8d, 0x13, 0xe8, 0xad, 0x11,
  0xe8, 0x29, 0x80, 0xf0, 0xf9, 0x2c, 0x10, 0xe8, 0x88, 0xd0, 0xdd, 0x60,
  0xa2, 0x08, 0xad, 0x11, 0xe8, 0x29, 0x80, 0xf0, 0xf9, 0x2c, 0x10, 0xe8,
  0xad, 0x10, 0xe8, 0x29, 0x10, 0x18, 0xf0, 0x01, 0x38, 0x66, 0xc5, 0xad,
  0x40, 0xe8, 0x49, 0x08, 0x8d, 0x40, 0xe8, 0xca, 0xd0, 0xe0, 0xa5, 0xc5,
  0x60
};

#endif //MT_PETLOAD_PET1
