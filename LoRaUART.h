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
  	int getDeviceEUI(String*);
  	int setDeviceEUI(String*, int);
  	int getApplicationEUI(String*);
  	int setApplicationEUI(String*, int);
  	int getApplicationKey(String*);
  	int getNetworkKey(String*);
  	int getDeviceAddress(String*);
  	int setDeviceAddress(String*, int);
  	int getNetworkConnType();
  	int getNetworkID(String*);
  	int getADRStatus();
  	int getUplinkAckStatus();
  	int getDataConfirmationRetries();
  	int getDataRate();
  	int getPowerSavingStatus();
  	int getClassSelection();
  	int saveConfigToEEPROM();
  	int retrieveConfigFromEEPROM();
  	int moduleTest();

  	int sendUplink(String, String, String*);
  	int checkDownlink(String*, String*, String*);

	String requestCmd = "";
	SoftwareSerial *altSerial;


  private:

  	String requestAPI = "$CMD";
  	String uplinkAPI = "$UP";
  	String downlinkAPI = "$DOWN";
  	String readCmd = "00";
  	String writeCmd = "01";
  	String ATcmdRestoreDefault        = "00";
  	String ATcmdInitLoRa              = "01";
  	String ATcmdDeactivateLoRa        = "02";
  	String ATcmdActivateLoRa          = "03";
  	String ATcmdBaudRate              = "04";
  	String ATcmdDeviceEUI             = "05";
  	String ATcmdApplicationEUI        = "06";
  	String ATcmdApplicationKey        = "07";
  	String ATcmdNetworkKey            = "08";
  	String ATcmdDeviceAddr            = "09";
  	String ATcmdNetworkConnType       = "0A";
  	String ATcmdNetworkID             = "0B";
	String ATcmdADRStatus             = "0C";
	String ATcmdUplinkAckStatus       = "0D";
	String ATcmdDataConfirmRetries    = "0E";
	String ATcmdDefaultDataRate       = "0F";
	String ATcmdPowerSaveMode         = "10";
	String ATcmdClassSelection        = "11";
	String ATcmdSaveConfigEEPROM      = "12";
	String ATcmdRetrieveConfigEEPROM  = "13";		
	String ATcmdModuleTestCmd         = "FF";


	String _RWmode;
	String _ATcmd ;
	String _CmdType;
	String response = "";
	String crlf= "\r\n";
	String _baudrate;
	//String _downlinkData[maxLenDownlinkdata];

	uint8_t _getbaud;
	String _portnum;
	uint8_t _dataConfirmRetries;
	uint8_t _defaultDataRate;


	uint16_t _netConnType;
	uint16_t _ADRStatus;
	uint16_t _uplinkAckStatus;
	uint16_t _powSaveStatus;
	uint16_t _classSelection;

	uint32_t baudrate;
	int _datalength;
	char _incomingByte;
	bool _timeout;
	int _rxPin;
	int _txPin;
	int respWaitTime=100;

};

#endif	