#ifdef _WIN32
#include <stdint.h>
#define PROGMEM
#else
#include <Arduino.h>
#endif
#include "Artino_Font.h"
//#include "ucs2_gbk.h"
#include "ASCII16.h"

const uint8_t hzk16Bitmap[] PROGMEM = {
#include "hzk16.h"
};

const size_t hzk16Size = sizeof(hzk16Bitmap);

// UCS2转GBK编码
namespace Encoding
{
    uint16_t UCS2GBK(uint16_t ch);
}


const uint8_t aASCIIBitmap32[] = {
  0x00, 0x03, 0xff, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xc7, 0xff, 0xe0, 0x3f, 0xfe, 0x0f, 0xff, 0x80, 0xff, 0xf8, 0x3f, 0xfe, 0x03, 0xff, 0xe0, 0xff, 0xf8, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x0f, 0xff, 0x83, 0xff, 0xe0, 0x3f, 0xfe, 0x0f, 0xff, 0x80, 0xff, 0xfc, 0x7f, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 0
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0f, 0xf0, 0x00, 0x00, 0x00, 0x7f, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x3f, 0xfc, 0x00, 0x00, 0x01, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x03, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0x00, 0x03, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0xff, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 1
  0x00, 0x03, 0xfe, 0x00, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x07, 0xff, 0xff, 0x00, 0x00, 0x3f, 0xff, 0xfe, 0x00, 0x01, 0xff, 0xff, 0xfc, 0x00, 0x07, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x01, 0xff, 0xff, 0xff, 0xc0, 0x07, 0xff, 0x1f, 0xff, 0x80, 0x1f, 0xfc, 0x3f, 0xfe, 0x00, 0xff, 0xe0, 0xff, 0xf8, 0x03, 0xff, 0x83, 0xff, 0xf0, 0x0f, 0xfe, 0x0f, 0xff, 0xc0, 0x3f, 0xf8, 0x3f, 0xff, 0x00, 0xff, 0xe0, 0xff, 0xfc, 0x03, 0xff, 0x83, 0xff, 0xf0, 0x0f, 0xfe, 0x0f, 0xff, 0xc0, 0x3f, 0xf8, 0x7f, 0xff, 0x00, 0xff, 0xe1, 0xff, 0xfc, 0x03, 0xff, 0x87, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0xff, 0xff, 0x00, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xe0, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x03, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x01, 0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x3f, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x07, 0xff, 0xf8, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0xff, 0xff, 0xff, 0xf8, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x3f, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 2
  0x00, 0x0f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0xff, 0xff, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x0f, 0xff, 0x9f, 0xff, 0x80, 0x7f, 0xfc, 0x3f, 0xfe, 0x01, 0xff, 0xf0, 0xff, 0xfc, 0x07, 0xff, 0xc3, 0xff, 0xf0, 0x1f, 0xff, 0x0f, 0xff, 0xc0, 0x7f, 0xfc, 0x3f, 0xff, 0x01, 0xff, 0xf0, 0xff, 0xfc, 0x07, 0xff, 0xc3, 0xff, 0xf0, 0x1f, 0xff, 0x0f, 0xff, 0xc0, 0x7f, 0xfc, 0x3f, 0xff, 0x01, 0xff, 0xf0, 0xff, 0xfc, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x01, 0xff, 0xff, 0x80, 0x00, 0x07, 0xff, 0xfc, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x01, 0xff, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xff, 0x80, 0x00, 0x1f, 0xff, 0xff, 0x00, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0x0f, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfe, 0x07, 0xff, 0xc1, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0xff, 0xe0, 0x7f, 0xfc, 0x1f, 0xff, 0x81, 0xff, 0xf0, 0x7f, 0xfe, 0x07, 0xff, 0xc1, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0xff, 0xe0, 0x7f, 0xfc, 0x1f, 0xff, 0x81, 0xff, 0xf0, 0x7f, 0xfe, 0x07, 0xff, 0xc1, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0xff, 0xe0, 0x7f, 0xfc, 0x1f, 0xff, 0x81, 0xff, 0xf0, 0x7f, 0xfe, 0x07, 0xff, 0xc1, 0xff, 0xf8, 0x0f, 0xff, 0x07, 0xff, 0xc0, 0x3f, 0xfc, 0x1f, 0xff, 0x00, 0xff, 0xf8, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 3
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xfe, 0x00, 0x00, 0x7f, 0xff, 0xf8, 0x00, 0x01, 0xff, 0xff, 0xe0, 0x00, 0x0f, 0xff, 0xff, 0x80, 0x00, 0x3f, 0xff, 0xfe, 0x00, 0x00, 0xff, 0xff, 0xf8, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x1f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xfe, 0x00, 0x03, 0xff, 0xff, 0xf8, 0x00, 0x0f, 0xff, 0xff, 0xe0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x01, 0xff, 0xff, 0xfe, 0x00, 0x07, 0xff, 0xff, 0xf8, 0x00, 0x1f, 0xff, 0xff, 0xe0, 0x00, 0xff, 0xbf, 0xff, 0x80, 0x03, 0xfe, 0xff, 0xfe, 0x00, 0x0f, 0xfb, 0xff, 0xf8, 0x00, 0x7f, 0xcf, 0xff, 0xe0, 0x01, 0xff, 0x3f, 0xff, 0x80, 0x07, 0xfc, 0xff, 0xfe, 0x00, 0x3f, 0xf3, 0xff, 0xf8, 0x00, 0xff, 0x8f, 0xff, 0xe0, 0x03, 0xfe, 0x3f, 0xff, 0x80, 0x1f, 0xf8, 0xff, 0xfe, 0x00, 0x7f, 0xc3, 0xff, 0xf8, 0x01, 0xff, 0x0f, 0xff, 0xe0, 0x0f, 0xfc, 0x3f, 0xff, 0x80, 0x3f, 0xf0, 0xff, 0xfe, 0x00, 0xff, 0x83, 0xff, 0xf8, 0x07, 0xfe, 0x0f, 0xff, 0xe0, 0x1f, 0xf8, 0x3f, 0xff, 0x80, 0x7f, 0xc0, 0xff, 0xfe, 0x03, 0xff, 0x03, 0xff, 0xf8, 0x0f, 0xfc, 0x0f, 0xff, 0xe0, 0x3f, 0xf0, 0x3f, 0xff, 0x81, 0xff, 0x80, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xfe, 0x7f, 0xff, 0xff, 0xff, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xe7, 0xff, 0xff, 0xff, 0xff, 0x9f, 0xff, 0xff, 0xff, 0xfe, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 4
  0x00, 0x00, 0x00, 0x00, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x1f, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x07, 0xff, 0x80, 0x00, 0x00, 0x1f, 0xfe, 0x00, 0x00, 0x00, 0x7f, 0xf8, 0x00, 0x00, 0x01, 0xff, 0xe0, 0x00, 0x00, 0x0f, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xfe, 0x0f, 0xe0, 0x00, 0xff, 0xf8, 0xff, 0xf0, 0x03, 0xff, 0xef, 0xff, 0xe0, 0x0f, 0xff, 0xff, 0xff, 0xc0, 0x3f, 0xff, 0xff, 0xff, 0x80, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0x8f, 0xff, 0xc0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x07, 0xff, 0xc1, 0xff, 0xf8, 0x1f, 0xff, 0x07, 0xff, 0xc0, 0x7f, 0xfe, 0x1f, 0xff, 0x01, 0xff, 0xf8, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xfc, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x7f, 0xff, 0xff, 0x80, 0x00, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x7f, 0xff, 0x80, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 5
  0x00, 0x01, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x01, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xc7, 0xff, 0xe0, 0x3f, 0xfe, 0x0f, 0xff, 0x80, 0xff, 0xf8, 0x3f, 0xfe, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x1f, 0xff, 0x83, 0xf0, 0x00, 0x7f, 0xfe, 0x3f, 0xf8, 0x01, 0xff, 0xf9, 0xff, 0xf0, 0x07, 0xff, 0xef, 0xff, 0xe0, 0x1f, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0x81, 0xff, 0xff, 0xff, 0xfe, 0x07, 0xff, 0xff, 0xff, 0xf8, 0x1f, 0xff, 0xc7, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x0f, 0xff, 0x83, 0xff, 0xf0, 0x3f, 0xfe, 0x1f, 0xff, 0x80, 0xff, 0xfc, 0x7f, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x1f, 0xff, 0xff, 0xf8, 0x00, 0x3f, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x1f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 6
  0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xf8, 0x01, 0xff, 0xff, 0xff, 0xe0, 0x07, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x07, 0xff, 0xf0, 0x00, 0x00, 0x1f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xe0, 0x00, 0x00, 0x3f, 0xff, 0x80, 0x00, 0x00, 0xff, 0xfe, 0x00, 0x00, 0x03, 0xff, 0xf8, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x7f, 0xff, 0x00, 0x00, 0x01, 0xff, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 7
  0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xff, 0xe0, 0x00, 0x07, 0xff, 0xff, 0xe0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0x80, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xc7, 0xff, 0xe0, 0x3f, 0xfe, 0x0f, 0xff, 0x81, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x0f, 0xff, 0x83, 0xff, 0xf0, 0x3f, 0xfe, 0x0f, 0xff, 0x80, 0xff, 0xf8, 0x3f, 0xfe, 0x01, 0xff, 0xf1, 0xff, 0xf0, 0x03, 0xff, 0xff, 0xff, 0x80, 0x07, 0xff, 0xff, 0xfc, 0x00, 0x0f, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x03, 0xff, 0xff, 0xff, 0x80, 0x1f, 0xff, 0xff, 0xff, 0x00, 0xff, 0xff, 0xff, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x0f, 0xff, 0xc7, 0xff, 0xe0, 0x3f, 0xfe, 0x0f, 0xff, 0x81, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x0f, 0xff, 0x83, 0xff, 0xf0, 0x3f, 0xfe, 0x0f, 0xff, 0x80, 0xff, 0xfc, 0x7f, 0xfe, 0x03, 0xff, 0xff, 0xff, 0xf8, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xff, 0x00, 0x3f, 0xff, 0xff, 0xf8, 0x00, 0x7f, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xf8, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 8
  0x00, 0x03, 0xff, 0x80, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x07, 0xff, 0xff, 0xc0, 0x00, 0x7f, 0xff, 0xff, 0x80, 0x03, 0xff, 0xff, 0xff, 0x00, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x7f, 0xff, 0xff, 0xfc, 0x03, 0xff, 0xff, 0xff, 0xf0, 0x0f, 0xff, 0xc7, 0xff, 0xe0, 0x3f, 0xff, 0x0f, 0xff, 0x81, 0xff, 0xf8, 0x3f, 0xfe, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xfc, 0x7f, 0xff, 0x03, 0xff, 0xff, 0xff, 0xfc, 0x0f, 0xff, 0xff, 0xff, 0xf0, 0x3f, 0xff, 0xff, 0xff, 0xc0, 0x7f, 0xff, 0xff, 0xff, 0x00, 0xff, 0xfe, 0xff, 0xfc, 0x01, 0xff, 0xf3, 0xff, 0xf0, 0x03, 0xff, 0x8f, 0xff, 0xc0, 0x01, 0xf8, 0x3f, 0xff, 0x00, 0x00, 0x00, 0xff, 0xfc, 0x00, 0x00, 0x03, 0xff, 0xf0, 0x00, 0x00, 0x0f, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x1f, 0xff, 0x83, 0xff, 0xf0, 0x7f, 0xfe, 0x0f, 0xff, 0xc1, 0xff, 0xf8, 0x3f, 0xff, 0x07, 0xff, 0xe0, 0xff, 0xfc, 0x0f, 0xff, 0x83, 0xff, 0xe0, 0x3f, 0xfe, 0x0f, 0xff, 0x80, 0xff, 0xfc, 0x7f, 0xfe, 0x01, 0xff, 0xff, 0xff, 0xf0, 0x07, 0xff, 0xff, 0xff, 0xc0, 0x0f, 0xff, 0xff, 0xfe, 0x00, 0x3f, 0xff, 0xff, 0xf0, 0x00, 0x3f, 0xff, 0xff, 0x80, 0x00, 0x7f, 0xff, 0xfc, 0x00, 0x00, 0x7f, 0xff, 0xc0, 0x00, 0x00, 0x3f, 0xf0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 9
  0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x7f, 0xf0, 0x00, 0x00, 0x01, 0xff, 0xc0, 0x00, 0x00, 0x07, 0xff, 0x00, 0x00, 0x00, 0x1f, 0xfc, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,  // 1
};

