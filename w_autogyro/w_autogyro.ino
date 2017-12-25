#include "common_makros.h"

#include "lcd_manager.h"
#include "menu.h"
#include "timer.h"
#include "gyro_kalman.h"
#include "buttons.h"
#include "mux74ch165read.h"
#include "mux74ch595dwrite.h"
#include "data_manager.h"

#include <avr/wdt.h>

//==============================================================================================
//==============================================================================================
//==============================================================================================
const long reset_watch_dog_period = 500;
void reset_watch_dog(){
  wdt_reset();
}
//==============================================================================================
const long led_blink_period = 500;
void led_blink(){
  INVBIT(PORTB, 5);
  g_timer_p->AddTask(led_blink, led_blink_period);
}
//==============================================================================================
const long send_message_period = 1000;
void send_message(){
  Serial.println("message from task");
  g_timer_p->AddTask(send_message, send_message_period);
}
//==============================================================================================
const long send_message2_period = 200;
void send_message2(){
  Serial.println("message2 from2 task2");
  g_timer_p->AddTask(send_message2, send_message2_period);
}
//==============================================================================================
const long update_hyroscope_period = 20;
void update_hyroscope(){
  double Xx, Yy;
  g_gyro_kalman_p->GetPosition(Xx, Yy); 
  g_timer_p->AddTask(update_hyroscope, update_hyroscope_period);
}
//==============================================================================================
const long update_buttons_period = 200;
void update_buttons(){
  
  g_buttons_p->Update();
  
  for (unsigned int i = 0; i < g_buttons_p->GetCount(); i++){
    if (g_buttons_p->WasButtonPressed(i)){
      switch (g_buttons_p->GetPressedButtonName(i)){
        case BUTTON_MENU_OK:
          g_lcd_manager_p->SetMenuName(g_menu_p->GoChild());
        break;
        case BUTTON_MENU_BACK:
          g_lcd_manager_p->SetMenuName(g_menu_p->GoParent());
        break;
        case BUTTON_MENU_SCROLL:
          g_lcd_manager_p->SetMenuName(g_menu_p->GoNext());
        break;
        default:

        break;        
      }
    }
  }

  g_timer_p->AddTask(update_buttons, update_buttons_period);
}
//==============================================================================================
const long print_to_lcd_period = 300;
void print_to_lcd(){
  
  static double tt = 0;
  
  double Xx, Yy;
  g_gyro_kalman_p->GetPosition(Xx, Yy); 
  
  g_lcd_manager_p->SetXY(Xx, Yy);  
  
  g_lcd_manager_p->SetLeftFirstWeelVal (tt++);
  g_lcd_manager_p->SetLeftLastWeelVal (tt++ + 10);
  g_lcd_manager_p->SetRightFirstWeelVal (tt + 20);
  g_lcd_manager_p->setRightLastWeelVal (tt + 30);
  
  g_lcd_manager_p->Refresh();

  if (tt > 950) tt = 0;

  g_timer_p->AddTask(print_to_lcd, print_to_lcd_period);
}
//==============================================================================================
//==============================================================================================
//==============================================================================================
void setup() {
  Serial.begin(115200);

  DDRB |= (1 << 5);

  int r = g_gyro_kalman_p->Init();

  g_lcd_manager_p->Init();
  g_menu_p->Init();
  

  g_timer_p->AddTask(led_blink, led_blink_period);
  g_timer_p->AddTask(send_message, send_message_period);
  g_timer_p->AddTask(send_message2, send_message2_period);
  g_timer_p->AddTask(update_buttons, update_buttons_period);
  g_timer_p->AddTask(print_to_lcd, print_to_lcd_period);
  g_timer_p->AddTask(update_hyroscope, update_hyroscope_period);
  g_timer_p->AddTask(reset_watch_dog, reset_watch_dog_period);


  wdt_reset();
  wdt_enable(WDTO_1S);
  g_timer_p->Init();

  g_mux_in_p->Init();
  g_mux_out_p->Init();
  g_buttons_p->Init();
  
  if (r){
    g_lcd_manager_p->SetErrorText((char *)"Gyro init error");
  }else{
    g_lcd_manager_p->SetMenuName(g_menu_p->GetCurrentName());
  }

  

  delay(1000);

  g_lcd_manager_p->Refresh();
}
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
//==============================================================================================
void loop() {

  TTask ttask = g_timer_p->GetTaskForWork();
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




