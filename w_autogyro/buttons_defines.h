// #include "defines_buttons.h"

#ifndef MY_BUTTONS_DEFENITIONS_H
#define MY_BUTTONS_DEFENITIONS_H

#define BUTTON_PRESSED_PIN_STATE true
#define BUTTON_PRESSED true
#define BUTTONS_COUNT 11

enum BUTTON_NAME {
  BUTTON_LEFT_FIRST_UP,
  BUTTON_LEFT_FIRST_DOWN, 
  BUTTON_RIGHT_FIRST_UP,
  BUTTON_RIGHT_FIRST_DOWN,
  BUTTON_LEFT_LAST_UP,
  BUTTON_LEFT_LAST_DOWN,
  BUTTON_RIGHT_LAST_UP,
  BUTTON_RIGHT_LAST_DOWN,
  BUTTON_MENU_BACK,
  BUTTON_MENU_OK,
  BUTTON_MENU_SCROLL
};

#define BUTTON_SHIFT_LEFT_FIRST_UP 0
#define BUTTON_SHIFT_LEFT_FIRST_DOWN 1 
#define BUTTON_SHIFT_RIGHT_FIRST_UP 2
#define BUTTON_SHIFT_RIGHT_FIRST_DOWN 3
#define BUTTON_SHIFT_LEFT_LAST_UP 4
#define BUTTON_SHIFT_LEFT_LAST_DOWN 5
#define BUTTON_SHIFT_RIGHT_LAST_UP 6
#define BUTTON_SHIFT_RIGHT_LAST_DOWN 7
#define BUTTON_SHIFT_MENU_SCROLL 9
#define BUTTON_SHIFT_MENU_BACK 10
#define BUTTON_SHIFT_MENU_OK 11

struct ButtonState {
  bool state;
  bool last_state;
  bool was_pressed;
  unsigned char  shift_position;
  BUTTON_NAME button_name;
};

#endif