#define IS_UTF8(str, i) ((str[i] & 0xf0) == 0xE0 && (str[i + 1] & 0xC0) == 0x80 && (str[i + 2] & 0xC0) == 0x80)
#define UTF8_TO_UCS2(str, i) (((str[i] & 0x0F) << 12) | ((str[i + 1] & 0x3F) << 6) | (str[i + 2] & 0x3F))
#define IS_GB2312(str, i) ((uint8_t)str[i] >= 0xA1 && (uint8_t)str[i] <= 0xFE && (uint8_t)str[i + 1] >= 0xA1 && (uint8_t)str[i + 1] <= 0xFE)
#define GB2312_TO_INDEX(str, i) (((uint16_t)((uint8_t)str[i] - 0xA1)) * 94 + ((uint16_t)((uint8_t)str[i + 1] - 0xA1)))

#ifdef EMU_WIN32
void RevertBits(const uint8_t* data, size_t len);
#endif

uint16_t GB2312ToIndex(uint16_t ch)
{
#if (0x1234 >> 8) == 0x12
  return ((ch >> 8) - 0xA1) + ((ch & 0xff) - 0xA1) * 94;
#elif (0x1234 >> 8) == 0x34
  return ((ch >> 8) - 0xA1) * 94 + (ch & 0xff) - 0xA1;
#else
# error something must be wrong
#endif 
}

