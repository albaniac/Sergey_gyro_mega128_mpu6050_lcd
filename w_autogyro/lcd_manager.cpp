#include "lcd_manager.h"
#include <stdio.h>
#include <string.h>

//=======================================================================================
LCDManager::LCDManager(){
};
//=======================================================================================
void LCDManager::SetXY (double x, double y){
  sprintf(&str_[0][5], "X:%4d", (int)x);
  sprintf(&str_[1][5], "Y:%4d", (int)y);
};    
//=======================================================================================
void LCDManager::SetLeftFirstWeelVal (double val){
  sprintf(&str_[0][0], "%3d", (int)val);
  str_[0][3] = '%';
};
//=======================================================================================
void LCDManager::SetLeftLastWeelVal (double val){
  sprintf(&str_[1][0], "%3d", (int)val);
  str_[1][3] = '%';
};
//=======================================================================================
void LCDManager::SetRightFirstWeelVal (double val){
  sprintf(&str_[0][12], "%3d", (int)val);
  str_[0][15] = '%';
};
//=======================================================================================
void LCDManager::setRightLastWeelVal (double val){
  sprintf(&str_[1][12], "%3d", (int)val);
  str_[1][15] = '%';
};
//=======================================================================================
void LCDManager::SetModeName (const char* mode_name){
  is_need_refresh_[2] = true;
  sprintf(&str_[2][0], "%s*", mode_name);
};
//=======================================================================================
void LCDManager::ClearModeName (){
  memcpy(&str_[2][0], clear_str_, LCD_STR_MAX_LEN);
};
//=======================================================================================
void LCDManager::SetMenuName (const char* menu_name){
  is_need_refresh_[3] = true;
  sprintf(&str_[3][0], "%s*", menu_name);
};  
//=======================================================================================
void LCDManager::ClearMenuName (){
  memcpy(&str_[3][0], clear_str_, LCD_STR_MAX_LEN);
};
//=======================================================================================
void LCDManager::SetErrorText (const char* err_text){
  is_need_refresh_[3] = true;
  sprintf(&str_[3][0], "%s*", err_text);
};  
//=======================================================================================
void LCDManager::ClearErrorText (){
  memcpy(&str_[3][0], clear_str_, LCD_STR_MAX_LEN);
}
//=======================================================================================
void LCDManager::Refresh(){
  //LCD_Clear_lcd();
  //LCD_Write_String(0, 0, clear_str_);
  //LCD_Write_String(1, 0, clear_str_);
  //LCD_Write_String(2, 0, clear_str_);
  //LCD_Write_String(3, 0, clear_str_);
  
  LCDWriteString(0, 0, &str_[0][0]);
  LCDWriteString(1, 0, &str_[1][0]);
  
  if (is_need_refresh_[2]){
	LCDWriteString(2, 0, clear_str_);
	LCDWriteString(2, 0, &str_[2][0]);
	is_need_refresh_[2] = false;
  }
  
  if (is_need_refresh_[3]){
	LCDWriteString(3, 0, clear_str_);
	LCDWriteString(3, 0, &str_[3][0]);
	is_need_refresh_[3] = false;
  }
  
};
//=======================================================================================
void LCDManager::Init(){
  memcpy(clear_str_ , "                *", LCD_STR_MAX_LEN);
  memcpy(&str_[0][0], "111% X:-179 222%*", LCD_STR_MAX_LEN);
  memcpy(&str_[1][0], "333% Y:-123 444%*", LCD_STR_MAX_LEN);
  memcpy(&str_[2][0], "                *", LCD_STR_MAX_LEN);
  memcpy(&str_[3][0], "                *", LCD_STR_MAX_LEN);

  for (unsigned char i = 0; i < LCD_STR_COUNT; i++){
	is_need_refresh_[i] = false;
  }

  LCDInit();
  LCDLigth(LCD_LIGHT_ON);
};
//=======================================================================================
static LCDManager g_lcd_manager;
LCDManager * g_lcd_manager_p = &g_lcd_manager;
//=======================================================================================
