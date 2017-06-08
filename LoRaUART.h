/**
	@file
	Arduino library for communication to LoRa Module via UART 
*/
/*
	LoRaUART.cpp - Arduino library for communication to LoRa module via UART.

	Library:: LoRaUART
*/

#ifndef LoRaUART_h
#define LoRaUART_h

/* _____CLASS DEFINITIONS____________________________________________________ */
/**
Arduino class library for communicating with LoRa module via UART.
*/
//
//#include "SoftwareSerial.h"
#include "WString.h"
#include "Arduino.h"

class LoRaUART
{
  public:
  	LoRaUART();

  	void initLoRa();
  	void activateLoRa();
  	void deactivateLoRa();
  	void restoreDefault();
  	uint32_t getBaudRate();
  	void setBaudRate(uint32_t);
  	void getDeviceEUI();
  	void setDeviceEUI(uint8_t*, int);
  	void getApplicationEUI();
  	void setApplicationEUI(uint8_t*, int);
  	void getApplicationKey();
  	void getNetworkKey();
  	void getDeviceAddress();
  	void getNetworkConnType();
  	void getNetworkID();
  	void getADRStatus();
  	void getUplinkAckStatus();
  	void getDataConfirmationRetries();
  	void getDataRate();
  	void getPowerSavingStatus();
  	void getClassSelection();
  	void moduleTest();

  	void sendUplink(uint8_t, int, uint8_t*);

	String requestCmd = "";

  private:

  	static const String requestAPI;
  	static const String uplinkAPI;
  	static const String downlinkAPI;
  	static const uint8_t readCmd = 0x00;
  	static const uint8_t writeCmd = 0x01;
  	static const uint8_t ATcmdRestoreDefault     = 0x00;
  	static const uint8_t ATcmdInitLoRa           = 0x01;
  	static const uint8_t ATcmdDeactivateLoRa     = 0x02;
  	static const uint8_t ATcmdActivateLoRa       = 0x03;
  	static const uint8_t ATcmdBaudRate           = 0x04;
  	static const uint8_t ATcmdDeviceEUI          = 0x05;
  	static const uint8_t ATcmdApplicationEUI     = 0x06;
  	static const uint8_t ATcmdApplicationKey     = 0x07;
  	static const uint8_t ATcmdNetworkKey         = 0x08;
  	static const uint8_t ATcmdDeviceAddr         = 0x09;
  	static const uint8_t ATcmdNetworkConnType    = 0x0A;
  	static const uint8_t ATcmdNetworkID          = 0x0B;
	static const uint8_t ATcmdADRStatus          = 0x0C;
	static const uint8_t ATcmdUplinkAckStatus    = 0x0D;
	static const uint8_t ATcmdDataConfirmRetries = 0x0E;
	static const uint8_t ATcmdDefaultDataRate    = 0x0F;
	static const uint8_t ATcmdPowerSaveMode      = 0x10;
	static const uint8_t ATcmdClassSelection     = 0x11;
	static const uint8_t ATcmdModuleTestCmd      = 0xFF;

	uint8_t _RWmode;
	uint8_t _ATcmd ;
	uint8_t _baudrate;
	uint8_t _portnum;

	uint32_t baudrate;
	int _datalength;
	String _CmdType;
	String response = "";
	char incomingByte;
	bool _timeout;

};
const String LoRaUART::requestAPI = "$CMD";
const String LoRaUART::uplinkAPI = "$UP";
const String LoRaUART::downlinkAPI = "$DOWN";


/*  	 Stream* _serial;                                             ///< reference to serial port object
*/
#endif	