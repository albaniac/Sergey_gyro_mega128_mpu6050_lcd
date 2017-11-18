// #include "menu.h"
#ifndef MY_MENU_H
#define MY_MENU_H

#include "defines_buttons.h"

char MENU_NODE_NAME_main[] = "Menu";
  char MENU_NODE_NAME_calibrate[] = "Calibrate";
    char MENU_NODE_NAME_left_first[] = "Left First Weel";
      char MENU_NODE_NAME_left_first_set_max[] = "Set Max";
      char MENU_NODE_NAME_left_first_set_min[] = "Set Min";
    char MENU_NODE_NAME_left_last[] = "Left Last Weel";
      char MENU_NODE_NAME_left_last_set_max[] = "Set Max";
      char MENU_NODE_NAME_left_last_set_min[] = "Set Min";
    char MENU_NODE_NAME_right_first[] = "Right First Weel";
      char MENU_NODE_NAME_right_first_set_max[] = "Set Max";
      char MENU_NODE_NAME_right_first_set_min[] = "Set Min";
    char MENU_NODE_NAME_right_last[] = "Right Last Weel";
      char MENU_NODE_NAME_right_last_set_max[] = "Set Max";
      char MENU_NODE_NAME_right_last_set_min[] = "Set Min";
    char MENU_NODE_NAME_compressor[] = "Compressor";
      char MENU_NODE_NAME_compressor_set_max[] = "Set Max";
      char MENU_NODE_NAME_compressor_set_min[] = "Set Min";
    char MENU_NODE_NAME_gyro_set_null[] = "Set gorizont";
  char MENU_NODE_NAME_reset[] = "Reset";
    char MENU_NODE_NAME_reset_gyro[] = "Reset gyro";
    char MENU_NODE_NAME_reset_max_min[] = "Reset Max_Min";
  char MENU_NODE_NAME_hardware_mode[] = "Hardware";
    char MENU_NODE_NAME_first_weel_only[] = "First Weel Only";
    char MENU_NODE_NAME_last_weel_only[] = "Last Weel Only";
    char MENU_NODE_NAME_full_weel[] = "4x4 weels";
    char MENU_NODE_NAME_h_compressor[] = "Compressor";
      char MENU_NODE_NAME_enable_compressor[] = "Yes Compressor";
      char MENU_NODE_NAME_disable_compressor[] = "No Compressor";

struct MUNU_BUTTON_ACTION{
  BUTTON_NAME but_name;
  void (*but_act)(void);
};

struct MENU_NODE {
	char *name;
	MENU_NODE * next;
	MENU_NODE * prev;
  MENU_NODE * parent;
	MUNU_BUTTON_ACTION * buttons_action;
};

class MyMenu {
  
  MENU_NODE * nodes;
  
};


#endif
