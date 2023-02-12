#ifndef _U74HCT4094_H_
#define _U74HCT4094_H_

namespace Artino
{
  class U74HCT4094
  {
    uint8_t m_dataPin;
    uint8_t m_clockPin;
    uint8_t m_strobePin;

  public:
    U74HCT4094(uint8_t clockPin, uint8_t dataPin, uint8_t strobePin)
      : m_clockPin(clockPin)
      , m_dataPin(dataPin)
      , m_strobePin(strobePin)
    {
    }

    void Begin()
    {
      pinMode(m_clockPin, OUTPUT);
      pinMode(m_dataPin, OUTPUT);
      pinMode(m_strobePin, OUTPUT);
    }

    void WriteByte(uint8_t c)
    {
      digitalWrite(m_dataPin, LOW);
      digitalWrite(m_strobePin, LOW);
      digitalWrite(m_clockPin, LOW);

      shiftOut(m_dataPin, m_clockPin, MSBFIRST, c);

      digitalWrite(m_strobePin, HIGH);
      digitalWrite(m_strobePin, LOW);
    }

    void WriteWord(uint16_t c) // 从最低位开始
    {
      WriteByte((c >> 8) & 0xff);
      WriteByte(c & 0xff);
    }
  };
}

#endif // _U74HCT4094_H_
