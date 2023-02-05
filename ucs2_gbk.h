#ifndef UCS2_TO_GBK_CONV_H
#define UCS2_TO_GBK_CONV_H

#ifdef _WIN32
#else
# include "Arduino.h"
#endif

// UCS2到GBK编码转换库
namespace Encoding
{
  uint16_t UCS2GBK(uint16_t ch);
}

#endif // UCS2_TO_GBK_CONV_H