#include "eeprom_worker.h"
#include <EEPROM.h>
//=======================================================================================
static EEPROMWorker  g_eeprom;
EEPROMWorker* g_eeprom_p = &g_eeprom;
//=======================================================================================
EEPROMWorker::EEPROMWorker(){
	
};
//=======================================================================================
HardWare EEPROMWorker::ReadCompressorT(){
	return YesCompressor;
};
//=======================================================================================
HardWare EEPROMWorker::ReadWeelsT(){
	return AllWeels;
};
//=======================================================================================
uint8_t EEPROMWorker::GetCalibrationByName(CalibratedObjects name, Calibration& calibration ){
  return 0;
};
//=======================================================================================
uint8_t EEPROMWorker::SetCalibrationByName(CalibratedObjects name, Calibration calibration){
  return 0;
};
//=======================================================================================

