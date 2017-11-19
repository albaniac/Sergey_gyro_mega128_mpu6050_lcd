// #include "lcd_manager.h"

#include "common_makros.h"
#include "lcd.h"

class LCD_MANAGER {
  private:

    static const unsigned char LCD_STR_MAX_LEN = 17;
    static const unsigned char LCD_STR_COUNT = 4;
    char clear_str[LCD_STR_MAX_LEN];

    bool is_need_refresh[LCD_STR_COUNT];
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
      is_need_refresh[2] = true;
      sprintf(&str[2][0], "%s*", mode_name);
    };

    void clear_mode_name (){
      memcpy(&str[2][0], clear_str, LCD_STR_MAX_LEN);
    };

    void set_menu_name (char * menu_name){
      is_need_refresh[3] = true;
      sprintf(&str[3][0], "%s*", menu_name);
    };  

    void clear_menu_name (){
      memcpy(&str[3][0], clear_str, LCD_STR_MAX_LEN);
    };

    void set_error_text (char * err_text){
      is_need_refresh[3] = true;
      sprintf(&str[3][0], "%s*", err_text);
    };  

    void clear_error_text (){
      memcpy(&str[3][0], clear_str, LCD_STR_MAX_LEN);
    }
    
    void refresh(){
      //LCD_Clear_lcd();
      //LCD_Write_String(0, 0, clear_str);
      //LCD_Write_String(1, 0, clear_str);
      //LCD_Write_String(2, 0, clear_str);
      //LCD_Write_String(3, 0, clear_str);
      
      LCD_Write_String(0, 0, &str[0][0]);
      LCD_Write_String(1, 0, &str[1][0]);
      
      if (is_need_refresh[2]){
        LCD_Write_String(2, 0, clear_str);
        LCD_Write_String(2, 0, &str[2][0]);
        is_need_refresh[2] = false;
      }
      
      if (is_need_refresh[3]){
        LCD_Write_String(3, 0, clear_str);
        LCD_Write_String(3, 0, &str[3][0]);
        is_need_refresh[3] = false;
      }
      
    };

    void init(){
      memcpy(clear_str , "                *", LCD_STR_MAX_LEN);
      memcpy(&str[0][0], "111% X:-179 222%*", LCD_STR_MAX_LEN);
      memcpy(&str[1][0], "333% Y:-123 444%*", LCD_STR_MAX_LEN);
      memcpy(&str[2][0], "                *", LCD_STR_MAX_LEN);
      memcpy(&str[3][0], "                *", LCD_STR_MAX_LEN);

      for (unsigned char i = 0; i < LCD_STR_COUNT; i++){
        is_need_refresh[i] = false;
      }

      LCD_Init();
      LCD_ligth(LCD_LIGHT_ON);
    };
};


