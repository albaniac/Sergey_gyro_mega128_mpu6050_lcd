#include "lcd_manager.h"
#include "common_makros.h"
#include "menu.h"
#include "timer.h"

//==============================================================================================
//==============================================================================================
//==============================================================================================

LCD_MANAGER g_lcd_manager;
MyMenu g_menu;

//==============================================================================================
//==============================================================================================
//==============================================================================================

void led_blink(){
  INVBIT(PORTB, 5);
}

void send_message(){
  Serial.println("message from task");
}
void send_message2(){
  Serial.println("message2 from2 task2");
}

void update_hyroscope(){
  double Xx, Yy;
  gyro_kalman_get_position(Xx, Yy); 
//  g_lcd_manager.set_x_y(Xx, Yy);  
}

void update_buttons(){
  
  buttons_update();
  
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
    }
  }
}

void print_to_lcd(){
  
  static double tt = 0;
  
  double Xx, Yy;
  gyro_kalman_get_position(Xx, Yy); 
  g_lcd_manager.set_x_y(Xx, Yy);  
  
  g_lcd_manager.set_left_first_weel_val (tt++);
  g_lcd_manager.set_left_last_weel_val (tt++ + 10);
  g_lcd_manager.set_right_first_weel_val (tt + 20);
  g_lcd_manager.set_right_last_weel_val (tt + 30);
  
  g_lcd_manager.refresh();

  if (tt > 950) tt = 0;
}

//==============================================================================================

void setup() {
  Serial.begin(115200);

  DDRB |= (1 << 5);

  int r = gyro_kalman_setup();

  g_lcd_manager.init();
  g_menu.init();
  g_timer.init();


  g_timer.add_task(led_blink, 1000, true);
//  g_timer.add_task(send_message, 100000, true);
//  g_timer.add_task(send_message2, 10000, true);
  g_timer.add_task(update_buttons, 5000, true);
  g_timer.add_task(print_to_lcd, 3000, true);
  g_timer.add_task(update_hyroscope, 30, true);



  mux_in_setup();
  mux_out_setup();
  buttons_init();
  
  if (r){
    g_lcd_manager.set_error_text((char *)"Gyro init error");
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

  TTask ttask = g_timer.get_task_for_work();
  if (ttask != 0){
    ttask();
  }
  
  //INVBIT(PORTB, 5);

  //update_hyroscope();
  //delay(50);
}

//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================



