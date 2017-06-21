/**
	@file
	Arduino library for communication to LoRa Module via UART 
*/
/*
	LoRaUART.cpp - Arduino library for communication to LoRa module via UART.

	Library:: LoRaUART

	SoftwareSerail.h must be included with this library while using it in arduino program
*/

#ifndef LoRaUART_h
#define LoRaUART_h

/* _____CLASS DEFINITIONS____________________________________________________ */
/**
Arduino class library for communicating with LoRa module via UART.
*/
//

#include "WString.h"
#include "Arduino.h"
#include "SoftwareSerial.h"

#define maxLenDownlinkdata 50

class LoRaUART
{
  public:
  	LoRaUART(int,int);

  	int initLoRa();
  	int activateLoRa();
  	int deactivateLoRa();
  	int restoreDefault();
  	long getBaudRate();
  	int setBaudRate(uint32_t);
  	int getDeviceEUI(uint8_t*);
  	int setDeviceEUI(uint8_t*);
  	int getApplicationEUI(uint8_t*);
  	int setApplicationEUI(uint8_t*);
  	int getApplicationKey(uint8_t*);
  	int setApplicationKey(uint8_t*);
  	int getNetworkKey(uint8_t*);
  	int setNetworkKey(uint8_t*);
  	int getDeviceAddress(uint8_t*);
  	int setDeviceAddress(uint8_t*);
  	int getNetworkConnType();
  	int getNetworkID(uint8_t*);
  	int getADRStatus();
  	int getUplinkAckStatus();
  	int getDataConfirmationRetries();
  	int getDataRate();
  	int getPowerSavingStatus();
  	int getClassSelection();
  	int saveConfigToEEPROM();
  	int retrieveConfigFromEEPROM();
  	int moduleTest();

  	int sendUplink(int, int, uint8_t*);
  	int checkDownlink(uint8_t*, uint8_t*, uint8_t*);

  private:
    SoftwareSerial *altSerial;
  	int respWaitTime = 100;
    int charReadDelay = 50;

};

#endif	