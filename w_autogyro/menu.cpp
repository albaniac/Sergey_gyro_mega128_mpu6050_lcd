#include "menu.h"
#include "buttons_defines.h"
#include "timer.h"

//=======================================================================================

static MyMenu g_menu;
MyMenu* g_menu_p = &g_menu;

//=======================================================================================

void MyMenu::LinkParentChild(MENU_NODE* parrent_node, MENU_NODE* child_node) {
  child_node->parent = parrent_node;
  if (parrent_node->child == 0) {
	parrent_node->child = child_node;
  }
};

//=======================================================================================

void MyMenu::LinkBackNext(MENU_NODE* back_node, MENU_NODE* next_node) {
  back_node->next = next_node;
};

//=======================================================================================

char * MyMenu::GoNext() {
  if (current_->next == 0) {
	return current_->name;
  }

  current_ = current_->next;
  return current_->name;
};

//=======================================================================================

char * MyMenu::GoParent() {
  if (current_->parent == 0) {
	return current_->name;
  }

  current_ = current_->parent;
  return current_->name;
};

//=======================================================================================

char * MyMenu::GoChild() {
  if (current_->child == 0) {
	if (current_->buttons_action != 0) {
	  g_timer_p->AddTask(current_->buttons_action, ACTION_PERIOD);
	}
	return current_->name;
  }

  current_ = current_->child;
  return current_->name;
};

//=======================================================================================

char * MyMenu::GetCurrentName() {
  return current_->name;
};

//=======================================================================================

