//#include "balancer.h"
#ifndef MY_SUPER_PUPER_BALANCER_H
#define MY_SUPER_PUPER_BALANCER_H

#include <Arduino.h>

class Balancer{
public:

	Balancer();
	void Init();
	void TryBalance();
	void StopBalance();
	
	// FGTIB = ForGlobalTimerInBalance
	static const uint32_t FGTIBMANAGECOMPRESSORPERIOD = 1000;
	void FGTIBManageCompressor(void);
	void FGTIBManageCompressorOn(void);
	void FGTIBManageCompressorOff(void);
	
	void FGTIBStartBalance(void);
	
	void FGTIBFirstWeelsUp(void);
	void FGTIBFirstWeelsDown(void);
	void FGTIBLastWeelsUp(void);
	void FGTIBLastWeelsDown(void);
	void FGTIBLeftWeelsUp(void);
	void FGTIBLeftWeelsDown(void);
	void FGTIBRightWeelsUp(void);
	void FGTIBRightWeelsDown(void);
	
	void FGTIBFirstLeftWeelUp(void);
	void FGTIBFirstLeftWeelDown(void);
	void FGTIBLastLeftWeelUp(void);
	void FGTIBLastLastWeelDown(void);
	void FGTIBFirstRightWeelUp(void);
	void FGTIBFirstRightWeelDown(void);
	void FGTIBLastRightWeelUp(void);
	void FGTIBLastRightWeelDown(void);

	void FGTIBCheckPosition(void);
	void FGTIBStopAndInform(void);
	
private:
	
};

extern Balancer* g_balanser_p;
#endif
