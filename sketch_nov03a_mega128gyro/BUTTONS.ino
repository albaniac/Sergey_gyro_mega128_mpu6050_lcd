#include "defines_buttons.h"

ButtonState buttons[BUTTONS_COUNT];

//=============================================================================================
//=============================================================================================
//=============================================================================================

void buttons_init(){
  for (unsigned char i = 0; i < BUTTONS_COUNT; i++){
    buttons[i].state = !BUTTON_PRESSED;
    buttons[i].last_state = !BUTTON_PRESSED;
    buttons[i].was_pressed = false;
  }

  buttons[0].button_name = BUTTON_LEFT_FIRST_UP;
  buttons[0].shift_position = BUTTON_SHIFT_LEFT_FIRST_UP;
  buttons[1].button_name = BUTTON_LEFT_FIRST_DOWN; 
  buttons[1].shift_position = BUTTON_SHIFT_LEFT_FIRST_DOWN; 
  buttons[2].button_name = BUTTON_RIGHT_FIRST_UP;
  buttons[2].shift_position = BUTTON_SHIFT_RIGHT_FIRST_UP;
  buttons[3].button_name = BUTTON_RIGHT_FIRST_DOWN;
  buttons[3].shift_position = BUTTON_SHIFT_RIGHT_FIRST_DOWN;
  buttons[4].button_name = BUTTON_LEFT_LAST_UP;
  buttons[4].shift_position = BUTTON_SHIFT_LEFT_LAST_UP;
  buttons[5].button_name = BUTTON_LEFT_LAST_DOWN;
  buttons[5].shift_position = BUTTON_SHIFT_LEFT_LAST_DOWN;
  buttons[6].button_name = BUTTON_RIGHT_LAST_UP;
  buttons[6].shift_position = BUTTON_SHIFT_RIGHT_LAST_UP;
  buttons[7].button_name = BUTTON_RIGHT_LAST_DOWN;
  buttons[7].shift_position = BUTTON_SHIFT_RIGHT_LAST_DOWN;
  buttons[8].button_name = BUTTON_MENU_BACK;
  buttons[8].shift_position = BUTTON_SHIFT_MENU_BACK;
  buttons[9].button_name = BUTTON_MENU_OK;
  buttons[9].shift_position = BUTTON_SHIFT_MENU_OK;
  buttons[10].button_name = BUTTON_MENU_SCROLL;
  buttons[10].shift_position = BUTTON_SHIFT_MENU_SCROLL;

}

//=============================================================================================
//=============================================================================================
//=============================================================================================

uint16_t buttons_update(){
  uint32_t data;
  mux_in_read(data);
  uint16_t curdata = data;
  curdata = ~curdata; 

  uint16_t point = 1;

  for (unsigned char i = 0; i < BUTTONS_COUNT; i++){
    // check pressed buttons
    if((curdata & (point << buttons[i].shift_position)) > 0){
      // button pressed
      if (buttons[i].last_state == !BUTTON_PRESSED){
        buttons[i].was_pressed = true;
      }
      buttons[i].last_state = buttons[i].state;
      buttons[i].state = BUTTON_PRESSED;
    }else{
      buttons[i].last_state = buttons[i].state;
      buttons[i].state = !BUTTON_PRESSED;
    }
  }
  return curdata;
}

//=============================================================================================
//=============================================================================================
//=============================================================================================

bool buttons_was_button_pressed(int num){
  bool st = false;
  if (buttons[num].was_pressed){
    st = true;
    buttons[num].was_pressed = false;
  }
  return st;
}

//=============================================================================================
//=============================================================================================
//=============================================================================================

inline unsigned char buttons_get_count(){
  return BUTTONS_COUNT;
}

//=============================================================================================
//=============================================================================================
//=============================================================================================

BUTTON_NAME buttons_get_pressed_button_name(int num){
  return buttons[num].button_name;    
}

