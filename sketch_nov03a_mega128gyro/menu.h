// #include "menu.h"
#ifndef MY_MENU_H
#define MY_MENU_H

#include "defines_buttons.h"

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

struct MUNU_BUTTON_ACTION {
  BUTTON_NAME but_name;
  void (*but_act)(void);
};

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

struct MENU_NODE {
	char * name;
	MENU_NODE * next;
	MENU_NODE * back;
  MENU_NODE * parent;
  MENU_NODE * child;
	MUNU_BUTTON_ACTION * buttons_action;

  MENU_NODE (){
    name = 0;
    next = 0;
    back = 0;
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

    static const unsigned char MENU_NODES_COUNT = 28;
    MENU_NODE nodes[MENU_NODES_COUNT];
    
    MENU_NODE * root;
    MENU_NODE * current;

  public:
   
    char * go_next(){
      if (current->next == 0){
        return current->name;
      }
      
      current = current->next;
      return current->name;      
    };
    
    char * go_back(){
      if (current->back == 0){
        return current->name;
      }
      
      current = current->back; 
      return current->name;      
    };
    
    char * go_parent(){
      if (current->parent == 0){
        return current->name;
      }
      
      current = current->parent; 
      return current->name;      
    };
    
    char * go_child(){
      if (current->child == 0){
        return current->name;
      }
      
      current = current->child; 
      return current->name;      
    };
    
    char * get_current_name(){
      return current->name; 
    };

    void init();
};

//=====================================================================================================
//=====================================================================================================
//=====================================================================================================

#endif
