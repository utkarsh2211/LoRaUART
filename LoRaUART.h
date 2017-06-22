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

    /* getNetworkKey() method will assign the Network Key to the array passed as an argument to the method.
       The array should be of 8 bit integer i.e. uint8_t
       e.g. uint8_t networkKey[16];
            LoRaModule.getNetworkKey(networkKey); */
  	int getNetworkKey(uint8_t*);

    /* setNetworkKey() method sets the Network Key which is passed as an array to the argument of the method
       The array should be of datatype uint8_t with the individul elements of the address in
       hexadecimal format.
       e.g. uint8_t networkKey[] = {0x95,0x75,0xA4,0xDD,0x02,0xA6,0x87,0x39,0xCA,0x6F,0x0A,0xB7,0x44,0x99,0x42,0x75};
            LoRaModule.setNetworkKey(networkKey); */
  	int setNetworkKey(uint8_t*);

    /* getDeviceAddress() method will assign the Device Address to the array passed as an argument to the method.
       The array should be of 8 bit integer i.e. uint8_t
       e.g. uint8_t deviceAddress[4];
            LoRaModule.getDeviceAddress(deviceAddress); */
  	int getDeviceAddress(uint8_t*);

    /* setDeviceAddress() method sets the Device Address which is passed as an array to the argument of the method
       The array should be of datatype uint8_t with the individul elements of the address in
       hexadecimal format.
       e.g. uint8_t deviceAddress[] = {0x70,0x00,0xD0,0x50};
            LoRaModule.setDeviceAddress(deviceAddress); */
  	int setDeviceAddress(uint8_t*);

    /* getNetworkConnType() method gives the type  of connection i.e. Over the air activation or Activation by Personalisation
       e.g. int networkConn = LoRaModule.getNetworkConnType(); */
  	int getNetworkConnType();

    /* getNetworkID() method will assign the Network ID to the array passed as an argument to the method.
       The array should be of 8 bit integer i.e. uint8_t
       e.g. uint8_t networkID[4];
            LoRaModule.getNetworkID(networkID); */
  	int getNetworkID(uint8_t*);

    /* getADRStatus() method returns whether the ADR is ON or OFF where 0 means ON and 1  means OFF
       e.g int ADRStatus = LoRaModule.getADRStatus(); */
  	int getADRStatus();

    /* getUplinkAckStatus() method checks whether receiving of an acknowledgement is active after sending an uplink to the server 
       0 means ON while 1 means OFF
       e.g. int uplinkAck = LoRaModule.getUplinkAckStatus(); */
  	int getUplinkAckStatus();

    /* getDataConfirmationRetries() method gives the number of retries which the module makes for the confirmation of data
       e.g. int dataReties = LoRaModule.getDataConfirmationRetries(); */
  	int getDataConfirmationRetries();

    /* getDataRate() method returns the data rate
       e.g. int dataRate = LoRaModule.getDataRate(); */
  	int getDataRate();

    /* getPowerSavingStatus() method returns whether the power saving mode on the device is active or not
       0 means ON while 1 means OFF 
       e.g int powerSaveMode = LoRaModule.getPowerSavingStatus(); */
  	int getPowerSavingStatus();

    /* getClassSelection() returns whether the device is programmed to be of A type or C type
       0 means C type while 1 means A type 
       e.g. int classtype = LoRaModule.getClassSelection(); */ 
  	int getClassSelection();

    /* saveConfigToEEPROM() method saves the module configurations to EEPROM */
  	int saveConfigToEEPROM();

    /* retrieveConfigFromEEPROM method reads configurations from the EEPROM and loads it to the module */ 
  	int retrieveConfigFromEEPROM();

    /* moduleTest() tests the module for a response */
  	int moduleTest();

    /* sendUplink() sends an uplink to the server with the port number, datalength and data (an array) as argument
       to the method. Port number and datalength are of integer datatype while data is an array of uint8_t datatype
       e.g. uint8_t uplinkData[] = {0x00,0x00,0x00,0x00,0x03,0x16};
            int uplinkPort = 5;
            int uplinkDataLength = 6; 
            LoraModule.sendUplink(uplinkPort,uplinkDataLength, uplinkData); */
  	int sendUplink(int, int, uint8_t*);

    /* checkDownlink() method checks for a downlink received in the serial buffer. If yes, it assigns the port number,
       datalength and data received in the frame to the arguments passed, where downlinkData is an array.
       All three arguments are of datatype uint8_t, where do 
  	   e.g. uint8_t port;
            uint8_t datalength;
            uint8_t downlinkData[50];
            LoraModule.checkDownlink(&port,&datalength,downlinkData); */
    int checkDownlink(uint8_t*, uint8_t*, uint8_t*);

  private:
    SoftwareSerial *altSerial;
    int respWaitTime = 100;
    int charReadDelay = 50;

};

#endif	