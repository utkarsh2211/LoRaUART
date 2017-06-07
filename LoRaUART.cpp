/**
	@file
	Arduino library for communication to LoRa Module via UART 
*/
/*
	LoRaUART.cpp - Arduino library for communication to LoRa module via UART.

	Library:: LoRaUART
*/

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "LoRaUART.h"

 	

void LoRaUART::initLoRa()
{
requestCmd= requestCmd + CmdType + ',' + read + ',' + ATcmd + ',' + "\r\n"; 
}	

