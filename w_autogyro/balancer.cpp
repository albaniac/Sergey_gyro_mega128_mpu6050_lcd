#include "balancer.h"
#include "data_manager.h"
#include "timer.h"
//=======================================================================================
//AddTask(TTask task, long period);
//=======================================================================================
Balancer g_balanser;
Balancer* g_balanser_p = &g_balanser;
//=======================================================================================
Balancer::Balancer(){
	
};
//=======================================================================================
void Balancer::Init(){
	
};
//=======================================================================================
void Balancer::TryBalance(){
	
};
//=======================================================================================
void Balancer::StopBalance(){
	
};
//=======================================================================================

// FGTIB = ForGlobalTimerInBalance
void Balancer::FGTIBManageCompressor(void){};
void Balancer::FGTIBManageCompressorOn(void){};
void Balancer::FGTIBManageCompressorOff(void){};

void Balancer::FGTIBStartBalance(void){};

void Balancer::FGTIBFirstWeelsUp(void){};
void Balancer::FGTIBFirstWeelsDown(void){};
void Balancer::FGTIBLastWeelsUp(void){};
void Balancer::FGTIBLastWeelsDown(void){};
void Balancer::FGTIBLeftWeelsUp(void){};
void Balancer::FGTIBLeftWeelsDown(void){};
void Balancer::FGTIBRightWeelsUp(void){};
void Balancer::FGTIBRightWeelsDown(void){};

void Balancer::FGTIBFirstLeftWeelUp(void){};
void Balancer::FGTIBFirstLeftWeelDown(void){};
void Balancer::FGTIBLastLeftWeelUp(void){};
void Balancer::FGTIBLastLastWeelDown(void){};
void Balancer::FGTIBFirstRightWeelUp(void){};
void Balancer::FGTIBFirstRightWeelDown(void){};
void Balancer::FGTIBLastRightWeelUp(void){};
void Balancer::FGTIBLastRightWeelDown(void){};

void Balancer::FGTIBCheckPosition(void){};
void Balancer::FGTIBStopAndInform(void){};
