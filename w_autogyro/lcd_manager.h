// #include "lcd_manager.h"
#ifndef MY_LCDManager_H
#define MY_LCDManager_H

#include "common_makros.h"
#include "lcd.h"

class LCDManager {

  public:
    
    LCDManager();

    void SetXY (double x, double y);    
    void SetLeftFirstWeelVal (double val);
    void SetLeftLastWeelVal (double val);
    void SetRightFirstWeelVal (double val);
    void setRightLastWeelVal (double val);
    
    void SetModeName (const char* mode_name);
    void ClearModeName ();

    void SetMenuName (const char* menu_name);  
    void ClearMenuName ();

    void SetErrorText (const char* err_text);  
    void ClearErrorText ();
    
    void Refresh();
    void Init();

  private:

    static const unsigned char LCD_STR_MAX_LEN = 17;
    static const unsigned char LCD_STR_COUNT = 4;

    char clear_str_[LCD_STR_MAX_LEN];
    bool is_need_refresh_[LCD_STR_COUNT];
    char str_[LCD_STR_COUNT][LCD_STR_MAX_LEN];

};

extern LCDManager * g_lcd_manager_p;

#endif