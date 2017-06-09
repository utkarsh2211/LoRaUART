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

  	uint32_t initLoRa();
  	uint32_t activateLoRa();
  	uint32_t deactivateLoRa();
  	uint32_t restoreDefault();
  	uint32_t getBaudRate();
  	uint32_t setBaudRate(uint32_t);
  	uint32_t getDeviceEUI(uint8_t*);
  	uint32_t setDeviceEUI(uint8_t*, int);
  	uint32_t getApplicationEUI(uint8_t*);
  	uint32_t setApplicationEUI(uint8_t*, int);
  	uint32_t getApplicationKey(uint8_t*);
  	uint32_t getNetworkKey(uint8_t*);
  	uint32_t getDeviceAddress(uint8_t*);
  	uint32_t getNetworkConnType();
  	uint32_t getNetworkID(uint8_t*);
  	uint32_t getADRStatus();
  	uint32_t getUplinkAckStatus();
  	uint32_t getDataConfirmationRetries();
  	uint32_t getDataRate();
  	uint32_t getPowerSavingStatus();
  	uint32_t getClassSelection();
  	uint32_t saveConfigToEEPROM();
  	uint32_t retrieveConfigFromEEPROM();
  	uint32_t moduleTest();

  	uint32_t sendUplink(uint8_t, int, uint8_t*);

	String requestCmd = "";

  private:

  	String requestAPI = "$CMD";
  	String uplinkAPI = "$UP";
  	String downlinkAPI = "$DOWN";
  	static const uint8_t readCmd = 0x00;
  	static const uint8_t writeCmd = 0x01;
  	static const uint8_t ATcmdRestoreDefault     = 0x00;
  	static const uint8_t ATcmdInitLoRa              = 0x01;
  	static const uint8_t ATcmdDeactivateLoRa        = 0x02;
  	static const uint8_t ATcmdActivateLoRa          = 0x03;
  	static const uint8_t ATcmdBaudRate              = 0x04;
  	static const uint8_t ATcmdDeviceEUI             = 0x05;
  	static const uint8_t ATcmdApplicationEUI        = 0x06;
  	static const uint8_t ATcmdApplicationKey        = 0x07;
  	static const uint8_t ATcmdNetworkKey            = 0x08;
  	static const uint8_t ATcmdDeviceAddr            = 0x09;
  	static const uint8_t ATcmdNetworkConnType       = 0x0A;
  	static const uint8_t ATcmdNetworkID             = 0x0B;
	static const uint8_t ATcmdADRStatus             = 0x0C;
	static const uint8_t ATcmdUplinkAckStatus       = 0x0D;
	static const uint8_t ATcmdDataConfirmRetries    = 0x0E;
	static const uint8_t ATcmdDefaultDataRate       = 0x0F;
	static const uint8_t ATcmdPowerSaveMode         = 0x10;
	static const uint8_t ATcmdClassSelection        = 0x11;
	static const uint8_t ATcmdSaveConfigEEPROM      = 0x12;
	static const uint8_t ATcmdRetrieveConfigEEPROM  = 0x13;		
	static const uint8_t ATcmdModuleTestCmd         = 0xFF;


	uint8_t _RWmode;
	uint8_t _ATcmd ;
	uint8_t _baudrate;
	uint8_t _portnum;
	uint8_t _dataConfirmRetries;
	uint8_t _defaultDataRate;


	uint16_t _netConnType;
	uint16_t _ADRStatus;
	uint16_t _uplinkAckStatus;
	uint16_t _powSaveStatus;
	uint16_t _classSelection;

	uint32_t baudrate;
	int _datalength;
	String _CmdType;
	String response = "";
	char _incomingByte;
	bool _timeout;

};


/*  	 Stream* _serial;                                             ///< reference to serial port object
*/
#endif	