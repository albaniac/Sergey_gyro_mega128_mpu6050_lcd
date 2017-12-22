// #include "timer.h"
#ifndef MY_TIMER_H
#define MY_TIMER_H

typedef void (*TTask)(void);

struct MySoftTimerTask {
  long period;
  long counter;
  TTask task;
  
  MySoftTimerTask(){
    period = 0;
	  counter = 0;
	  task = 0;
  }
};

class MySoftTimer {
  private:
  
  static const unsigned char MAX_TASK_COUNT = 32;
	MySoftTimerTask tasks[MAX_TASK_COUNT];
  long prescaller;
  
  public:
  
    void init();

    void stop();
    void start();
    
    void set_my_prescaller(long new_prescaller){
      prescaller = new_prescaller;
    };
    
	  bool add_task(TTask task, long period){
  	  for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
  	    if (tasks[i].task == 0){
  		  tasks[i].task = task;
  		  tasks[i].period = period * prescaller;
  		  tasks[i].counter = tasks[i].period;
        return true;
  		}
	  }
	  return false;
	};
	
    TTask get_task_for_work(){
      for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
        if (tasks[i].task != 0 && tasks[i].counter <= 0){
          TTask ctask = tasks[i].task;
          tasks[i].task = 0;
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
