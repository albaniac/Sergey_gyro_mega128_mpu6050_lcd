// #include "menu.h"
#ifndef MY_MENU_H
#define MY_MENU_H

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

struct MENU_NODE {
  char* name;
  MENU_NODE* next;
  MENU_NODE* parent;
  MENU_NODE* child;
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
    const long ACTION_PERIOD = 1;

    MENU_NODE* root_;
    MENU_NODE* current_;

    void LinkParentChild(MENU_NODE* parrent_node, MENU_NODE* child_node);
    void LinkBackNext(MENU_NODE* back_node, MENU_NODE* next_node);

    MENU_NODE node_menu_;
    MENU_NODE node_calibrate_;
    MENU_NODE node_weel_;
    MENU_NODE node_lf_weel_;
    MENU_NODE node_lf_set_min_;
    MENU_NODE node_lf_set_max_;
    MENU_NODE node_rf_weel_;
    MENU_NODE node_rf_set_min_;
    MENU_NODE node_rf_set_max_;
    MENU_NODE node_ll_weel_;
    MENU_NODE node_ll_set_min_;
    MENU_NODE node_ll_set_max_;
    MENU_NODE node_rl_weel_;
    MENU_NODE node_rl_set_min_;
    MENU_NODE node_rl_set_max_;
    MENU_NODE node_compressor_;
    MENU_NODE node_compressor_set_min_;
    MENU_NODE node_compressor_set_max_;
    MENU_NODE node_gyro_;
    MENU_NODE node_gyro_x_;
    MENU_NODE node_x_set_min_;
    MENU_NODE node_x_set_max_;
    MENU_NODE node_gyro_y_;
    MENU_NODE node_y_set_min_;
    MENU_NODE node_y_set_max_;
    MENU_NODE node_reset_;
    MENU_NODE node_reset_gyro_zerro_;
    MENU_NODE node_reset_weels_;
    MENU_NODE node_reset_compressor_;
    MENU_NODE node_hardware_;
    MENU_NODE node_hard_f_only_;
    MENU_NODE node_hard_l_only_;
    MENU_NODE node_hard_l_f_;
    MENU_NODE node_hard_compressor_;
    MENU_NODE node_hard_compressor_exist_;
    MENU_NODE node_hard_compressor_not_exist_;
	
  public:

    char * GoNext();
    char * GoParent();
    char * GoChild();
    char * GetCurrentName();
    void Init();
};

extern MyMenu* g_menu_p;
#endif
