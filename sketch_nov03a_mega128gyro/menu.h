// #include "menu.h"
#ifndef MY_MENU_H
#define MY_MENU_H

#include "defines_buttons.h"
#include "timer.h"

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

struct MENU_NODE {
  char * name;
  MENU_NODE * next;
  MENU_NODE * parent;
  MENU_NODE * child;
  TTask buttons_action;

  MENU_NODE () {
    name = 0;
    next = 0;
    parent = 0;
    child = 0;
    buttons_action = 0;
  };
};

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

class MyMenu {

  private:
    const long action_period = 1;

    MENU_NODE * root;
    MENU_NODE * current;

    void link_parent_child(MENU_NODE * parrent_node, MENU_NODE * child_node);
    void link_back_next(MENU_NODE * back_node, MENU_NODE * next_node);

    MENU_NODE node_menu;
    MENU_NODE node_calibrate;
    MENU_NODE node_weel;
    MENU_NODE node_lf_weel;
    MENU_NODE node_lf_set_min;
    MENU_NODE node_lf_set_max;
    MENU_NODE node_rf_weel;
    MENU_NODE node_rf_set_min;
    MENU_NODE node_rf_set_max;
    MENU_NODE node_ll_weel;
    MENU_NODE node_ll_set_min;
    MENU_NODE node_ll_set_max;
    MENU_NODE node_rl_weel;
    MENU_NODE node_rl_set_min;
    MENU_NODE node_rl_set_max;
    MENU_NODE node_compressor;
    MENU_NODE node_compressor_set_min;
    MENU_NODE node_compressor_set_max;
    MENU_NODE node_gyro;
    MENU_NODE node_gyro_x;
    MENU_NODE node_x_set_min;
    MENU_NODE node_x_set_max;
    MENU_NODE node_gyro_y;
    MENU_NODE node_y_set_min;
    MENU_NODE node_y_set_max;
    MENU_NODE node_reset;
    MENU_NODE node_reset_gyro_zerro;
    MENU_NODE node_reset_weels;
    MENU_NODE node_reset_compressor;
    MENU_NODE node_hardware;
    MENU_NODE node_hard_f_only;
    MENU_NODE node_hard_l_only;
    MENU_NODE node_hard_l_f;
    MENU_NODE node_hard_compressor;
    MENU_NODE node_hard_compressor_exist;
    MENU_NODE node_hard_compressor_not_exist;
	
  public:

    char * go_next();
    char * go_parent();
    char * go_child();
    char * get_current_name();
    void init();
};

extern MyMenu g_menu;
#endif
