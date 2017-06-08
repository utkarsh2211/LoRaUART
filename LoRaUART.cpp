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

void LoRaUART::getDeviceEUI()
{
	_RWmode = read;
	_ATcmd = ATcmdDeviceEUI;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";

}

void LoRaUART::setDeviceEUI(uint8_t* deviceEUI, int size)
{
	_RWmode = write;
	_ATcmd = ATcmdDeviceEUI;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + ",";
	for(int i=1; i<=size; i++)
	{
		if(i!=size)
			requestCmd = requestCmd + *deviceEUI + ',';
		else
			requestCmd = requestCmd + *deviceEUI;
		deviceEUI++;
	}
	requestCmd= requestCmd + "\r\n";
}

void LoRaUART::getApplicationEUI()
{
	_RWmode = read;
	_ATcmd = ATcmdApplicationEUI;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::setApplicationEUI(uint8_t* applicationEUI, int size)
{
	_RWmode = write;
	_ATcmd = ATcmdApplicationEUI;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + ",";
	for(int i=1; i<=size; i++)
	{
		if(i!=size)
			requestCmd = requestCmd + *applicationEUI + ',';
		else
			requestCmd = requestCmd + *applicationEUI;
		applicationEUI++;
	}
	requestCmd = requestCmd + "\r\n";
}

void LoRaUART::getApplicationKey()
{
	_RWmode = read;
	_ATcmd = ATcmdApplicationKey;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}	

void LoRaUART::getNetworkKey()
{
	_RWmode = read;
	_ATcmd = ATcmdNetworkKey;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}	

void LoRaUART::getDeviceAddress()
{
	_RWmode = read;
	_ATcmd = ATcmdDeviceAddr;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}	

void LoRaUART::getNetworkConnType()
{
	_RWmode = read;
	_ATcmd = ATcmdNetworkConnType;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::getNetworkID()
{
	_RWmode = read;
	_ATcmd = ATcmdNetworkID;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getADRStatus()
{
	_RWmode = read;
	_ATcmd = ATcmdADRStatus;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getUplinkAckStatus()
{
	_RWmode = read;
	_ATcmd = ATcmdUplinkAckStatus;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getDataConfirmationRetries()
{
	_RWmode = read;
	_ATcmd = ATcmdDataConfirmRetries;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getDataRate()
{
	_RWmode = read;
	_ATcmd = ATcmdDefaultDataRate;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getPowerSavingStatus()
{
	_RWmode = read;
	_ATcmd = ATcmdPowerSaveMode;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getClassSelection()
{
	_RWmode = read;
	_ATcmd = ATcmdClassSelection;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::moduleTest()
{
	_RWmode = read;
	_ATcmd = ATcmdModuleTestCmd;
	requestCmd= requestCmd + CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}