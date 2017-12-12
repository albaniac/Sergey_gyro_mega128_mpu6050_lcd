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

    void link_parent_child(MENU_NODE * parrent_node, MENU_NODE * child_node) {
      child_node->parent = parrent_node;
      if (parrent_node->child == 0) {
        parrent_node->child = child_node;
      }
    };

    void link_back_next(MENU_NODE * back_node, MENU_NODE * next_node) {
      back_node->next = next_node;
    };

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

    char * go_next() {
      if (current->next == 0) {
        return current->name;
      }

      current = current->next;
      return current->name;
    };


    char * go_parent() {
      if (current->parent == 0) {
        return current->name;
      }

      current = current->parent;
      return current->name;
    };

    char * go_child() {
      if (current->child == 0) {
        if (current->buttons_action != 0) {
          g_timer.add_task(current->buttons_action, action_period);
        }
        return current->name;
      }

      current = current->child;
      return current->name;
    };

    char * get_current_name() {
      return current->name;
    };

    void init() {

      node_menu.name = "Menu";

      node_calibrate.name = "Calibrate";
      link_parent_child(&node_menu, &node_calibrate);

      node_weel.name = "Weel";
      link_parent_child(&node_calibrate, &node_weel);

      node_lf_weel.name = "Left First Weel";
      link_parent_child(&node_weel, &node_lf_weel);

      node_lf_set_min.name = "Set Min";
      link_parent_child(&node_lf_weel, &node_lf_set_min);

      node_lf_set_max.name = "Set Max";
      link_parent_child(&node_lf_weel, &node_lf_set_max);
      link_back_next(&node_lf_set_min, &node_lf_set_max);

      link_back_next(&node_lf_set_max, &node_lf_set_min);

      node_rf_weel.name = "Left Last Weel";
      link_parent_child(&node_weel, &node_rf_weel);
      link_back_next(&node_lf_weel, &node_rf_weel);

      node_rf_set_min.name = "Set Min";
      link_parent_child(&node_rf_weel, &node_rf_set_min);
      
      node_rf_set_max.name = "Set Max";
      link_parent_child(&node_rf_weel, &node_rf_set_max);
      link_back_next(&node_rf_set_min, &node_rf_set_max);

      link_back_next(&node_rf_set_max, &node_rf_set_min);
      
      /*
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

      */
      root = &node_menu;
      current = root;
    };
};

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

#endif
