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
	_CmdType = requestAPI;
	_ATcmd = ATcmdInitLoRa;
	_RWmode = readCmd;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n"; 
}	

void LoRaUART::activateLoRa()
{
	_CmdType = requestAPI;
	_ATcmd = ATcmdActivateLoRa;
	_RWmode = readCmd;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::deactivateLoRa()
{
	_CmdType = requestAPI;
 	_ATcmd = ATcmdDeactivateLoRa;
 	_RWmode = readCmd;
 	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::restoreDefault()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdRestoreDefault;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::getBaudRate()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdBaudRate;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::setBaudRate(uint32_t baudrate)
{
	_CmdType = requestAPI;
	_RWmode = writeCmd;
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
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + ',' + _baudrate + "\r\n";
}

void LoRaUART::getDeviceEUI()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdDeviceEUI;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";

}

void LoRaUART::setDeviceEUI(uint8_t* deviceEUI, int EUIlength)
{
	_CmdType = requestAPI;
	_RWmode = writeCmd;
	_ATcmd = ATcmdDeviceEUI;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + ",";
	for(int i=1; i<=EUIlength; i++)
	{
		if(i!=EUIlength)
			requestCmd = requestCmd + *deviceEUI + ',';
		else
			requestCmd = requestCmd + *deviceEUI;
		deviceEUI++;
	}
	requestCmd= requestCmd + "\r\n";
}

void LoRaUART::getApplicationEUI()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdApplicationEUI;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::setApplicationEUI(uint8_t* applicationEUI, int EUIlength)
{
	_CmdType = requestAPI;
	_RWmode = writeCmd;
	_ATcmd = ATcmdApplicationEUI;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + ",";
	for(int i=1; i<=EUIlength; i++)
	{
		if(i!=EUIlength)
			requestCmd = requestCmd + *applicationEUI + ',';
		else
			requestCmd = requestCmd + *applicationEUI;
		applicationEUI++;
	}
	requestCmd = requestCmd + "\r\n";
}

void LoRaUART::getApplicationKey()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdApplicationKey;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}	

void LoRaUART::getNetworkKey()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdNetworkKey;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}	

void LoRaUART::getDeviceAddress()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdDeviceAddr;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}	

void LoRaUART::getNetworkConnType()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdNetworkConnType;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";
}

void LoRaUART::getNetworkID()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdNetworkID;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getADRStatus()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdADRStatus;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getUplinkAckStatus()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdUplinkAckStatus;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getDataConfirmationRetries()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdDataConfirmRetries;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getDataRate()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdDefaultDataRate;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getPowerSavingStatus()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdPowerSaveMode;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::getClassSelection()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdClassSelection;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::moduleTest()
{
	_CmdType = requestAPI;
	_RWmode = readCmd;
	_ATcmd = ATcmdModuleTestCmd;
	requestCmd= requestCmd + _CmdType + ',' + _RWmode + ',' + _ATcmd + "\r\n";	
}

void LoRaUART::sendUplink(uint8_t portnum, int datalength, uint8_t* data)
{
	_CmdType = uplinkAPI;
	_portnum = portnum;
	_datalength = datalength;
	requestCmd= requestCmd + _CmdType + ',' + _portnum + ',' + _datalength + ",";
	for(int i=1; i<=_datalength; i++)
	{
		if(i!=_datalength)
			requestCmd = requestCmd + *data + ',';
		else
			requestCmd = requestCmd + *data;
		data++;
	}
	requestCmd = requestCmd + "\r\n";

}

