// SRC: http://arduino.ru/Tutorial/registr_74HC595
// SRC: http://arduino.ru/Reference/ShiftOut
// SRC for mega128: https://github.com/MCUdude/MegaCore

#define MUX_OUT_LATCH_PL  24  // STCP // PD6     
#define MUX_OUT_CLK_CP   23    // SHCP  // PD5    
#define MUX_OUT_DATA    25       // DS // PD7      

#define MUX_OUT_NUMBER_OF_SHIFT_CHIPS   2
#define MUX_OUT_DATA_WIDTH   MUX_OUT_NUMBER_OF_SHIFT_CHIPS * 8

#define MUX_OUT_BYTES_VAL_T uint16_t

int mux_out_latchPin        = MUX_OUT_LATCH_PL;  
int mux_out_dataPin         = MUX_OUT_DATA; 
int mux_out_clockPin        = MUX_OUT_CLK_CP; 

MUX_OUT_BYTES_VAL_T mux_out_oldPinValues;

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

int mux_out_setup(){
  // Initialize our digital pins...

  pinMode(mux_out_latchPin, OUTPUT);
  pinMode(mux_out_dataPin, OUTPUT);
  pinMode(mux_out_clockPin, OUTPUT);

  digitalWrite(mux_out_clockPin, LOW);
  digitalWrite(mux_out_latchPin, HIGH);
  
  return 0;
}

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

int mux_out_write_val(MUX_OUT_BYTES_VAL_T data){

  mux_out_oldPinValues = data;

  digitalWrite(mux_out_latchPin, LOW);

  shiftOut(mux_out_dataPin, mux_out_clockPin, MSBFIRST, (data >> 8)); 
  shiftOut(mux_out_dataPin, mux_out_clockPin, MSBFIRST, data);

  digitalWrite(mux_out_latchPin, HIGH);

  return 0;
}

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

int mux_out_write_one_pos_val(uint8_t pos, uint8_t pin_state){

  if (pin_state == HIGH){
    UPBIT(mux_out_oldPinValues, pos);
  }else{ // it's LOW
    DOWNBIT(mux_out_oldPinValues, pos);
  }

  digitalWrite(mux_out_latchPin, LOW);

  shiftOut(mux_out_dataPin, mux_out_clockPin, MSBFIRST, (mux_out_oldPinValues >> 8)); 
  shiftOut(mux_out_dataPin, mux_out_clockPin, MSBFIRST, mux_out_oldPinValues);

  digitalWrite(mux_out_latchPin, HIGH);

  return 0;
}

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================


