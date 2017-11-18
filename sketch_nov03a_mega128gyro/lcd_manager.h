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

    void set_x_y (double x, double y){
      sprintf(&str[0][5], "X:%4d", (int)x);
      sprintf(&str[1][5], "Y:%4d", (int)y);
    };    
    void set_left_first_weel_val (double val){
      sprintf(&str[0][0], "%3d", (int)val);
      str[0][3] = '%';
    };
    void set_left_last_weel_val (double val){
      sprintf(&str[1][0], "%3d", (int)val);
      str[1][3] = '%';
    };
    void set_right_first_weel_val (double val){
      sprintf(&str[0][12], "%3d", (int)val);
      str[0][15] = '%';
    };
    void set_right_last_weel_val (double val){
      sprintf(&str[1][12], "%3d", (int)val);
      str[1][15] = '%';
    };
    
    void set_mode_name (char * mode_name){
      clear_mode_name();
      sprintf(&str[2][0], "%s*", mode_name);
    };

    void clear_mode_name (){
      memset(&str[2][0], ' ', 16);
      str[2][16] = '*';
    };

    void set_menu_name (char * menu_name){
      clear_menu_name();
      sprintf(&str[3][0], "%s*", menu_name);
    };  

    void clear_menu_name (){
      memset(&str[3][0], ' ', 16);
      str[3][16] = '*';
    };

    void set_error_text (char * err_text){
      clear_error_text();
      sprintf(&str[3][0], "%s*", err_text);
    };  

    void clear_error_text (){
      memset(&str[3][0], ' ', 16);
      str[3][16] = '*';
    }
    
    void refresh(){
      LCD_Write_String(0, 0, &str[0][0]);
      LCD_Write_String(1, 0, &str[1][0]);
      LCD_Write_String(2, 0, &str[2][0]);
      LCD_Write_String(3, 0, &str[3][0]);      
    };

    void init(){
      memcpy(&str[0][0], "111% X:-179 222%*", 17);
      memcpy(&str[1][0], "333% Y:-123 444%*", 17);
      memcpy(&str[2][0], "Suck My Dick    *", 17);
      memcpy(&str[3][0], "Thank You!      *", 17);

      LCD_Init();
      LCD_ligth(LCD_LIGHT_ON);
    };
};


