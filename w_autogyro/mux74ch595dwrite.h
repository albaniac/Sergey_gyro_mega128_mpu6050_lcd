// #include "mux74ch595dwrite.h"
#ifndef MY_MUX74CH595DWRITE_H
#define MY_MUX74CH595DWRITE_H

#define MUX_OUT_BYTES_VAL_T uint16_t

class MUX74CH595DWriter {
public:
	MUX74CH595DWriter();
	void Init();
	int WriteVal(MUX_OUT_BYTES_VAL_T data);
	int WriteOnePosVal(uint8_t pos, uint8_t pin_state);
	
private:	
	int mux_out_latchPin_;  
	int mux_out_dataPin_; 
	int mux_out_clockPin_; 

	MUX_OUT_BYTES_VAL_T mux_out_oldPinValues_;
}

extern MUX74CH595DWriter* g_mux_out_p;
#endif
