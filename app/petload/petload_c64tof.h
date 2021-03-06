
// Marcel Timm, RhinoDevel, 2021mar26

#ifndef MT_PETLOAD_C64TOF
#define MT_PETLOAD_C64TOF

#include <stdint.h>

// How to get byte array from (PRG) file:
//
// xxd -i c64tof.prg > c64tof.h

static uint8_t const s_petload_c64tof[369] = {
  0x01, 0x08, 0x22, 0x08, 0x9d, 0x1d, 0x9e, 0x32, 0x30, 0x38, 0x34, 0x3a,
  0x8f, 0x20, 0x28, 0x43, 0x29, 0x20, 0x32, 0x30, 0x32, 0x31, 0x2c, 0x20,
  0x52, 0x48, 0x49, 0x4e, 0x4f, 0x44, 0x45, 0x56, 0x45, 0x4c, 0x00, 0x00,
  0x00, 0xa9, 0x42, 0x85, 0x5f, 0xa9, 0x08, 0x85, 0x60, 0xa9, 0x70, 0x85,
  0x5a, 0xa9, 0x09, 0x85, 0x5b, 0xa9, 0x00, 0x85, 0x58, 0xa9, 0xd0, 0x85,
  0x59, 0x20, 0xbf, 0xa3, 0x4c, 0xd2, 0xce, 0xa9, 0x4c, 0x85, 0x73, 0xa9,
  0xf1, 0x85, 0x74, 0xa9, 0xce, 0x85, 0x75, 0x78, 0xa0, 0xff, 0xa5, 0x01,
  0x49, 0x08, 0x85, 0x01, 0xa2, 0x2f, 0xca, 0xd0, 0xfd, 0x88, 0xd0, 0xf2,
  0x58, 0x60, 0xe6, 0x7a, 0xd0, 0x02, 0xe6, 0x7b, 0x84, 0x76, 0xa4, 0x7b,
  0xc0, 0x02, 0xd0, 0x28, 0xa4, 0x7a, 0xd0, 0x24, 0xb1, 0x7a, 0xc9, 0x21,
  0xd0, 0x1e, 0xe6, 0x7a, 0xb1, 0x7a, 0xf0, 0x0c, 0x99, 0xe1, 0xce, 0xc8,
  0xc0, 0x10, 0xd0, 0xf4, 0xb1, 0x7a, 0xd0, 0x0c, 0xa9, 0x20, 0xc0, 0x10,
  0xf0, 0x0b, 0x99, 0xe1, 0xce, 0xc8, 0xd0, 0xf6, 0xa4, 0x76, 0x4c, 0x79,
  0x00, 0x78, 0xa9, 0x00, 0x85, 0x77, 0x85, 0x78, 0xaa, 0xad, 0xe1, 0xce,
  0xc9, 0x2b, 0xd0, 0x08, 0xa5, 0x2b, 0x85, 0x77, 0xa5, 0x2c, 0x85, 0x78,
  0x2c, 0x0d, 0xdc, 0xbc, 0xe1, 0xce, 0x20, 0xc0, 0xcf, 0xe8, 0xe0, 0x10,
  0xd0, 0xf5, 0xa4, 0x77, 0x20, 0xc0, 0xcf, 0xa4, 0x78, 0x20, 0xc0, 0xcf,
  0xa5, 0x77, 0xd0, 0x04, 0xa5, 0x78, 0xf0, 0x22, 0xa4, 0x2d, 0x20, 0xc0,
  0xcf, 0xa4, 0x2e, 0x20, 0xc0, 0xcf, 0xb1, 0x77, 0xa8, 0x20, 0xc0, 0xcf,
  0xe6, 0x77, 0xd0, 0x02, 0xe6, 0x78, 0xa5, 0x77, 0xc5, 0x2d, 0xd0, 0xee,
  0xa5, 0x78, 0xc5, 0x2e, 0xd0, 0xe8, 0x20, 0xe1, 0xcf, 0x85, 0x77, 0x20,
  0xe1, 0xcf, 0x85, 0x78, 0xd0, 0x04, 0xa5, 0x77, 0xf0, 0x21, 0x20, 0xe1,
  0xcf, 0x85, 0x2d, 0x20, 0xe1, 0xcf, 0x85, 0x2e, 0x20, 0xe1, 0xcf, 0x81,
  0x77, 0xe6, 0x77, 0xd0, 0x02, 0xe6, 0x78, 0xa5, 0x77, 0xc5, 0x2d, 0xd0,
  0xef, 0xa5, 0x78, 0xc5, 0x2e, 0xd0, 0xe9, 0x58, 0x20, 0x59, 0xa6, 0x20,
  0x33, 0xa5, 0x4c, 0x74, 0xa4, 0x84, 0x76, 0xa0, 0x08, 0x46, 0x76, 0xa5,
  0x01, 0x29, 0xf7, 0x90, 0x02, 0x09, 0x08, 0x85, 0x01, 0xa5, 0x01, 0x49,
  0x20, 0x85, 0x01, 0xad, 0x0d, 0xdc, 0x29, 0x10, 0xf0, 0xf9, 0x88, 0xd0,
  0xe4, 0x60, 0xa2, 0x08, 0xad, 0x0d, 0xdc, 0x29, 0x10, 0xf0, 0xf9, 0xa5,
  0x01, 0x29, 0x10, 0x18, 0xf0, 0x01, 0x38, 0x66, 0x76, 0xa5, 0x01, 0x49,
  0x08, 0x85, 0x01, 0xca, 0xd0, 0xe6, 0xa5, 0x76, 0x60
};

#endif //MT_PETLOAD_C64TOF
