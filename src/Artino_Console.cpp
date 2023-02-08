#ifdef _WIN32
#include <stdint.h>
#else
#endif
#include <Arduino.h>
#include "Artino_Console.h"

// void LCD_Write(int x, int y, const char* text, size_t len);
namespace Artino
{

    void Console::SetTextColor(uint16_t crText, uint16_t crBk)
    {
        m_crText = crText;
        m_crTextBk = crBk;
    }

    void Console::println(const char *text)
    {
        Outputln(text);
    }

    int Console::printf(const char *format, ...)
    {
        int len;
        va_list arg;
        va_start(arg, format);
        len = printfv(format, arg);
        va_end(arg);
        return len;
    }

    int Console::printfv(const char *format, va_list arg)
    {
        static char loc_buf[64];
        char *temp = loc_buf;
        uint32_t len;
        va_list copy;
        va_copy(copy, arg);
        len = vsnprintf(NULL, 0, format, copy);
        va_end(copy);
        if (len >= sizeof(loc_buf))
        {
            temp = (char *)malloc(len + 1);
            if (temp == NULL)
            {
                return 0;
            }
        }

        vsnprintf(temp, len + 1, format, arg);
        Outputln(temp);

        if (len >= sizeof(loc_buf))
        {
            free(temp);
        }
        return len;
    }

}