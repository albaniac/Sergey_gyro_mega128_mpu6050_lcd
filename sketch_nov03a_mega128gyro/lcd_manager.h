// #include "lcd_manager.h"
#include "common_makros.h"
#include "lcd.h"

class LCD_MANAGER {
  private:

    static const unsigned char LCD_STR_MAX_LEN = 17;
    static const unsigned char LCD_STR_COUNT = 4;
    
    char str[LCD_STR_COUNT][LCD_STR_MAX_LEN];

  public:
    
    LCD_MANAGER(){
    };

    void set_x (double x){
      memset(&str[0][5], ' ', 6);
      sprintf(&str[0][5], "X:%4d", (int)x);
      LCD_Write_String(0, 0, str[0]);
    };
    
    void set_y (double y){
      memset(&str[1][5], ' ', 6);
      sprintf(&str[1][5], "Y:%4d", (int)y);
      LCD_Write_String(1, 0, str[1]);
    };
    
    void set_left_first_weel_val (double val){};
    void set_left_last_weel_val (double val){};
    void set_right_first_weel_val (double val){};
    void set_right_last_weel_val (double val){};
    void set_mode_name (char * mode_name){};
    void set_menu_name (char * mode_name){
      
    };  

    void refresh(){
      LCD_Write_String(0, 0, &str[0][0]);
      LCD_Write_String(1, 0, &str[1][0]);
      LCD_Write_String(2, 0, &str[2][0]);
      LCD_Write_String(3, 0, &str[3][0]);      
    };

    void init(){
      memcpy(&str[0][0], "111%        222%*", 17);
      memcpy(&str[1][0], "333%        444%*", 17);
      memcpy(&str[2][0], "Suck My Dick    *", 17);
      memcpy(&str[3][0], "Thank You!      *", 17);

      LCD_Init();
      LCD_ligth(LCD_LIGHT_ON);
    };
};


