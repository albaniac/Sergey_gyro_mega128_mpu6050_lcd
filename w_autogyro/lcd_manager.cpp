#include "lcd_manager.h"
//=======================================================================================
LCDManager::LCDManager(){
};
//=======================================================================================
void LCDManager::SetXY (double x, double y){
  sprintf(&str[0][5], "X:%4d", (int)x);
  sprintf(&str[1][5], "Y:%4d", (int)y);
};    
//=======================================================================================
void LCDManager::SetLeftFirstWeelVal (double val){
  sprintf(&str[0][0], "%3d", (int)val);
  str[0][3] = '%';
};
//=======================================================================================
void LCDManager::SetLeftLastWeelVal (double val){
  sprintf(&str[1][0], "%3d", (int)val);
  str[1][3] = '%';
};
//=======================================================================================
void LCDManager::SetRightFirstWeelVal (double val){
  sprintf(&str[0][12], "%3d", (int)val);
  str[0][15] = '%';
};
//=======================================================================================
void LCDManager::setRightLastWeelVal (double val){
  sprintf(&str[1][12], "%3d", (int)val);
  str[1][15] = '%';
};
//=======================================================================================
void LCDManager::SetModeName (char * mode_name){
  is_need_refresh[2] = true;
  sprintf(&str[2][0], "%s*", mode_name);
};
//=======================================================================================
void LCDManager::ClearModeName (){
  memcpy(&str[2][0], clear_str, LCD_STR_MAX_LEN);
};
//=======================================================================================
void LCDManager::SetMenuName (char * menu_name){
  is_need_refresh[3] = true;
  sprintf(&str[3][0], "%s*", menu_name);
};  
//=======================================================================================
void LCDManager::ClearMenuName (){
  memcpy(&str[3][0], clear_str, LCD_STR_MAX_LEN);
};
//=======================================================================================
void LCDManager::SetErrorText (char * err_text){
  is_need_refresh[3] = true;
  sprintf(&str[3][0], "%s*", err_text);
};  
//=======================================================================================
void LCDManager::ClearErrorText (){
  memcpy(&str[3][0], clear_str, LCD_STR_MAX_LEN);
}
//=======================================================================================
void LCDManager::Refresh(){
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
//=======================================================================================
void LCDManager::Init(){
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
//=======================================================================================
static LCDManager g_lcd_manager;
LCDManager * g_lcd_manager_p = &g_lcd_manager;
//=======================================================================================