void MyMenu::Init(){
  node_menu_.name = "Menu";

  node_calibrate_.name = "Calibrate";
  LinkParentChild(&node_menu_, &node_calibrate_);

  node_weel_.name = "Weel";
  LinkParentChild(&node_calibrate_, &node_weel_);

  node_lf_weel_.name = "Left First Weel";
  LinkParentChild(&node_weel_, &node_lf_weel_);

  node_lf_set_min_.name = "Set Min";
  LinkParentChild(&node_lf_weel_, &node_lf_set_min_);

  node_lf_set_max_.name = "Set Max";
  LinkParentChild(&node_lf_weel_, &node_lf_set_max_);
  LinkBackNext(&node_lf_set_min_, &node_lf_set_max_);

  LinkBackNext(&node_lf_set_max_, &node_lf_set_min_);

  node_rf_weel_.name = "Right First Weel";
  LinkParentChild(&node_weel_, &node_rf_weel_);
  LinkBackNext(&node_lf_weel_, &node_rf_weel_);

  node_rf_set_min_.name = "Set Min";
  LinkParentChild(&node_rf_weel_, &node_rf_set_min_);
  
  node_rf_set_max_.name = "Set Max";
  LinkParentChild(&node_rf_weel_, &node_rf_set_max_);
  LinkBackNext(&node_rf_set_min_, &node_rf_set_max_);

  LinkBackNext(&node_rf_set_max_, &node_rf_set_min_);

  node_ll_weel_.name = "Left Last Weel";
  LinkParentChild(&node_weel_, &node_ll_weel_);
  LinkBackNext(&node_rf_weel_, &node_ll_weel_);

  node_ll_set_min_.name = "Set Min";
  LinkParentChild(&node_ll_weel_, &node_ll_set_min_);
  
  node_ll_set_max_.name = "Set Max";
  LinkParentChild(&node_ll_weel_, &node_ll_set_max_);
  LinkBackNext(&node_ll_set_min_, &node_ll_set_max_);

  LinkBackNext(&node_ll_set_max_, &node_ll_set_min_);
  
  node_rl_weel_.name = "Right Last Weel";
  LinkParentChild(&node_weel_, &node_rl_weel_);
  LinkBackNext(&node_ll_weel_, &node_rl_weel_);

  node_rl_set_min_.name = "Set Min";
  LinkParentChild(&node_rl_weel_, &node_rl_set_min_);
  
  node_rl_set_max_.name = "Set Max";
  LinkParentChild(&node_rl_weel_, &node_rl_set_max_);
  LinkBackNext(&node_rl_set_min_, &node_rl_set_max_);

  LinkBackNext(&node_rl_set_max_, &node_rl_set_min_);

  LinkBackNext(&node_rl_weel_, &node_lf_weel_); // loop to lf

  node_compressor_.name = "Compressor";
  LinkParentChild(&node_calibrate_, &node_compressor_);
  LinkBackNext(&node_weel_, &node_compressor_);

  node_compressor_set_min_.name = "Set Min";
  LinkParentChild(&node_compressor_, &node_compressor_set_min_);
  
  node_compressor_set_max_.name = "Set Max";
  LinkParentChild(&node_compressor_, &node_compressor_set_max_);
  LinkBackNext(&node_compressor_set_min_, &node_compressor_set_max_);

  LinkBackNext(&node_compressor_set_max_, &node_compressor_set_min_);

  node_gyro_.name = "Gyroscope";
  LinkParentChild(&node_calibrate_, &node_gyro_);
  LinkBackNext(&node_compressor_, &node_gyro_);

  node_gyro_x_.name = "X-axis";
  LinkParentChild(&node_gyro_, &node_gyro_x_);
  
  node_x_set_min_.name = "Set Min";
  LinkParentChild(&node_gyro_x_, &node_x_set_min_);
  
  node_x_set_max_.name = "Set Max";
  LinkParentChild(&node_gyro_x_, &node_x_set_max_);
  LinkBackNext(&node_x_set_min_, &node_x_set_max_);

  LinkBackNext(&node_x_set_max_, &node_x_set_min_);

  node_gyro_y_.name = "Y-axis";
  LinkParentChild(&node_gyro_, &node_gyro_y_);
  LinkBackNext(&node_gyro_x_, &node_gyro_y_);
  
  node_x_set_min_.name = "Set Min";
  LinkParentChild(&node_gyro_y_, &node_y_set_min_);
  
  node_x_set_max_.name = "Set Max";
  LinkParentChild(&node_gyro_y_, &node_y_set_max_);
  LinkBackNext(&node_y_set_min_, &node_y_set_max_);

  LinkBackNext(&node_y_set_max_, &node_y_set_min_);

  LinkBackNext(&node_gyro_y_, &node_gyro_x_); // loop to X-axis

  LinkBackNext(&node_gyro_, &node_weel_); // loop to weel
  
  node_reset_.name = "Reset";   
  LinkParentChild(&node_menu_, &node_reset_);
  LinkBackNext(&node_calibrate_, &node_reset_); 

  node_reset_gyro_zerro_.name = "Reset gyro";
  LinkParentChild(&node_reset_, &node_reset_gyro_zerro_);

  node_reset_weels_.name = "Reset weels";
  LinkParentChild(&node_reset_, &node_reset_weels_);
  LinkBackNext(&node_reset_gyro_zerro_, &node_reset_weels_);

  node_reset_compressor_.name = "Reset compressor";
  LinkParentChild(&node_reset_, &node_reset_compressor_);
  LinkBackNext(&node_reset_weels_, &node_reset_compressor_);

  LinkBackNext(&node_reset_compressor_, &node_reset_gyro_zerro_); // loop to reset gyro

  node_hardware_.name = "Hardware";
  LinkParentChild(&node_menu_, &node_hardware_);
  LinkBackNext(&node_reset_, &node_hardware_); 

  node_hard_f_only_.name = "First Weels Only";
  LinkParentChild(&node_hardware_, &node_hard_f_only_);

  node_hard_l_only_.name = "Last Weels Only";
  LinkParentChild(&node_hardware_, &node_hard_l_only_);
  LinkBackNext(&node_hard_f_only_, &node_hard_l_only_); 

  node_hard_l_f_.name = "4 x 4";
  LinkParentChild(&node_hardware_, &node_hard_l_f_);
  LinkBackNext(&node_hard_l_only_, &node_hard_l_f_); 

  node_hard_compressor_.name = "Is compressor";
  LinkParentChild(&node_hardware_, &node_hard_compressor_);
  LinkBackNext(&node_hard_l_f_, &node_hard_compressor_); 

  node_hard_compressor_exist_.name = "Compressor exists";
  LinkParentChild(&node_hard_compressor_, &node_hard_compressor_exist_);   

  node_hard_compressor_not_exist_.name = "Compressor NOT exists";
  LinkParentChild(&node_hard_compressor_, &node_hard_compressor_not_exist_);   

  LinkBackNext(&node_hard_compressor_exist_, &node_hard_compressor_not_exist_); 
  LinkBackNext(&node_hard_compressor_not_exist_, &node_hard_compressor_exist_); 

  LinkBackNext(&node_hard_compressor_, &node_hard_f_only_); // loop to compressor

  LinkBackNext(&node_hardware_, &node_calibrate_); // loop to colibrate

  root_ = &node_menu_;
  current_ = root_;
}

//=======================================================================================

