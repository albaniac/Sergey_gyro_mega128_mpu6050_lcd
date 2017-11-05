// SRC: https://playground.arduino.cc/Code/ShiftRegSN74HC165N
// SRC for mega128: https://github.com/MCUdude/MegaCore

#define MUX_LATCH_PL  3      // PE3 
#define MUX_CE       5       // PE5
#define MUX_CLK_CP   2        // PE2
#define MUX_DATA_Q7  4       // PE4

#define MUX_NUMBER_OF_SHIFT_CHIPS   2
#define MUX_DATA_WIDTH   MUX_NUMBER_OF_SHIFT_CHIPS * 8

#define MUX_PULSE_WIDTH_USEC   5
#define MUX_POLL_DELAY_MSEC   1

// You will need to change the "int" to "long" If the
// NUMBER_OF_SHIFT_CHIPS is higher than 2.

#define MUX_BYTES_VAL_T uint32_t

int ploadPin        = MUX_LATCH_PL;  // Connects to Parallel load pin the 165
int clockEnablePin  = MUX_CE;  // Connects to Clock Enable pin the 165
int dataPin         = MUX_DATA_Q7; // Connects to the Q7 pin the 165
int clockPin        = MUX_CLK_CP; // Connects to the Clock pin the 165

MUX_BYTES_VAL_T pinValues;
MUX_BYTES_VAL_T oldPinValues;

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
int mux_setup(){
  // Initialize our digital pins...

  pinMode(ploadPin, OUTPUT);
  pinMode(clockEnablePin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(dataPin, INPUT);

  digitalWrite(clockPin, LOW);
  digitalWrite(ploadPin, HIGH);
  
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

int mux_read(MUX_BYTES_VAL_T &data){
  long bitVal;
  MUX_BYTES_VAL_T bytesVal = 0;

  // Trigger a parallel Load to latch the state of the data lines,

  digitalWrite(clockEnablePin, HIGH);
  digitalWrite(ploadPin, LOW);
  delayMicroseconds(MUX_PULSE_WIDTH_USEC);
  digitalWrite(ploadPin, HIGH);
  digitalWrite(clockEnablePin, LOW);

  // Loop to read each bit value from the serial out line
  // of the SN74HC165N.
 
  for(int i = 0; i < MUX_DATA_WIDTH; i++)
  {
      bitVal = digitalRead(dataPin);

      // Set the corresponding bit in bytesVal.
      
      bytesVal |= (bitVal << ((MUX_DATA_WIDTH-1) - i));

      // Pulse the Clock (rising edge shifts the next bit).
      
      digitalWrite(clockPin, HIGH);
      delayMicroseconds(MUX_PULSE_WIDTH_USEC);
      digitalWrite(clockPin, LOW);
  }

  data = bytesVal;
  return 0;
}
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

