#ifndef _U74HCT165_H_
#define _U74HCT165_H_

class U74HC165
{
	int8_t m_dataPin;
	int8_t m_clockPin;
	int8_t m_selectPin;
	int8_t m_plPin;

public:
	U74HC165(int8_t clockPin, int8_t dataPin, int8_t selectPin, int8_t plPin)
		: m_clockPin(clockPin), m_dataPin(dataPin), m_selectPin(selectPin), m_plPin(plPin)
	{
	}
#ifdef ARDUINO_ARCH_RP2040
	uint8_t shiftIn(uint8_t dataPin, uint8_t clockPin, uint8_t bitOrder)
	{
		uint8_t value = 0;
		for (uint8_t i = 0; i < 8; ++i) {
			digitalWrite(clockPin, LOW);     // 拉低时钟完成脉冲
			delayMicroseconds(1);  // 根据74LV165时序表调整
			if (bitOrder == LSBFIRST) {
				value |= (!!digitalRead(dataPin)) << i; // 低位在前，依次填充到对应位置
			} else {
				value = (value << 1) | (!!digitalRead(dataPin)); // 高位在前，左移后合并新位
			}
			digitalWrite(clockPin, HIGH);    // 触发时钟上升沿
			delayMicroseconds(1);  // 根据74LV165时序表调整
		}
		return value;
	}
#endif	

	void Begin()
	{
		if (m_clockPin >= 0)
		{
			pinMode(m_clockPin, OUTPUT);
		}
		if (m_dataPin >= 0)
		{
			pinMode(m_dataPin, INPUT);
		}
		if (m_selectPin >= 0)
		{
			pinMode(m_selectPin, OUTPUT);
		}
		pinMode(m_plPin, OUTPUT);
	}

	uint8_t ReadByte()
	{
		digitalWrite(m_plPin, LOW);
		digitalWrite(m_plPin, HIGH);

		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, LOW);
		}
		uint8_t c = shiftIn(m_dataPin, m_clockPin, LSBFIRST);
		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, HIGH);
		}
		return c;
	}

	uint16_t ReadWord()
	{
		digitalWrite(m_plPin, LOW);
		digitalWrite(m_plPin, HIGH);

		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, LOW);
		}

		uint16_t H = (uint16_t)shiftIn(m_dataPin, m_clockPin, LSBFIRST);
		uint16_t L = (uint16_t)shiftIn(m_dataPin, m_clockPin, LSBFIRST);

		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, HIGH);
		}
		return ((H << 8) | L);
	}

	void ReadBytes(uint8_t* pOut, int16_t nBytesCount, bool bFlip = false)
	{
		digitalWrite(m_plPin, LOW);
#ifdef ARDUINO_ARCH_RP2040
		delayMicroseconds(5);  // 确保LOAD信号有效
#endif		
		digitalWrite(m_plPin, HIGH);

		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, LOW);
		}

		if(bFlip)
		{
			for(int16_t i = nBytesCount - 1; i >= 0; i--)
			{
				pOut[i] = (uint16_t)shiftIn(m_dataPin, m_clockPin, LSBFIRST);
			}
		}
		else
		{
			for(int16_t i = 0; i < nBytesCount; i++)
			{
				pOut[i] = (uint16_t)shiftIn(m_dataPin, m_clockPin, LSBFIRST);
			}
		}

		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, HIGH);
		}
	}
	
	void ReadWords(uint16_t* pOut, int16_t nWordsCount)
	{
		uint8_t *pOut8 = reinterpret_cast<uint8_t*>(pOut);
		ReadBytes(pOut8, nWordsCount * 2);
	}
};

#endif // _U74HCT4094_H_
