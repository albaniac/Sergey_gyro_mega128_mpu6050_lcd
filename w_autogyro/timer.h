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
  
  static const unsigned char MAX_TASK_COUNT = 64;
	MySoftTimerTask tasks_[MAX_TASK_COUNT];
  long prescaller_;
  
  public:
  
    void Init();
    void Stop();
    void Start();
    
    void SetMyPrescaller(long prescaller);
    
	bool AddTask(TTask task, long period);
	
    TTask GetTaskForWork();
	
	void TouchTimer();
    
};

extern MySoftTimer* g_timer_p;
#endif
