#include "menu.h"

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
	  
//=============================================================================
//=============================================================================
//=============================================================================

void MyMenu::init(){
  root = &nodes[0];
  current = root;
  
  nodes[0].name = MENU_NODE_NAME_main; // *
  nodes[0].next = &nodes[1];
  
  nodes[1].name = MENU_NODE_NAME_calibrate; // **
  nodes[1].next = &nodes[18];
  nodes[1].parent = &nodes[0];
  nodes[1].child = &nodes[2];
		 
  nodes[2].name = MENU_NODE_NAME_left_first; // ***
  nodes[2].next = &nodes[5];
  nodes[2].parent = &nodes[1];
  nodes[2].child = &nodes[3];

  nodes[3].name = MENU_NODE_NAME_left_first_set_max; // ****
  nodes[3].next = &nodes[4];
  nodes[3].parent = &nodes[2];
  
  nodes[4].name = MENU_NODE_NAME_left_first_set_min; // ****
  nodes[4].back = &nodes[3];
  nodes[4].parent = &nodes[2];

  nodes[5].name = MENU_NODE_NAME_left_last; // ***
  nodes[5].next = &nodes[8];
  nodes[5].back = &nodes[2];
  nodes[5].parent = &nodes[1];
  nodes[5].child = &nodes[6];
  
  nodes[6].name = MENU_NODE_NAME_left_last_set_max; // ****
  nodes[6].next = &nodes[7];
  nodes[6].parent = &nodes[5];

  nodes[7].name = MENU_NODE_NAME_left_last_set_min; // ****
  nodes[7].back = &nodes[6];
  nodes[7].parent = &nodes[5];
  
  nodes[8].name = MENU_NODE_NAME_right_first; // ***
  nodes[8].next = &nodes[11];
  nodes[8].back = &nodes[5];
  nodes[8].parent = &nodes[1];
  nodes[8].child = &nodes[9];

  nodes[9].name = MENU_NODE_NAME_right_first_set_max; // ****
  nodes[9].next = &nodes[10];
  nodes[9].parent = &nodes[8];

  nodes[10].name = MENU_NODE_NAME_right_first_set_min; // ****
  nodes[10].back = &nodes[9];
  nodes[10].parent = &nodes[8];

  nodes[11].name = MENU_NODE_NAME_right_last; // ***
  nodes[11].next = &nodes[14];
  nodes[11].back = &nodes[8];
  nodes[11].parent = &nodes[1];
  nodes[11].child = &nodes[12];

  nodes[12].name = MENU_NODE_NAME_right_last_set_max; // ****
  nodes[12].next = &nodes[13];
  nodes[12].parent = &nodes[11];

  nodes[13].name = MENU_NODE_NAME_right_last_set_min; // ****
  nodes[13].back = &nodes[12];
  nodes[13].parent = &nodes[11];

  nodes[14].name = MENU_NODE_NAME_compressor; // ***
  nodes[14].next = &nodes[17];
  nodes[14].back = &nodes[11];
  nodes[14].parent = &nodes[1];
  nodes[14].child = &nodes[15];

  nodes[15].name = MENU_NODE_NAME_compressor_set_max; // ****
  nodes[15].next = &nodes[16];
  nodes[15].parent = &nodes[14];

  nodes[16].name = MENU_NODE_NAME_compressor_set_min; // ****
  nodes[16].back = &nodes[15];
  nodes[16].parent = &nodes[14];

  nodes[17].name = MENU_NODE_NAME_gyro_set_null; // *** 
  nodes[17].back = &nodes[14];
  nodes[17].parent = &nodes[1];
  
  nodes[18].name = MENU_NODE_NAME_reset; // **
  nodes[18].next = &nodes[21];
  nodes[18].back = &nodes[1];
  nodes[18].parent = &nodes[0];
  nodes[18].child = &nodes[19];

  nodes[19].name = MENU_NODE_NAME_reset_gyro; // ***
  nodes[19].next = &nodes[20];
  nodes[19].parent = &nodes[18];

  nodes[20].name = MENU_NODE_NAME_reset_max_min; // ***
  nodes[20].back = &nodes[19];
  nodes[20].parent = &nodes[18];
  
  nodes[21].name = MENU_NODE_NAME_hardware_mode; // **
  nodes[21].back = &nodes[18];
  nodes[21].parent = &nodes[0];
  nodes[21].child = &nodes[22];

  nodes[22].name = MENU_NODE_NAME_first_weel_only; // ***
  nodes[22].next = &nodes[23];
  nodes[22].parent = &nodes[21];

  nodes[23].name = MENU_NODE_NAME_last_weel_only; // ***
  nodes[23].next = &nodes[24];
  nodes[23].back = &nodes[22];
  nodes[23].parent = &nodes[21];

  nodes[24].name = MENU_NODE_NAME_full_weel; // ***
  nodes[24].next = &nodes[25];
  nodes[24].back = &nodes[23];
  nodes[24].parent = &nodes[21];
  
  nodes[25].name = MENU_NODE_NAME_h_compressor; // ***
  nodes[25].back = &nodes[24];
  nodes[25].parent = &nodes[21];
  nodes[25].child = &nodes[26];

  nodes[26].name = MENU_NODE_NAME_enable_compressor; // ****
  nodes[26].next = &nodes[27];
  nodes[26].parent = &nodes[25];

  nodes[27].name = MENU_NODE_NAME_disable_compressor; // ****
  nodes[27].back = &nodes[26];
  nodes[27].parent = &nodes[25];

};