namespace Artint_HZK
{
  BitmapFont_HZK16 hzk16;
  BitmapFont_ASC16 asc16;
  BitmapFont_NUM32 num32;

  int8_t BitmapFont_ASC16::Query(const char* pText, size_t len, BITMAPFONT* pFont)
  {
    pFont->data = ASCII16Bitmaps + (uint16_t)(*(uint8_t*)pText) * (16 * 8 / 8);
    pFont->width = 8;
    pFont->height = 16;
    return 1;
  }

  int8_t BitmapFont_HZK16::Query(const char* pText, size_t len, BITMAPFONT* pFont)
  {
    if (encoding == TextEncoding::UTF8)
    {
      if (len >= 3 && IS_UTF8(pText, 0))
      {
        uint16_t ucs2 = UTF8_TO_UCS2(pText, 0);
        uint16_t gbk = Encoding::UCS2GBK(ucs2);
        const uint32_t stride = (16 * 16 / 8);
        uint32_t offset = GB2312ToIndex(gbk) * stride;
        if (offset < hzk16Size)
        {
          pFont->data = hzk16Bitmap + offset;
          pFont->width = 16;
          pFont->height = 16;
        }
        return 3;
      }
    }
    else if (encoding == TextEncoding::GB2312)
    {
      if (len >= 2 && IS_GB2312(pText, 0))
      {
        uint32_t index = GB2312_TO_INDEX(pText, 0);
        const uint32_t stride = (16 * 16 / 8);
        uint32_t offset = index * stride;
        if (offset < hzk16Size)
        {
          pFont->data = hzk16Bitmap + offset;
          pFont->width = 16;
          pFont->height = 16;
          return 2;
        }
      }
    }
    return asc16.Query(pText, len, pFont);
  }

  int8_t BitmapFont_NUM32::Query(const char* pText, size_t len, BITMAPFONT* pFont)
  {
    const int w = 38;
    const int h = 60;
    //RevertBits(aASCIIBitmap32, sizeof(aASCIIBitmap32));
    if (*pText >= '0' && *pText <= '9' + 1)
    {
      pFont->data = aASCIIBitmap32 + (*pText - '0') * ((w * h + 7) / 8);
      pFont->width = w;
      pFont->height = h;
      return 1;
    }
    return 0;
  }
}
