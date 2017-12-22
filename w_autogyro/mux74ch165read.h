// #include "mux74ch165read.h"
#ifndef MY_MUX74CH165READ_H
#define MY_MUX74CH165READ_H

#include <Arduino.h>
// SRC: https://playground.arduino.cc/Code/ShiftRegSN74HC165N
// SRC for mega128: https://github.com/MCUdude/MegaCore

// You will need to change the "int" to "long" If the
// NUMBER_OF_SHIFT_CHIPS is higher than 2.

#define MUX_IN_BYTES_VAL_T uint32_t


class MUX74CH165Reader {
public:
	MUX74CH165Reader();
	void Init();
	int Read(MUX_IN_BYTES_VAL_T &data);
private:	
	int mux_in_ploadPin_;
	int mux_in_clockEnablePin_;
	int mux_in_dataPin_;
	int mux_in_clockPin_;
	MUX_IN_BYTES_VAL_T pinValues_;
	MUX_IN_BYTES_VAL_T oldPinValues_;
};

extern MUX74CH165Reader* g_mux_in_p;
#endif
