#define MENU_NODENAME_LEN 16

struct MENU_NODE {
	char name[MENU_NODENAME_LEN];
	MENU_NODE * next;
	MENU_NODE * prev;
	void (*node_act)(void);
};



