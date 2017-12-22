#include "mux74ch165read.h"
#include <Arduino>
//==============================================================================================
static MUX74CH165Reader g_mux_in;
MUX74CH165Reader* g_mux_in_p = g_mux_in;
//==============================================================================================
#define MUX_IN_LATCH_PL  3      // PE3 // Connects to Parallel load pin the 165
#define MUX_IN_CE       5       // PE5 // Connects to Clock Enable pin the 165
#define MUX_IN_CLK_CP   2        // PE2 // Connects to the Clock pin the 165
#define MUX_IN_DATA_Q7  4       // PE4 // Connects to the Q7 pin the 165

#define MUX_IN_NUMBER_OF_SHIFT_CHIPS   2
#define MUX_IN_DATA_WIDTH   MUX_IN_NUMBER_OF_SHIFT_CHIPS * 8

#define MUX_IN_PULSE_WIDTH_USEC   5
#define MUX_IN_POLL_DELAY_MSEC   1
//==============================================================================================
MUX74CH165Reader::MUX74CH165Reader(){
	
}
//==============================================================================================
int MUX74CH165Reader::Init(){
  // Initialize our digital pins...
  mux_in_ploadPin_        = MUX_IN_LATCH_PL;  
  mux_in_clockEnablePin_  = MUX_IN_CE;  
  mux_in_dataPin_         = MUX_IN_DATA_Q7;
  mux_in_clockPin_        = MUX_IN_CLK_CP;

  pinMode(mux_in_ploadPin_, OUTPUT);
  pinMode(mux_in_clockEnablePin_, OUTPUT);
  pinMode(mux_in_clockPin_, OUTPUT);
  pinMode(mux_in_dataPin_, INPUT);

  digitalWrite(mux_in_clockPin_, LOW);
  digitalWrite(mux_in_ploadPin_, HIGH);
  
  return 0;
}
//==============================================================================================
// This function is essentially a "shift-in" routine reading the
// serial Data from the shift register chips and representing
// the state of those pins in an unsigned integer (or long).

int MUX74CH165Reader::Read(MUX_IN_BYTES_VAL_T &data){
  long bitVal;
  MUX_IN_BYTES_VAL_T bytesVal = 0;

  // Trigger a parallel Load to latch the state of the data lines,

  digitalWrite(mux_in_clockEnablePin_, HIGH);
  digitalWrite(mux_in_ploadPin_, LOW);
  delayMicroseconds(MUX_IN_PULSE_WIDTH_USEC);
  digitalWrite(mux_in_ploadPin_, HIGH);
  digitalWrite(mux_in_clockEnablePin_, LOW);

  // Loop to read each bit value from the serial out line
  // of the SN74HC165N.
 
  for(int i = 0; i < MUX_IN_DATA_WIDTH; i++)
  {
      bitVal = digitalRead(mux_in_dataPin_);

      // Set the corresponding bit in bytesVal.
      
      bytesVal |= (bitVal << ((MUX_IN_DATA_WIDTH-1) - i));

      // Pulse the Clock (rising edge shifts the next bit).
      
      digitalWrite(mux_in_clockPin_, HIGH);
      delayMicroseconds(MUX_IN_PULSE_WIDTH_USEC);
      digitalWrite(mux_in_clockPin_, LOW);
  }

  data = bytesVal;
  return 0;
}
//==============================================================================================

