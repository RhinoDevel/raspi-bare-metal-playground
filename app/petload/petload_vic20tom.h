
// Marcel Timm, RhinoDevel, 2021mar12

#ifndef MT_PETLOAD_VIC20TOM
#define MT_PETLOAD_VIC20TOM

#include <stdint.h>

// How to get byte array from (PRG) file:
//
// xxd -i vic20tom.prg > vic20tom.h

static uint8_t const s_petload_vic20tom[540] = {
  0x01, 0x10, 0x22, 0x10, 0x9d, 0x1d, 0x9e, 0x34, 0x31, 0x33, 0x32, 0x3a,
  0x8f, 0x20, 0x28, 0x43, 0x29, 0x20, 0x32, 0x30, 0x32, 0x31, 0x2c, 0x20,
  0x52, 0x48, 0x49, 0x4e, 0x4f, 0x44, 0x45, 0x56, 0x45, 0x4c, 0x00, 0x00,
  0x00, 0x38, 0xa5, 0x37, 0xe9, 0x18, 0x8d, 0xd8, 0x10, 0xa5, 0x38, 0xe9,
  0x01, 0x8d, 0xdc, 0x10, 0x38, 0xa5, 0x37, 0xe9, 0x48, 0x8d, 0x47, 0x11,
  0x8d, 0x59, 0x11, 0x8d, 0x22, 0x11, 0x8d, 0x34, 0x11, 0xa5, 0x38, 0xe9,
  0x01, 0x8d, 0x48, 0x11, 0x8d, 0x5a, 0x11, 0x8d, 0x23, 0x11, 0x8d, 0x35,
  0x11, 0x38, 0xa5, 0x37, 0xe9, 0x49, 0x8d, 0x5c, 0x11, 0x8d, 0x66, 0x11,
  0x8d, 0x6b, 0x11, 0x8d, 0x78, 0x11, 0x8d, 0x7d, 0x11, 0x8d, 0x83, 0x11,
  0xa5, 0x38, 0xe9, 0x00, 0x8d, 0x5d, 0x11, 0x8d, 0x67, 0x11, 0x8d, 0x6c,
  0x11, 0x8d, 0x79, 0x11, 0x8d, 0x7e, 0x11, 0x8d, 0x84, 0x11, 0x38, 0xa5,
  0x37, 0xe9, 0x23, 0x8d, 0x98, 0x11, 0x8d, 0x9d, 0x11, 0x8d, 0xa8, 0x11,
  0x8d, 0xad, 0x11, 0x8d, 0xb2, 0x11, 0xa5, 0x38, 0xe9, 0x00, 0x8d, 0x99,
  0x11, 0x8d, 0x9e, 0x11, 0x8d, 0xa9, 0x11, 0x8d, 0xae, 0x11, 0x8d, 0xb3,
  0x11, 0xa9, 0xd3, 0x85, 0x5f, 0xa9, 0x10, 0x85, 0x60, 0xa9, 0x1b, 0x85,
  0x5a, 0xa9, 0x12, 0x85, 0x5b, 0xa5, 0x37, 0x85, 0x58, 0xa5, 0x38, 0x85,
  0x59, 0x20, 0xbf, 0xc3, 0x38, 0xa5, 0x37, 0xe9, 0x48, 0x85, 0x37, 0xa5,
  0x38, 0xe9, 0x01, 0x85, 0x38, 0x6c, 0x37, 0x00, 0xa9, 0x4c, 0x85, 0x73,
  0xa9, 0x03, 0x85, 0x74, 0xa9, 0x11, 0x85, 0x75, 0x78, 0xad, 0x1c, 0x91,
  0x29, 0xfd, 0x8d, 0x1c, 0x91, 0xad, 0x11, 0x91, 0x29, 0x40, 0xf0, 0xf9,
  0xa0, 0xff, 0xad, 0x20, 0x91, 0x49, 0x08, 0x8d, 0x20, 0x91, 0xa2, 0x2f,
  0xca, 0xd0, 0xfd, 0x88, 0xd0, 0xf0, 0x58, 0x60, 0xe6, 0x7a, 0xd0, 0x02,
  0xe6, 0x7b, 0x84, 0x76, 0xa4, 0x7b, 0xc0, 0x02, 0xd0, 0x28, 0xa4, 0x7a,
  0xd0, 0x24, 0xb1, 0x7a, 0xc9, 0x21, 0xd0, 0x1e, 0xe6, 0x7a, 0xb1, 0x7a,
  0xf0, 0x0c, 0x99, 0xd3, 0x10, 0xc8, 0xc0, 0x10, 0xd0, 0xf4, 0xb1, 0x7a,
  0xd0, 0x0c, 0xa9, 0x20, 0xc0, 0x10, 0xf0, 0x0b, 0x99, 0xd3, 0x10, 0xc8,
  0xd0, 0xf6, 0xa4, 0x76, 0x4c, 0x79, 0x00, 0x78, 0xa9, 0x00, 0x85, 0x77,
  0x85, 0x78, 0xaa, 0xad, 0xd3, 0x10, 0xc9, 0x2b, 0xd0, 0x08, 0xa5, 0x2b,
  0x85, 0x77, 0xa5, 0x2c, 0x85, 0x78, 0x2c, 0x2c, 0x91, 0xbc, 0xd3, 0x10,
  0x20, 0xd2, 0x11, 0xe8, 0xe0, 0x10, 0xd0, 0xf5, 0xa4, 0x77, 0x20, 0xd2,
  0x11, 0xa4, 0x78, 0x20, 0xd2, 0x11, 0xa5, 0x77, 0xd0, 0x04, 0xa5, 0x78,
  0xf0, 0x22, 0xa4, 0x2d, 0x20, 0xd2, 0x11, 0xa4, 0x2e, 0x20, 0xd2, 0x11,
  0xb1, 0x77, 0xa8, 0x20, 0xd2, 0x11, 0xe6, 0x77, 0xd0, 0x02, 0xe6, 0x78,
  0xa5, 0x77, 0xc5, 0x2d, 0xd0, 0xee, 0xa5, 0x78, 0xc5, 0x2e, 0xd0, 0xe8,
  0x20, 0xf8, 0x11, 0x85, 0x77, 0x20, 0xf8, 0x11, 0x85, 0x78, 0xd0, 0x04,
  0xa5, 0x77, 0xf0, 0x21, 0x20, 0xf8, 0x11, 0x85, 0x2d, 0x20, 0xf8, 0x11,
  0x85, 0x2e, 0x20, 0xf8, 0x11, 0x81, 0x77, 0xe6, 0x77, 0xd0, 0x02, 0xe6,
  0x78, 0xa5, 0x77, 0xc5, 0x2d, 0xd0, 0xef, 0xa5, 0x78, 0xc5, 0x2e, 0xd0,
  0xe9, 0x58, 0x20, 0x59, 0xc6, 0x20, 0x33, 0xc5, 0x4c, 0x74, 0xc4, 0x84,
  0x76, 0xa0, 0x08, 0x46, 0x76, 0xad, 0x20, 0x91, 0x29, 0xf7, 0x90, 0x02,
  0x09, 0x08, 0x8d, 0x20, 0x91, 0xad, 0x1c, 0x91, 0x49, 0x02, 0x8d, 0x1c,
  0x91, 0x2c, 0x2d, 0x91, 0x10, 0xfb, 0x2c, 0x2c, 0x91, 0x88, 0xd0, 0xdf,
  0x60, 0xa2, 0x08, 0x2c, 0x2d, 0x91, 0x10, 0xfb, 0x2c, 0x2c, 0x91, 0xad,
  0x11, 0x91, 0x29, 0x40, 0x18, 0xf0, 0x01, 0x38, 0x66, 0x76, 0xad, 0x20,
  0x91, 0x49, 0x08, 0x8d, 0x20, 0x91, 0xca, 0xd0, 0xe2, 0xa5, 0x76, 0x60
};

#endif //MT_PETLOAD_VIC20TOM
