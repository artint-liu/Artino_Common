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

	void ReadBytes(uint8_t* pOut, int16_t nBytesCount)
	{
		digitalWrite(m_plPin, LOW);
		digitalWrite(m_plPin, HIGH);

		if (m_selectPin >= 0)
		{
			digitalWrite(m_selectPin, LOW);
		}

		for(int16_t i = nBytesCount - 1; i >= 0; i--)
		{
			pOut[i] = (uint16_t)shiftIn(m_dataPin, m_clockPin, LSBFIRST);
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
