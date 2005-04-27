/* 256 color mode color table for Linux, partially borrowed from BootX */


unsigned char color_table_red[] = {
  0x00, 0x00, 0x00, 0x00, 0xAA, 0xAA, 0xAA, 0xAA,
  0x55, 0x55, 0x55, 0x55, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x02, 0x9E, 0xE9, 0xC4, 0x50, 0xC9, 0xC4, 0xE9,
  0x65, 0xE3, 0xC2, 0x25, 0xA4, 0xEC, 0x90, 0xA6,
  0xC4, 0x6A, 0xD1, 0xF3, 0x12, 0xED, 0xA0, 0xC2,
  0xB8, 0xD5, 0xDB, 0xD2, 0x3E, 0x16, 0xEB, 0x54,
  0xA9, 0xCD, 0xF5, 0x0A, 0xBA, 0xB3, 0xDC, 0x74,
  0xCE, 0xF6, 0xD3, 0xC5, 0xEA, 0xB8, 0xED, 0x5E,
  0xE5, 0x26, 0xF4, 0xA9, 0x82, 0x94, 0xE6, 0x38,
  0xF2, 0x0F, 0x7F, 0x49, 0xE5, 0xF4, 0xD3, 0xC3,
  0xC2, 0x1E, 0xD5, 0xC6, 0xA4, 0xFA, 0x0A, 0xBA,
  0xD4, 0xEB, 0xEA, 0xEC, 0xA8, 0xBC, 0xB4, 0xDC,
  0x84, 0xE4, 0xCE, 0xEC, 0x92, 0xCD, 0xDC, 0x8B,
  0xCC, 0x1E, 0xF6, 0xB2, 0x60, 0x2A, 0x96, 0x52,
  0x0F, 0xBD, 0xFA, 0xCC, 0xB8, 0x7A, 0x4C, 0xD2,
  0x06, 0xEF, 0x44, 0x64, 0xF4, 0xBA, 0xCE, 0xE6,
  0x8A, 0x6F, 0x3C, 0x70, 0x7C, 0x9C, 0xBA, 0xDF,
  0x2C, 0x4D, 0x3B, 0xCA, 0xDE, 0xCE, 0xEE, 0x46,
  0x6A, 0xAC, 0x96, 0xE5, 0x96, 0x7A, 0xBA, 0xB6,
  0xE2, 0x7E, 0xAA, 0xC5, 0x96, 0x9E, 0xC2, 0xAA,
  0xDA, 0x35, 0xB6, 0x82, 0x88, 0xBE, 0xC2, 0x9E,
  0xB4, 0xD5, 0xDA, 0x9C, 0xA0, 0xD0, 0xA8, 0xC7,
  0x72, 0xF2, 0xDB, 0x76, 0xDC, 0xBE, 0xAA, 0xF4,
  0x87, 0x2F, 0x53, 0x8E, 0x36, 0xCE, 0xE6, 0xCA,
  0xCB, 0xE4, 0xD6, 0xAA, 0x42, 0x5D, 0xB4, 0x59,
  0x1C, 0xC8, 0x96, 0x6C, 0xDA, 0xCE, 0xE6, 0xCB,
  0x96, 0x16, 0xFA, 0xBE, 0xAE, 0xFE, 0x6E, 0xD6,
  0xCE, 0xB6, 0xE5, 0xED, 0xDB, 0xDC, 0xF4, 0x72,
  0x1F, 0xAE, 0xE6, 0xC2, 0xCA, 0xC4, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};

