#include "pressurer.h"
#include "mux74ch595dwrite.h"
//=======================================================================================
#define LIFT_UP_PIN_STATE_ON HIGH
#define LIFT_UP_PIN_STATE_OFF LOW
#define LIFT_DOWN_PIN_STATE_ON HIGH
#define LIFT_DOWN_PIN_STATE_OFF LOW
//=======================================================================================
Pressurer::Pressurer(){
  pin_up_number_ = -1;
  pin_down_number_ = -1;
}
//=======================================================================================
void Pressurer::Up(){
	if (pin_up_number_ < 0) return;
	g_mux_out_p->WriteOnePosVal(pin_up_number_, LIFT_UP_PIN_STATE_ON);
}
//=======================================================================================
void Pressurer::Down(){
  if (pin_down_number_ < 0) return;
  g_mux_out_p->WriteOnePosVal(pin_down_number_, LIFT_DOWN_PIN_STATE_ON);
}
//=======================================================================================
void Pressurer::Stop(){
  if (pin_up_number_ < 0 || pin_down_number_ < 0) return;
  g_mux_out_p->WriteOnePosVal(pin_up_number_, LIFT_UP_PIN_STATE_OFF);
  g_mux_out_p->WriteOnePosVal(pin_down_number_, LIFT_DOWN_PIN_STATE_OFF);
}
//=======================================================================================

