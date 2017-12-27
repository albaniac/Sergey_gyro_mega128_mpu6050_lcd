#include "eeprom_worker.h"
#include <Arduino.h>
#include <EEPROM.h>
//=======================================================================================
#define START_ADRESS 10

#define HARDWARE_SHIFT_START 0
#define HARDWARE_SHIFT_COMPRESSOR 0
#define HARDWARE_SHIFT_WEELS 1

#define CALIBRATE_SHIFT_START 10

#define CALIBRATE_SHIFT_MIN 0
#define CALIBRATE_SHIFT_MAX 2
#define CALIBRATE_SHIFT_DELTA 4

#define CALIBRATE_SHIFT_DATA 20
//=======================================================================================
static EEPROMWorker  g_eeprom;
EEPROMWorker* g_eeprom_p = &g_eeprom;
//=======================================================================================
EEPROMWorker::EEPROMWorker(){
	
};
//=======================================================================================
HardWare EEPROMWorker::ReadCompressorT(){
	uint16_t address = START_ADRESS + HARDWARE_SHIFT_START + HARDWARE_SHIFT_COMPRESSOR;
	HardWare hardware = (HardWare)EEPROM.read(address);
	//return hardware;
	return YesCompressor;
};
//=======================================================================================
void EEPROMWorker::WriteCompressorT(HardWare hardware){
	uint16_t address = START_ADRESS + HARDWARE_SHIFT_START + HARDWARE_SHIFT_COMPRESSOR;
	EEPROM.write(address, (byte)hardware);
};
//=======================================================================================
HardWare EEPROMWorker::ReadWeelsT(){
	uint16_t address = START_ADRESS + HARDWARE_SHIFT_START + HARDWARE_SHIFT_WEELS;
	HardWare hardware = (HardWare)EEPROM.read(address);
	//return hardware;
	return AllWeels;
};
//=======================================================================================
void EEPROMWorker::WriteWeelsT(HardWare hardware){
	uint16_t address = START_ADRESS + HARDWARE_SHIFT_START + HARDWARE_SHIFT_WEELS;
	EEPROM.write(address, (byte)hardware);
};
//=======================================================================================
uint8_t EEPROMWorker::GetFromMemoryCalibrationByName(CalibratedObjects name, Calibration& calibration ){
  uint16_t address = START_ADRESS + CALIBRATE_SHIFT_START + (CALIBRATE_SHIFT_DATA * ((int)name));
  
  uint16_t calibrate_val = 0;
  EEPROM.get(address + CALIBRATE_SHIFT_MIN, calibrate_val);
  calibration.min = calibrate_val;
  calibrate_val = 0;
  EEPROM.get(address + CALIBRATE_SHIFT_MAX, calibrate_val);
  calibration.max = calibrate_val;
  calibrate_val = 0;
  EEPROM.get(address + CALIBRATE_SHIFT_DELTA, calibrate_val);
  calibration.delta = calibrate_val;
  
  return 0;
};
//=======================================================================================
uint8_t EEPROMWorker::SetInMemoryCalibrationByName(CalibratedObjects name, Calibration calibration){
  uint16_t address = START_ADRESS + CALIBRATE_SHIFT_START + (CALIBRATE_SHIFT_DATA * ((int)name));
  
  EEPROM.put(address + CALIBRATE_SHIFT_MIN, calibration.min);
  EEPROM.put(address + CALIBRATE_SHIFT_MAX, calibration.max);
  EEPROM.put(address + CALIBRATE_SHIFT_DELTA, calibration.delta);
  
  return 0;
};
//=======================================================================================
uint8_t EEPROMWorker::GetFromMemoryGyroZerroCalibration(double& x, double& y){
  uint16_t address = START_ADRESS + CALIBRATE_SHIFT_START + (CALIBRATE_SHIFT_DATA * ((int)CaliObbjGyroScope));
  
  EEPROM.get(address + CALIBRATE_SHIFT_MIN, x);
  EEPROM.get(address + CALIBRATE_SHIFT_MAX, y);
};
//=======================================================================================
uint8_t EEPROMWorker::SetInMemoryGyroZerroCalibration(double x, double y){
  uint16_t address = START_ADRESS + CALIBRATE_SHIFT_START + (CALIBRATE_SHIFT_DATA * ((int)CaliObbjGyroScope));
  
  EEPROM.put(address + CALIBRATE_SHIFT_MIN, x);
  EEPROM.put(address + CALIBRATE_SHIFT_MAX, y);
};
//=======================================================================================

