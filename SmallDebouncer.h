#ifndef SMALL_DEBOUNCER_H
#define SMALL_DEBOUNCER_H

class SmallDebouncer {
public:
	bool wasPressed(uint8_t pin, unsigned long millis);
	bool wasPressed(uint8_t pin);

private:
	struct {
		unsigned int current: 1;
		unsigned int timeStates: 4;
	} m_bits;
};

#endif
