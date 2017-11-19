// #include "timer.h"
#ifndef MY_TIMER_H
#define MY_TIMER_H

//#include <avr/io.h>
//#include "common_makros.h"

typedef void (*TTask)(void);

struct MySoftTimerTask {
  long period;
  long counter;
  TTask task;
  bool is_repeted;
  bool is_finished;
  
  MySoftTimerTask(){
    period = 0;
	  counter = 0;
	  task = 0;
	  is_repeted = false;
  }
};

class MySoftTimer {
  private:
  
  static const unsigned char MAX_TASK_COUNT = 10;
	MySoftTimerTask tasks[MAX_TASK_COUNT];
  
  public:
  
    void init();
    
	  bool add_task(TTask task, long period, bool is_repeted){
  	  for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
  	    if (tasks[i].task == 0){
  		  tasks[i].task = task;
  		  tasks[i].period = period;
  		  tasks[i].is_repeted = is_repeted;
  		  tasks[i].counter = period;
        return true;
  		}
	  }
	  return false;
	};
	
    TTask get_task_for_work(){
      for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
        if (tasks[i].task != 0 && tasks[i].counter <= 0){
          TTask ctask = tasks[i].task;
          if (tasks[i].is_repeted){
            tasks[i].counter = tasks[i].period;
          }else{
            tasks[i].task = 0;
          }
          return ctask;
        }
      }
      return 0;
    };
	
	  void touch_timer(){
      for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
        if (tasks[i].task != 0 && tasks[i].counter > 0){
          tasks[i].counter--;
        }
      }
    };
    
};

extern MySoftTimer g_timer;
#endif
