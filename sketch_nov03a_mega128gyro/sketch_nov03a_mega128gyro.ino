#include "lcd_manager.h"
#include "common_makros.h"
#include "menu.h"

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

LCD_MANAGER g_lcd_manager;
MyMenu g_menu;

void setup() {
  Serial.begin(38400);
  g_lcd_manager.init();
  g_menu.init();

  mux_in_setup();
  mux_out_setup();
  buttons_init();


  DDRB |= (1 << 5);

  int r = 
  gyro_kalman_setup();
  
  if (r){
    g_lcd_manager.set_error_text("Gyro init error");
  }else{
    g_lcd_manager.set_menu_name(g_menu.get_current_name());
  }

  

  delay(1000);

  g_lcd_manager.refresh();

}

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

void loop() {
  static double tt = 0;
  INVBIT(PORTB, 5);

  double Xx, Yy;
  gyro_kalman_get_position(Xx, Yy);  

  g_lcd_manager.set_x_y(Xx, Yy);

  Serial.println(buttons_update());


  for (unsigned int i = 0; i < buttons_get_count(); i++){
    if (buttons_was_button_pressed(i)){

      switch (buttons_get_pressed_button_name(i)){
        case BUTTON_MENU_OK:
          g_lcd_manager.set_menu_name(g_menu.go_child());
        break;
        case BUTTON_MENU_SELECT:
          g_lcd_manager.set_menu_name(g_menu.go_parent());
        break;
        case BUTTON_LEFT_FIRST_UP:
          g_lcd_manager.set_menu_name(g_menu.go_back());
        break;
        case BUTTON_LEFT_FIRST_DOWN:
          g_lcd_manager.set_menu_name(g_menu.go_next());
        break;
        default:

        break;        
      }


      
      Serial.println(i);
    }
  }


  

  g_lcd_manager.set_left_first_weel_val (tt++);
  g_lcd_manager.set_left_last_weel_val (tt++ + 10);
  g_lcd_manager.set_right_first_weel_val (tt + 20);
  g_lcd_manager.set_right_last_weel_val (tt + 30);
  
  g_lcd_manager.refresh();


  if (tt > 950) tt = 0;
  
  delay(200);
}

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================

