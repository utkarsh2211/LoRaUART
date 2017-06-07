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
	_ATcmd = ATcmdInitLoRa;
	_RWmode = read;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n"; 
}	

void LoRaUART::activateLoRa()
{
	_ATcmd = ATcmdActivateLoRa;
	_RWmode = read;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::deactivateLoRa()
{
 	_ATcmd = ATcmdDeactivateLoRa;
 	_RWmode = read;
 	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::restoreDefault()
{
	_RWmode = read;
	_ATcmd = ATcmdRestoreDefault;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::getBaudRate()
{
	_RWmode = read;
	_ATcmd = ATcmdBaudRate;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::setBaudRate(uint32_t baudrate)
{
	_RWmode = write;
	_ATcmd = ATcmdBaudRate;

	switch(baudrate)
	{
		case 4800 : _baudrate = 0x00; break;
		case 9600 : _baudrate = 0x01; break;
		case 19200 : _baudrate = 0x02; break;
		case 57600 : _baudrate = 0x03; break;
		case 115200 : _baudrate = 0x04; break;
		default: _baudrate = 0x01;
	};
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + ',' + _baudrate + "\r\n";
}
