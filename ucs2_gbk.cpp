#if defined(ESP8266) || defined(ESP32)
#include <pgmspace.h>
#else
#include <avr/pgmspace.h>
#endif

#include "ucs2_gbk.h"

#ifndef pgm_read_word
#define pgm_read_word(addr) (*(const unsigned short *)(addr))
#endif

#if !defined(__INT_MAX__) || (__INT_MAX__ > 0xFFFF)
#define pgm_read_pointer(addr) ((void *)pgm_read_dword(addr))
#else
#define pgm_read_pointer(addr) ((void *)pgm_read_word(addr))
#endif



namespace Encoding
{
  const uint8_t UCS2Table[] PROGMEM = {
#   include "ucs2_gbk_table.h"
  };

  struct UCS2LINE
  {
    int16_t offset;
    uint8_t begin;
    uint8_t end;
  };

  // UCS2 line offset
  const UCS2LINE UCSLine[] PROGMEM = {
    {0, 164, 252}, {89, 1, 220}, {309, 81, 201}, {430, 145, 201}, {487, 1, 81}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {568, 20, 59}, {608, 3, 147}, {753, 8, 165}, {911, 18, 18}, {912, 96, 155}, {972, 0, 207}, {1180, 5, 66}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {1242, 0, 246}, {1489, 5, 41}, {1526, 32, 41}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {1536, 0, 255}, {1792, 1, 254},
    {2046, 12, 251}, {2286, 6, 255}, {2536, 0, 255}, {2792, 0, 253}, {3046, 1, 255}, {3301, 1, 254}, {3555, 0, 255}, {3811, 3, 253},
    {4062, 0, 249}, {4312, 2, 255}, {4566, 1, 241}, {4807, 9, 255}, {5054, 1, 251}, {5305, 2, 254}, {5558, 1, 255}, {5813, 0, 255},
    {6069, 0, 250}, {6320, 0, 255}, {6576, 6, 255}, {6826, 1, 255}, {7081, 0, 230}, {7312, 0, 250}, {7563, 0, 255}, {7819, 0, 255},
    {8075, 0, 252}, {8328, 1, 255}, {8583, 10, 172}, {8746, 32, 253}, {8968, 5, 254}, {9218, 1, 252}, {9470, 5, 249}, {9715, 2, 239},
    {9953, 17, 253}, {10190, 9, 249}, {10431, 6, 252}, {10678, 1, 242}, {10920, 3, 255}, {11173, 4, 255}, {11425, 0, 254}, {11680, 1, 255},
    {11935, 0, 250}, {12186, 1, 253}, {12439, 0, 255}, {12695, 3, 254}, {12947, 7, 251}, {13192, 10, 174}, {13357, 59, 255}, {13554, 0, 252},
    {13807, 0, 253}, {14061, 2, 254}, {14314, 0, 251}, {14566, 1, 253}, {14819, 1, 255}, {15074, 12, 255}, {15318, 5, 254}, {15568, 0, 254},
    {15823, 3, 254}, {16075, 2, 243}, {16317, 0, 147}, {16465, 7, 255}, {16714, 0, 152}, {16867, 29, 253}, {17092, 5, 206}, {17294, 102, 253},
    {17446, 0, 254}, {17701, 2, 220}, {17920, 116, 200}, {18005, 62, 214}, {18158, 62, 255}, {18352, 0, 254}, {18607, 0, 254}, {18862, 0, 246},
    {19109, 117, 232}, {19225, 13, 168}, {19381, 108, 251}, {19525, 3, 84}, {19607, 124, 226}, {-1, 0, 0}, {19710, 31, 254}, {19934, 11, 160},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {20084, 0, 255}, {20340, 0, 255}, {20596, 0, 51}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {20648, 102, 255},
    {20802, 0, 20}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0},
    {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {-1, 0, 0}, {20823, 49, 68}, {20843, 1, 229},
  };

  uint16_t UCS2GBK(uint16_t ch)
  {
    uint16_t line = ch >> 8;
    uint16_t index = ch & 0xff;
    const UCS2LINE* pLine = (const UCS2LINE*)/*pgm_read_pointer*/(UCSLine + line);
    if(pLine->offset == -1 || index < pLine->begin || index > pLine->end)
    {
      return 0;
    }
    return pgm_read_word(UCS2Table + ((pLine->offset + index - pLine->begin) << 1));
  }
}
