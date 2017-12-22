#include "mux74ch595dwrite.h"
#include "common_makros.h"
#include <Arduino.h>
//==============================================================================================
static MUX74CH595DWriter g_mux_out;
MUX74CH595DWriter* g_mux_out_p = &g_mux_out;
//==============================================================================================
// SRC: http://arduino.ru/Tutorial/registr_74HC595
// SRC: http://arduino.ru/Reference/ShiftOut
// SRC for mega128: https://github.com/MCUdude/MegaCore

#define MUX_OUT_LATCH_PL  24  // STCP // PD6     
#define MUX_OUT_CLK_CP   23    // SHCP  // PD5    
#define MUX_OUT_DATA    25       // DS // PD7      

#define MUX_OUT_NUMBER_OF_SHIFT_CHIPS   2
#define MUX_OUT_DATA_WIDTH   MUX_OUT_NUMBER_OF_SHIFT_CHIPS * 8
//==============================================================================================
MUX74CH595DWriter::MUX74CH595DWriter(){
	
}
//==============================================================================================
void MUX74CH595DWriter::Init(){
	
	
  // Initialize our digital pins...
  mux_out_latchPin_        = MUX_OUT_LATCH_PL;  
  mux_out_dataPin_         = MUX_OUT_DATA; 
  mux_out_clockPin_        = MUX_OUT_CLK_CP; 

  pinMode(mux_out_latchPin_, OUTPUT);
  pinMode(mux_out_dataPin_, OUTPUT);
  pinMode(mux_out_clockPin_, OUTPUT);

  digitalWrite(mux_out_clockPin_, LOW);
  digitalWrite(mux_out_latchPin_, HIGH);

}
//==============================================================================================
int MUX74CH595DWriter::WriteVal(MUX_OUT_BYTES_VAL_T data){

  mux_out_oldPinValues_ = data;

  digitalWrite(mux_out_latchPin_, LOW);

  shiftOut(mux_out_dataPin_, mux_out_clockPin_, MSBFIRST, (data >> 8)); 
  shiftOut(mux_out_dataPin_, mux_out_clockPin_, MSBFIRST, data);

  digitalWrite(mux_out_latchPin_, HIGH);

  return 0;
}
//==============================================================================================
int MUX74CH595DWriter::WriteOnePosVal(uint8_t pos, uint8_t pin_state){

  if (pin_state == HIGH){
    UPBIT(mux_out_oldPinValues_, pos);
  }else{ // it's LOW
    DOWNBIT(mux_out_oldPinValues_, pos);
  }

  digitalWrite(mux_out_latchPin_, LOW);

  shiftOut(mux_out_dataPin_, mux_out_clockPin_, MSBFIRST, (mux_out_oldPinValues_ >> 8)); 
  shiftOut(mux_out_dataPin_, mux_out_clockPin_, MSBFIRST, mux_out_oldPinValues_);

  digitalWrite(mux_out_latchPin_, HIGH);

  return 0;
}
//==============================================================================================
