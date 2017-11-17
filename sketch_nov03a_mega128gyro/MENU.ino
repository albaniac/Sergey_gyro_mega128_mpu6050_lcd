char MENU_NODE_NAME_1_main[] = "MENU";

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
  
  MyMenu(){
    
  };
};

