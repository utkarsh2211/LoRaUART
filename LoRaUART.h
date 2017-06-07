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
class LoRaUART
{
  public:
  	LoRaUART();

  	void initLoRa();
  	void activateLoRa();
  	void deactivateLoRa();
  	void restoreDefault();



  	static const string CmdType = "$CMD";
  	char* requestCmd;
  	static const uint8_t read = 0x00;
  	static const uint8_t write = 0x01;
  	uint8_t* ATcmd ;
  	uint8_t baudrate;



  	 Stream* _serial;                                             ///< reference to serial port object






#endif	