unsigned char color_table_green[] = {
  0x00, 0x00, 0xAA, 0xAA, 0x00, 0x00, 0xAA, 0xAA,
  0x55, 0x55, 0xFF, 0xFF, 0x55, 0x55, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x02, 0x88, 0xC4, 0x85, 0x44, 0xA2, 0xA8, 0xE5,
  0x65, 0xA6, 0xC2, 0x24, 0xA4, 0xB4, 0x62, 0x86,
  0x94, 0x44, 0xD2, 0xB6, 0x12, 0xD4, 0x73, 0x96,
  0x92, 0x95, 0xB2, 0xC2, 0x36, 0x0E, 0xBC, 0x54,
  0x75, 0xA5, 0xF5, 0x0A, 0xB2, 0x83, 0xC2, 0x74,
  0x9B, 0xBD, 0xA2, 0xCA, 0xDA, 0x8C, 0xCB, 0x42,
  0xAC, 0x12, 0xDA, 0x7B, 0x54, 0x94, 0xD2, 0x24,
  0xBE, 0x06, 0x65, 0x33, 0xBB, 0xBC, 0xAB, 0x8C,
  0x92, 0x1E, 0x9B, 0xB6, 0x6E, 0xFB, 0x04, 0xA2,
  0xC8, 0xBD, 0xAD, 0xEC, 0x92, 0xBC, 0x7B, 0x9D,
  0x84, 0xC4, 0xC4, 0xB4, 0x6C, 0x93, 0xA3, 0x5E,
  0x8D, 0x13, 0xD6, 0x82, 0x4C, 0x2A, 0x7A, 0x5A,
  0x0D, 0x82, 0xBB, 0xCC, 0x8B, 0x6A, 0x3C, 0xBE,
  0x06, 0xC4, 0x44, 0x45, 0xDB, 0x96, 0xB6, 0xDE,
  0x8A, 0x4D, 0x3C, 0x5A, 0x7C, 0x9C, 0xAA, 0xCB,
  0x1C, 0x4D, 0x2E, 0xB2, 0xBE, 0xAA, 0xDE, 0x3E,
  0x6A, 0xAC, 0x82, 0xE5, 0x72, 0x62, 0x92, 0x9E,
  0xCA, 0x4A, 0x8E, 0xBE, 0x86, 0x6B, 0xAA, 0x9A,
  0xBE, 0x34, 0xAB, 0x76, 0x6E, 0x9A, 0x9E, 0x62,
  0x76, 0xCE, 0xD3, 0x92, 0x7C, 0xB8, 0x7E, 0xC6,
  0x5E, 0xE2, 0xC3, 0x54, 0xAA, 0x9E, 0x8A, 0xCA,
  0x63, 0x2D, 0x3B, 0x8E, 0x1A, 0x9E, 0xC2, 0xA6,
  0xCB, 0xDC, 0xD6, 0x8E, 0x26, 0x5C, 0xB4, 0x45,
  0x1C, 0xB8, 0x6E, 0x4C, 0xBC, 0xAE, 0xD6, 0x92,
  0x63, 0x16, 0xF6, 0x8C, 0x7A, 0xFE, 0x6E, 0xBA,
  0xC6, 0x86, 0xAA, 0xAE, 0xDB, 0xA4, 0xD4, 0x56,
  0x0E, 0x6E, 0xB6, 0xB2, 0xBE, 0xBE, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF
};


unsigned char color_table_blue[] = {
  0x00, 0xAA, 0x00, 0xAA, 0x00, 0xAA, 0x00, 0xAA,
  0x55, 0xFF, 0x55, 0xFF, 0x55, 0xFF, 0x55, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
  0x04, 0x28, 0x10, 0x0B, 0x14, 0x14, 0x74, 0xC7,
  0x64, 0x0E, 0xC3, 0x24, 0xA4, 0x0C, 0x10, 0x20,
  0x0D, 0x04, 0xD1, 0x0D, 0x13, 0x22, 0x0A, 0x40,
  0x14, 0x0C, 0x11, 0x94, 0x0C, 0x08, 0x0B, 0x56,
  0x09, 0x47, 0xF4, 0x0B, 0x9C, 0x07, 0x54, 0x74,
  0x0F, 0x0C, 0x0F, 0xC7, 0x6C, 0x14, 0x14, 0x11,
  0x0B, 0x04, 0x12, 0x0C, 0x05, 0x94, 0x94, 0x0A,
  0x34, 0x09, 0x14, 0x08, 0x2F, 0x15, 0x19, 0x11,
  0x28, 0x0C, 0x0B, 0x94, 0x08, 0xFA, 0x08, 0x7C,
  0xBC, 0x15, 0x0A, 0xEC, 0x64, 0xBB, 0x0A, 0x0C,
  0x84, 0x2C, 0xA0, 0x15, 0x10, 0x0D, 0x0B, 0x0E,
  0x0A, 0x07, 0x10, 0x3C, 0x24, 0x2C, 0x28, 0x5C,
  0x0A, 0x0D, 0x0A, 0xC1, 0x22, 0x4C, 0x10, 0x94,
  0x04, 0x0F, 0x45, 0x08, 0x31, 0x54, 0x3C, 0xBC,
  0x8C, 0x09, 0x3C, 0x18, 0x7C, 0x9C, 0x7C, 0x91,
  0x0C, 0x4D, 0x17, 0x74, 0x0C, 0x48, 0x9C, 0x3C,
  0x6A, 0xAC, 0x5C, 0xE3, 0x29, 0x3C, 0x2C, 0x7C,
  0x6C, 0x04, 0x14, 0xA9, 0x74, 0x07, 0x2C, 0x74,
  0x4C, 0x34, 0x97, 0x5C, 0x38, 0x0C, 0x5C, 0x04,
  0x0C, 0xBA, 0xBC, 0x78, 0x18, 0x88, 0x24, 0xC2,
  0x3C, 0xB4, 0x87, 0x0C, 0x14, 0x4C, 0x3C, 0x10,
  0x17, 0x2C, 0x0A, 0x8C, 0x04, 0x1C, 0x44, 0x2C,
  0xCD, 0xD8, 0xD4, 0x34, 0x0C, 0x5B, 0xB4, 0x1E,
  0x1D, 0xAC, 0x24, 0x18, 0x20, 0x5C, 0xB4, 0x1C,
  0x09, 0x14, 0xFC, 0x0C, 0x10, 0xFC, 0x6C, 0x7C,
  0xB4, 0x1C, 0x15, 0x17, 0xDB, 0x18, 0x21, 0x24,
  0x04, 0x04, 0x44, 0x8C, 0x8C, 0xB7, 0xFF, 0xFF,
  0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF,
};
