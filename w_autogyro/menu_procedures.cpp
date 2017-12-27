#include "menu_procedures.h"
#include "menu.h"
#include "data_manager.h"

#define MENUDEBUG

#ifdef MENUDEBUG
#include <Arduino.h>
#include <string.h>
#include <avr/pgmspace.h>
#endif

//=======================================================================================
void ProcNodeLFSetMin(void){ // ready
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeLFSetMin"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMinByName(WeelFirstLeft);
	//#endif
  
};
//=======================================================================================
void ProcNodeLFSetMax(void){ // ready
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeLFSetMax"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMaxByName(WeelFirstLeft);
	//#endif
  
};
//=======================================================================================
void ProcNodeRFSetMin(void){ // ready
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeRFSetMin"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMinByName(WeelFirstRight);
	//#endif
  
};
//=======================================================================================
void ProcNodeRFSetMax(void){ // ready
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeRFSetMax"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMaxByName(WeelFirstRight);
	//#endif
  
};
//=======================================================================================
void ProcNodeLLSetMin(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeLLSetMin"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMinByName(WeelLastLeft);
	//#endif
  
};
//=======================================================================================
void ProcNodeLLSetMax(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeLLSetMax"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMaxByName(WeelLastLeft);
	//#endif
  
};
//=======================================================================================
void ProcNodeRLSetMin(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeRLSetMin"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMinByName(WeelLastRight);
	//#endif
  
};
//=======================================================================================
void ProcNodeRLSetMax(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeRLSetMax"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMaxByName(WeelLastRight);
	//#endif
  
};
//=======================================================================================
void ProcNodeCompressorSetMin(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeCompressorSetMin"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMinByName(DeviceCompressor);
	//#endif
  
};
//=======================================================================================
void ProcNodeCompressorSetMax(void){ // ready
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeCompressorSetMax"));
	#endif
	
	//#ifndef MENUDEBUG
	g_data_manager_p->SetCalibrationMaxByName(DeviceCompressor);
	//#endif
  
};
//=======================================================================================
void ProcNodeGyroXSetMin(void){
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeGyroXSetMin"));
	#endif
};
//=======================================================================================
void ProcNodeGyroXSetMax(void){
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeGyroXSetMax"));
	#endif
};
//=======================================================================================
void ProcNodeGyroYSetMin(void){
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeGyroYSetMin"));
	#endif
};
//=======================================================================================
void ProcNodeGyroYSetMax(void){
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeGyroYSetMax"));
	#endif
};
//=======================================================================================
void ProcNodeResetGyroZerro(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeResetGyroZerro"));
	#endif
	
	g_data_manager_p->SetCalibrationGyroZerro();
	
};
//=======================================================================================
void ProcNodeResetWeels(void){
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeResetWeels"));
	#endif
};
//=======================================================================================
void ProcNodeResetCompressor(void){
	#ifdef MENUDEBUG
  //Serial.println(__FUNCTION__);
  Serial.println(F("ProcNodeResetCompressor"));
	#endif
};
//=======================================================================================
void ProcNodeHardFOnly(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeHardFOnly"));
	#endif
	
	g_data_manager_p->SetHardWare(OnlyFirstWeels);
	
};
//=======================================================================================
void ProcNodeHardLOnly(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeHardLOnly"));
	#endif
	
	g_data_manager_p->SetHardWare(OnlyLastWeels);
	
};
//=======================================================================================
void ProcNodeHardLF(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeHardLF"));
	#endif
	
	g_data_manager_p->SetHardWare(AllWeels);
	
};
//=======================================================================================
void ProcNodeHardCompressorYes(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeHardCompressorYes"));
	#endif
	
	g_data_manager_p->SetHardWare(YesCompressor);
	
};
//=======================================================================================
void ProcNodeHardCompressorNo(void){ // ready
	#ifdef MENUDEBUG
	//Serial.println(__FUNCTION__);
	Serial.println(F("ProcNodeHardCompressorNo"));
	#endif
	
	g_data_manager_p->SetHardWare(NoCompressor);
	
};
//=======================================================================================
