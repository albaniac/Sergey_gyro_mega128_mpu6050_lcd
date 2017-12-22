#include "timer.h"
#include "common_makros.h"
#include <avr/io.h>
#include <avr/interrupt.h>
//==============================================================================================
static MySoftTimer g_timer;
MySoftTimer* g_timer_p = &g_timer;
//==============================================================================================
ISR (TIMER2_OVF_vect)
{
// cli();
  g_timer.touch_timer();
// sei();
}
//==============================================================================================
inline void setupTIMER2 (void)
{
  TIMSK &=~(1<<OCIE2 | 1<< TOIE2);  
  ASSR  = 1<<AS0;       
  TCNT2 = 0;
  //TCCR2 = 5<<CS20; // (1<<CS20 | 1<<CS21 | 1<<CS22)
  //TCCR2 = (1<<CS20 | 1<<CS21 | 1<<CS22);
  TCCR2 = 1<<CS21; // 010 = 2

  long pr = (long)(1.0 / ((1.0 / ((16000000.0 / 8.0) / 255.0)) * 1000.0)); // must be 2 then 8, but speed was in 4 times slower
  g_timer.set_my_prescaller_(pr);
  
  TIMSK |= 1<< TOIE2;
  //TIMSK |= (1<< TOIE2 | 1<<OCIE2);
//  sei();
}
//==============================================================================================
void MySoftTimer::Start(){
   TIMSK |= 1<< TOIE2;  
}
//==============================================================================================
void MySoftTimer::Stop(){
  TIMSK &=~(1<< TOIE2);
}
//==============================================================================================
void MySoftTimer::Init(){
  setupTIMER2();
}
//==============================================================================================
void MySoftTimer::SetMyPrescaller(long prescaller){
  prescaller_ = prescaller;
};
//==============================================================================================
bool MySoftTimer::AddTask(TTask task, long period){
  for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
	if (tasks_[i].task == 0){
	  tasks_[i].task = task;
	  tasks_[i].period = period * prescaller_;
	  tasks_[i].counter = tasks_[i].period;
	return true;
	}
  }
  return false;
};
//==============================================================================================
TTask MySoftTimer::GetTaskForWork(){
  for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
	if (tasks_[i].task != 0 && tasks_[i].counter <= 0){
	  TTask ctask = tasks_[i].task;
	  tasks_[i].task = 0;
	  return ctask;
	}
  }
  return 0;
};
//==============================================================================================
void MySoftTimer::TouchTimer(){
  for (unsigned char i = 0; i < MAX_TASK_COUNT; i++){
	if (tasks_[i].task != 0 && tasks_[i].counter > 0){
	  tasks_[i].counter--;
	}
  }
};
//==============================================================================================
