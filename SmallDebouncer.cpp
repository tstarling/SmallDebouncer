#include <Arduino.h>
#include "SmallDebouncer.h"

bool SmallDebouncer::wasPressed(uint8_t pin)
{
	return wasPressed(pin, millis());
}

bool SmallDebouncer::wasPressed(uint8_t pin, unsigned long t)
{
	t >>= 3;
	t &= 3;
	uint8_t value = digitalRead(pin) == HIGH;
	bitWrite(m_bits.timeStates, t, value);
	if (!m_bits.current && m_bits.timeStates == 15) {
		// Rising edge
		m_bits.current = 1;
	} else if (m_bits.current && m_bits.timeStates == 0) {
		// Falling edge
		m_bits.current = 0;
		return true;
	}
	return false;
}
