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

    /* initLoRa() method initialises the  LoRa module */
  	int initLoRa();

    /* activateLoRa() method activates the LoRa module for communication with the server */
  	int activateLoRa();

    /* deactivateLoRa() method deactivates the LoRa module */
  	int deactivateLoRa();

    /* restoreDefault() method loads default values to the various parameters of the LoRa module
       for example, default baudrate, data rate, device EUI, network ID, etc */
  	int restoreDefault();

    /* getBaudRate() method returns the current set baudrate for the communication between module
       and server. The variable receiving the return value should be of 'long' data type
       e.g. long baudrate = LoRaModule.getBaudRate() */  
  	long getBaudRate();

    /* setBaudRate() method sets the baudrate for communication according to the argument passed in the
       method. The argument should be a 32 bit integer.
       Standard baud rates are : 4800, 9600, 19200, 57600, 115200
       e.g. LoRaModule.setBaudRate(115200); */
  	int setBaudRate(uint32_t);

    /* getDeviceEUI() method will assign the device EUI to the array passed as an argument to the method.
       The array should be of 8 bit integer i.e. uint8_t
       e.g. uint8_t deviceEUI[8];
            LoRaModule.getDeviceEUI(deviceEUI); */ 
  	int getDeviceEUI(uint8_t*);

    /* setDeviceEUI() method sets the device EUI which is passed as an array to the argument of the method
       The array should be of datatype uint8_t with the individul elements of the address in
       hexadecimal format.
       e.g. uint8_t deviceEUI[] = {0x70,0x00,0xD0,0x50,0x45,0x85,0xC1,0xA4};
            LoRaModule.setDeviceEUI(deviceEUI); */
   	int setDeviceEUI(uint8_t*);

    /* getApplicationEUI() method will assign the Application EUI to the array passed as an argument to the method.
       The array should be of 8 bit integer i.e. uint8_t
       e.g. uint8_t applicationEUI[8];
            LoRaModule.getApplicationEUI(applicationEUI); */
  	int getApplicationEUI(uint8_t*);

    /* setApplicationEUI() method sets the application EUI which is passed as an array to the argument of the method
       The array should be of datatype uint8_t with the individul elements of the address in
       hexadecimal format.
       e.g. uint8_t applicationEUI[] = {0x70,0x00,0xD0,0x50,0x45,0x85,0xC1,0xA4};
            LoRaModule.setApplicationEUI(applicationEUI); */
  	int setApplicationEUI(uint8_t*);

    /* getApplicationKey() method will assign the Application Key to the array passed as an argument to the method.
       The array should be of 8 bit integer i.e. uint8_t
       e.g. uint8_t applicationKey[16];
            LoRaModule.getApplicationKey(applicationKey); */
  	int getApplicationKey(uint8_t*);

    /* setApplicationKey() method sets the application Key which is passed as an array to the argument of the method
       The array should be of datatype uint8_t with the individul elements of the address in
       hexadecimal format.
       e.g. uint8_t applicationKey[] = {0xAA,0x36,0x40,0xAB,0x0E,0x47,0xDF,0x96,0x06,0x55,0x79,0xA4,0x96,0x16,0x4C,0x56};
            LoRaModule.setApplicationKey(applicationKey); */
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