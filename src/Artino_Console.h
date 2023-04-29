#ifndef _ARTINO_CONSOLE_H_
#define _ARTINO_CONSOLE_H_

namespace Artino
{
    class Console
    {
    protected:
        int16_t m_x = 0;
        int16_t m_y = 0;
        uint16_t m_crText = 0XFFFF;
        uint16_t m_crTextBk = 0x0000;

    public:
        virtual void Clear() = 0;
        virtual void SetTextColor(uint16_t crText, uint16_t crBk);
        virtual void Outputln(const char *szText) = 0;
        virtual void Scroll(int16_t offsetX, int16_t offsetY) = 0;

        void println(const char *text);
        int printf(const char *format, ...);
        int printfv(const char *format, va_list arg);
    };
}

#endif // _ARTINO_CONSOLE_H_