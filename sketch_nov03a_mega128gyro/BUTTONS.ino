#define BUTTON_PRESSED_PIN_STATE false
#define BUTTON_PRESSED true
#define BUTTONS_COUNT 10

#define BUTTON_SHIFT_LEFT_FIRST_UP 0
#define BUTTON_SHIFT_LEFT_FIRST_DOWN 1 
#define BUTTON_SHIFT_RIGHT_FIRST_UP 2
#define BUTTON_SHIFT_RIGHT_FIRST_DOWN 3
#define BUTTON_SHIFT_LEFT_LAST_UP 4
#define BUTTON_SHIFT_LEFT_LAST_DOWN 5
#define BUTTON_SHIFT_RIGHT_LAST_UP 6
#define BUTTON_SHIFT_RIGHT_LAST_DOWN 7
#define BUTTON_SHIFT_MENU_SELECT 8
#define BUTTON_SHIFT_MENU_OK 9

uint8_t buttons_shifts[BUTTONS_COUNT] = {
  BUTTON_SHIFT_LEFT_FIRST_UP,
  BUTTON_SHIFT_LEFT_FIRST_DOWN, 
  BUTTON_SHIFT_RIGHT_FIRST_UP,
  BUTTON_SHIFT_RIGHT_FIRST_DOWN,
  BUTTON_SHIFT_LEFT_LAST_UP,
  BUTTON_SHIFT_LEFT_FIRST_DOWN,
  BUTTON_SHIFT_RIGHT_LAST_UP,
  BUTTON_SHIFT_RIGHT_LAST_DOWN,
  BUTTON_SHIFT_MENU_SELECT,
  BUTTON_SHIFT_MENU_OK
};

//=============================================================================================
//=============================================================================================
//=============================================================================================

struct ButtonState {
  bool state;
  bool last_state;
  bool was_pressed;
  unsigned char  shift_position;
};

//=============================================================================================
//=============================================================================================
//=============================================================================================

ButtonState buttons[BUTTONS_COUNT];

//=============================================================================================
//=============================================================================================
//=============================================================================================

void buttons_init(){
  for (unsigned char i = 0; i < BUTTONS_COUNT; i++){
    buttons[i].state = !BUTTON_PRESSED;
    buttons[i].last_state = !BUTTON_PRESSED;
    buttons[i].was_pressed = false;
    buttons[i].shift_position = buttons_shifts[i];
  }
}

//=============================================================================================
//=============================================================================================
//=============================================================================================

void buttons_update(){
  uint32_t data;
  mux_in_read(data);
  uint16_t curdata = data;

  for (unsigned char i = 0; i < BUTTONS_COUNT; i++){
    // check pressed buttons
    if(((bool)(curdata & (1 << buttons[i].shift_position))) == BUTTON_PRESSED_PIN_STATE){
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

inline char buttons_get_count(){
  return BUTTONS_COUNT;
}

