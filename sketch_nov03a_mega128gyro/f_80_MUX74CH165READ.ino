// SRC: https://playground.arduino.cc/Code/ShiftRegSN74HC165N
// SRC for mega128: https://github.com/MCUdude/MegaCore

#define MUX_IN_LATCH_PL  3      // PE3 
#define MUX_IN_CE       5       // PE5
#define MUX_IN_CLK_CP   2        // PE2
#define MUX_IN_DATA_Q7  4       // PE4

#define MUX_IN_NUMBER_OF_SHIFT_CHIPS   2
#define MUX_IN_DATA_WIDTH   MUX_IN_NUMBER_OF_SHIFT_CHIPS * 8

#define MUX_IN_PULSE_WIDTH_USEC   5
#define MUX_IN_POLL_DELAY_MSEC   1

// You will need to change the "int" to "long" If the
// NUMBER_OF_SHIFT_CHIPS is higher than 2.

#define MUX_IN_BYTES_VAL_T uint32_t

int mux_in_ploadPin        = MUX_IN_LATCH_PL;  // Connects to Parallel load pin the 165
int mux_in_clockEnablePin  = MUX_IN_CE;  // Connects to Clock Enable pin the 165
int mux_in_dataPin         = MUX_IN_DATA_Q7; // Connects to the Q7 pin the 165
int mux_in_clockPin        = MUX_IN_CLK_CP; // Connects to the Clock pin the 165

MUX_IN_BYTES_VAL_T pinValues;
MUX_IN_BYTES_VAL_T oldPinValues;

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
int mux_in_setup(){
  // Initialize our digital pins...

  pinMode(mux_in_ploadPin, OUTPUT);
  pinMode(mux_in_clockEnablePin, OUTPUT);
  pinMode(mux_in_clockPin, OUTPUT);
  pinMode(mux_in_dataPin, INPUT);

  digitalWrite(mux_in_clockPin, LOW);
  digitalWrite(mux_in_ploadPin, HIGH);
  
  return 0;
}
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
// This function is essentially a "shift-in" routine reading the
// serial Data from the shift register chips and representing
// the state of those pins in an unsigned integer (or long).

int mux_in_read(MUX_IN_BYTES_VAL_T &data){
  long bitVal;
  MUX_IN_BYTES_VAL_T bytesVal = 0;

  // Trigger a parallel Load to latch the state of the data lines,

  digitalWrite(mux_in_clockEnablePin, HIGH);
  digitalWrite(mux_in_ploadPin, LOW);
  delayMicroseconds(MUX_IN_PULSE_WIDTH_USEC);
  digitalWrite(mux_in_ploadPin, HIGH);
  digitalWrite(mux_in_clockEnablePin, LOW);

  // Loop to read each bit value from the serial out line
  // of the SN74HC165N.
 
  for(int i = 0; i < MUX_IN_DATA_WIDTH; i++)
  {
      bitVal = digitalRead(mux_in_dataPin);

      // Set the corresponding bit in bytesVal.
      
      bytesVal |= (bitVal << ((MUX_IN_DATA_WIDTH-1) - i));

      // Pulse the Clock (rising edge shifts the next bit).
      
      digitalWrite(mux_in_clockPin, HIGH);
      delayMicroseconds(MUX_IN_PULSE_WIDTH_USEC);
      digitalWrite(mux_in_clockPin, LOW);
  }

  data = bytesVal;
  return 0;
}
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

