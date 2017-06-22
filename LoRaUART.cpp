/**
	@file
	Arduino library for communication to LoRa Module via UART 
*/
/*
	LoRaUART.cpp - Arduino library for communication to LoRa module via UART.

	Library:: LoRaUART

	SoftwareSerail.h must be included with this library while using it in arduino program
*/

/* _____PROJECT INCLUDES_____________________________________________________ */
#include "LoRaUART.h"

/* General Note: For every request, return of 1 by the function corresponds to successful request
									return of -1 corresponds to invalid parameters sent
									return of -2 corresponds to AT command error

*/

LoRaUART::LoRaUART(int rxPin, int txPin)
{
	altSerial = new SoftwareSerial(rxPin,txPin);
	altSerial->begin(9600);
}

int LoRaUART::initLoRa()
{

	char charArray[] = "$CMD,00,01\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;

	while(altSerial->available()>0)
	{	
		_incomingByte = (char)altSerial->read();
		response += _incomingByte;
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
	
		responseStatus=strtol(q,NULL,16);
	
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
			default: return 1000; break;
		}	
	}
}	

int LoRaUART::activateLoRa()
{
	char charArray[] ="$CMD,00,03\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		

	String response = "";
	char _incomingByte;
	
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;


	if(response.substring(0,4) == "$RES")
	{
		first = response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
		
		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}		
	}
}

int LoRaUART::deactivateLoRa()
{
	char charArray[] ="$CMD,00,02\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		

	String response = "";
	char _incomingByte;
	
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}		
	}
}

int LoRaUART::restoreDefault()
{ 
	char charArray[] = "$CMD,00,00\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

long LoRaUART::getBaudRate()
{
	char charArray[] = "$CMD,00,04\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _getbaud;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_getbaud = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: switch(_getbaud)
					{
						case 0 : return 4800; break;
						case 1 : return 9600; break;
						case 2 : return 19200; break;
						case 3 : return 57600; break;
						case 4 : return 115200; break;
					}
					break;	
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}

}

int LoRaUART::setBaudRate(uint32_t baudrate)
{

	char charArray[16] = "$CMD,01,04,";

	switch(baudrate)
	{
		case 4800 :   charArray[11] = '0';
					  charArray[12] = '0'; break;
		case 9600 :   charArray[11] = '0';
					  charArray[12] = '1'; break;
		case 19200 :  charArray[11] = '0';
					  charArray[12] = '2'; break;
		case 57600 :  charArray[11] = '0';
					  charArray[12] = '3'; break;
		case 115200 : charArray[11] = '0';
					  charArray[12] = '4'; break;
		default: 	  charArray[11] = '0';
					  charArray[12] = '1'; break;
	}	
	charArray[13] = '\r';
	charArray[14] = '\n';
	charArray[15] = '\0';
	altSerial->write(charArray);
		
	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}		
	}
}

/* The getDeviceEUI method will give the device EUI to the integer array passed as an argument. To get the 
	values in hexadecimal format, it has to be done explicitly in the program */

int LoRaUART::getDeviceEUI(uint8_t* deviceEUI)
{
	char charArray[] = "$CMD,00,05\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char value[3];
	int first,second,third;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		for(int j = third, a=0; response.charAt(j)!='\r'; j++)
		{
			if(response.charAt(j)==',')
			{
				value[0]=response.charAt(j+1);
				value[1]=response.charAt(j+2);
				value[2]='\0';
				*(deviceEUI+a) = strtol(value,NULL,16);
				a++;
			}
		}
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}		
	}
}

int LoRaUART::setDeviceEUI(uint8_t* deviceEUI)
{
	char charArray[37] = "$CMD,01,05,";
	charArray[34]='\r';
	charArray[35]='\n';
	charArray[36]='\0';
	
	String EUI;
	for(int i=1,j=i+10; i<=8; i++,j+=3)
	{
		EUI= String(*deviceEUI, HEX);
		if(i!=8)
		{
			if(*deviceEUI<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = EUI.charAt(0);
				charArray[j+2] = ','; 
			}
			else
			{	
				charArray[j] = EUI.charAt(0);
				charArray[j+1] = EUI.charAt(1);
				charArray[j+2] = ',';
			}	
		}
		else
		{
			if(*deviceEUI<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = EUI.charAt(0);
			}
			else
			{	
				charArray[j] = EUI.charAt(0);
				charArray[j+1] = EUI.charAt(1);
			}	
		}	
		deviceEUI++;
	}

	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
		responseStatus = strtol(q,NULL,16);
	 	switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}		
	}
}

int LoRaUART::getApplicationEUI(uint8_t* applicationEUI)
{

	char charArray[] = "$CMD,00,06\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char value[3];
	int first,second,third;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		for(int j = third, a=0; response.charAt(j)!='\r'; j++)
		{
			if(response.charAt(j)==',')
			{
				value[0]=response.charAt(j+1);
				value[1]=response.charAt(j+2);
				value[2]='\0';
				*(applicationEUI+a) = strtol(value,NULL,16);
				a++;
			}
		}
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

int LoRaUART::setApplicationEUI(uint8_t* applicationEUI)
{
	char charArray[37] = "$CMD,01,06,";
	charArray[34]='\r';
	charArray[35]='\n';
	charArray[36]='\0';
	
	String EUI;
	for(int i=1,j=i+10; i<=8; i++,j+=3)
	{
		EUI= String(*applicationEUI, HEX);
		if(i!=8)
		{
			if(*applicationEUI<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = EUI.charAt(0);
				charArray[j+2] = ','; 
			}
			else
			{	
				charArray[j] = EUI.charAt(0);
				charArray[j+1] = EUI.charAt(1);
				charArray[j+2] = ',';
			}	
		}
		else
		{
			if(*applicationEUI<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = EUI.charAt(0);
			}
			else
			{	
				charArray[j] = EUI.charAt(0);
				charArray[j+1] = EUI.charAt(1);
			}	
		}	
		applicationEUI++;
	}
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

int LoRaUART::getApplicationKey(uint8_t* _applicationKey)
{
	char charArray[] = "$CMD,00,07\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char value[3];
	int first,second,third;
	uint8_t responseStatus;


	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		for(int j = third, a=0; response.charAt(j)!='\r'; j++)
		{
			if(response.charAt(j)==',')
			{
				value[0]=response.charAt(j+1);
				value[1]=response.charAt(j+2);
				value[2]='\0';
				*(_applicationKey+a) = strtol(value,NULL,16);
				a++;
			}
		}
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

int LoRaUART::setApplicationKey(uint8_t* _applicationKey)
{
	char charArray[61] = "$CMD,01,07,";
	charArray[58]='\r';
	charArray[59]='\n';
	charArray[60]='\0';
	
	String Key;
	for(int i=1,j=i+10; i<=16; i++,j+=3)
	{
		Key= String(*_applicationKey, HEX);
		if(i!=16)
		{
			if(*_applicationKey<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = Key.charAt(0);
				charArray[j+2] = ','; 
			}
			else
			{	
				charArray[j] = Key.charAt(0);
				charArray[j+1] = Key.charAt(1);
				charArray[j+2] = ',';
			}	
		}
		else
		{
			if(*_applicationKey<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = Key.charAt(0);
			}
			else
			{	
				charArray[j] = Key.charAt(0);
				charArray[j+1] = Key.charAt(1);
			}	
		}	
		_applicationKey++;
	}
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
		responseStatus = strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}		
	}
}	

int LoRaUART::getNetworkKey(uint8_t* _networkKey)
{
	char charArray[] = "$CMD,00,08\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char value[3];
	int first,second,third;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		for(int j = third, a=0; response.charAt(j)!='\r'; j++)
		{
			if(response.charAt(j)==',')
			{
				value[0]=response.charAt(j+1);
				value[1]=response.charAt(j+2);
				value[2]='\0';
				*(_networkKey+a) = strtol(value,NULL,16);
				a++;
			}
		}
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

int LoRaUART::setNetworkKey(uint8_t* _networkKey)
{
	char charArray[61] = "$CMD,01,08,";
	charArray[58]='\r';
	charArray[59]='\n';
	charArray[60]='\0';
	
	String Key;
	for(int i=1,j=i+10; i<=16; i++,j+=3)
	{
		Key= String(*_networkKey, HEX);
		if(i!=16)
		{
			if(*_networkKey<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = Key.charAt(0);
				charArray[j+2] = ','; 
			}
			else
			{	
				charArray[j] = Key.charAt(0);
				charArray[j+1] = Key.charAt(1);
				charArray[j+2] = ',';
			}	
		}
		else
		{
			if(*_networkKey<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = Key.charAt(0);
			}
			else
			{	
				charArray[j] = Key.charAt(0);
				charArray[j+1] = Key.charAt(1);
			}	
		}	
		_networkKey++;
	}
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
		responseStatus = strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}	

int LoRaUART::getDeviceAddress(uint8_t* _deviceAddress)
{
	char charArray[] = "$CMD,00,09\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char value[3];
	int first,second,third;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		for(int j = third, a=0; response.charAt(j)!='\r'; j++)
		{
			if(response.charAt(j)==',')
			{
				value[0]=response.charAt(j+1);
				value[1]=response.charAt(j+2);
				value[2]='\0';
				*(_deviceAddress+a) = strtol(value,NULL,16);
				a++;
			}
		}
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}	

int LoRaUART::setDeviceAddress(uint8_t* _deviceAddress)
{
	char charArray[25] = "$CMD,01,09,";
	charArray[22]='\r';
	charArray[23]='\n';
	charArray[24]='\0';
	
	String Address;
	for(int i=1,j=i+10; i<=4; i++,j+=3)
	{
		Address= String(*_deviceAddress, HEX);
		if(i!=4)
		{
			if(*_deviceAddress<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = Address.charAt(0);
				charArray[j+2] = ','; 
			}
			else
			{	
				charArray[j] = Address.charAt(0);
				charArray[j+1] = Address.charAt(1);
				charArray[j+2] = ',';
			}	
		}
		else
		{
			if(*_deviceAddress<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = Address.charAt(0);
			}
			else
			{	
				charArray[j] = Address.charAt(0);
				charArray[j+1] = Address.charAt(1);
			}	
		}	
		_deviceAddress++;
	}
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';
		responseStatus = strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

int LoRaUART::getNetworkConnType()
{
	char charArray[] = "$CMD,00,0A\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _netConnType;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_netConnType = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: switch(_netConnType)						//success
					{
						case 0 : return 0; break;				//Activation By Personalisation
						case 1 : return 1; break;				//Over The Air Activation
					}
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}
}

int LoRaUART::getNetworkID(uint8_t* _networkID)
{
	char charArray[] = "$CMD,00,0B\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}	

	char q[3];
	char value[3];
	int first,second,third;
	uint8_t responseStatus;


	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		for(int j = third, a=0; response.charAt(j)!='\r'; j++)
		{
			if(response.charAt(j)==',')
			{
				value[0]=response.charAt(j+1);
				value[1]=response.charAt(j+2);
				value[2]='\0';
				*(_networkID+a) = strtol(value,NULL,16);
				a++;
			}
		}
		switch(responseStatus)
		{
			case 0: return 1; break;
			case 1: return -1; break;
			case 2: return -2; break;
		}	
	}
}

int LoRaUART::getADRStatus()
{
	char charArray[] = "$CMD,00,0C\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _ADRStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_ADRStatus = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: switch(_ADRStatus)							//success
					{
						case 0 : return 0; break;				//ADR On
						case 1 : return 1; break;				//ADR Off
					}
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}	
}

int LoRaUART::getUplinkAckStatus()
{
	char charArray[] = "$CMD,00,0D\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _uplinkAckStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_uplinkAckStatus = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: switch(_uplinkAckStatus)					//success
					{
						case 0 : return 0; break;				//Uplink Acknowledgement On
						case 1 : return 1; break;				//Uplink Acknowledgement Off
					}
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}		
}

int LoRaUART::getDataConfirmationRetries()
{
	char charArray[] = "$CMD,00,0E\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _dataConfirmRetries;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_dataConfirmRetries = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: return _dataConfirmRetries;					//Data Confirmation Retries Value
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}	
}

int LoRaUART::getDataRate()
{
	char charArray[] = "$CMD,00,0F\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}	

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _defaultDataRate;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_defaultDataRate = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: return _defaultDataRate;					//Default data Rate
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}
}

int LoRaUART::getPowerSavingStatus()
{
	char charArray[] = "$CMD,00,10\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _powSaveStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_powSaveStatus = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: switch(_powSaveStatus)						//success
					{
						case 0 : return 0; break;				//Power Saving Mode On
						case 1 : return 1; break;				//Power Saving Mode Off
					}
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}	
}

int LoRaUART::getClassSelection()
{
	char charArray[] = "$CMD,00,11\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}	

	char q[3];
	char b[3];
	int first,second,third;
	uint8_t responseStatus;
	uint8_t _classSelection;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		third = response.indexOf(',',second+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		b[0]= response.charAt(third+1);
		b[1]= response.charAt(third+2);
		b[2]= '\0';

		responseStatus=strtol(q,NULL,16);
		_classSelection = strtol(b,NULL,16);

		switch(responseStatus)
		{
			case 0: switch(_classSelection)						//success
					{
						case 0 : return 0; break;				//Class C
						case 1 : return 1; break;				//Class A
					}
					break;	
			case 1: return -1; break;							//invalid parameter
			case 2: return -2; break;							//AT command error
		}	
	}
}

int LoRaUART::saveConfigToEEPROM()
{
	char charArray[] = "$CMD,00,12\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}
		
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}		

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;				//success
			case 1: return -1; break;				//invalid parameter
			case 2: return -2; break;				//AT command error
		}	
	}
}

int LoRaUART::retrieveConfigFromEEPROM()
{
	char charArray[] = "$CMD,00,13\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}		

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);

		switch(responseStatus)
		{
			case 0: return 1; break;				//success
			case 1: return -1; break;				//invalid parameter
			case 2: return -2; break;				//AT command error
		}	
	}
}

int LoRaUART::moduleTest()
{
	char charArray[] = "$CMD,00,FF\r\n";
	altSerial->write(charArray);

	unsigned long t= millis();

	while(millis()-t<respWaitTime){}   					// Time required for response to load into serial 

	while(!altSerial->available())
	{
		if(millis()-t >1000)
			return -3;
	}		
	
	String response = "";
	char _incomingByte;
	while(altSerial->available()>0)
	{
		_incomingByte = altSerial->read();
		response += _incomingByte;
		delay(charReadDelay);
	}

	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,4) == "$RES")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);
		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;				//success
			case 1: return -1; break;				//invalid parameter
			case 2: return -2; break;				//AT command error
		}	
	}
}

/* This function sends a uplink to the server with the data as provided in the packet.
 	*/
int LoRaUART::sendUplink(int portnum, int datalength, uint8_t* data)
{
	int arraylength = (2*datalength)+(datalength-1)+12;
	char charArray[120] = "$UP,";
	charArray[arraylength-2]='\r';
	charArray[arraylength-1]='\n';
	charArray[arraylength]='\0';

	String temp = String(portnum, HEX);
	if(portnum<=15)
	{
		charArray[4]= '0';
		charArray[5] = temp.charAt(0);
		charArray[6] = ','; 
	}
	else
	{	
		charArray[4] = temp.charAt(0);
		charArray[5] = temp.charAt(1);
		charArray[6] = ',';
	}

	temp = String(datalength, HEX);
	if(datalength<=15)
	{
		charArray[7]= '0';
		charArray[8] = temp.charAt(0);
		charArray[9] = ','; 
	}
	else
	{	
		charArray[7] = temp.charAt(0);
		charArray[8] = temp.charAt(1);
		charArray[9] = ',';
	}
	
	for(int i=1,j=i+9; i<=datalength; i++,j+=3)
	{
		temp = String(*data, HEX);
		if(i!=datalength)
		{
			if(*data<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = temp.charAt(0);
				charArray[j+2] = ','; 
			}
			else
			{	
				charArray[j] = temp.charAt(0);
				charArray[j+1] = temp.charAt(1);
				charArray[j+2] = ',';
			}	
		}
		else
		{
			if(*data<=15)
			{
				charArray[j]= '0';
				charArray[j+1] = temp.charAt(0);
			}
			else
			{	
				charArray[j] = temp.charAt(0);
				charArray[j+1] = temp.charAt(1);
			}	
		}	
		data++;
	}
	altSerial->flush();
	altSerial->write(charArray);

	unsigned long t= millis();
	bool uplinkResp = false;

	while(millis()-t<respWaitTime);  					// Time required for response to load into serial 

	t=millis();	

	// while(!altSerial->available())
	// {
	// 	delay(10);
	// 	if(millis()-t >5000)
	// 		return -3;
	// }		
	
	String response = "";
	char _incomingByte;

	while(millis()-t<5000)
	{
		while(altSerial->available()>0)
		{
			uplinkResp=true;
			_incomingByte = altSerial->read();
			response += _incomingByte;
			delay(charReadDelay);
		}
		if(uplinkResp)
			break;
	}
	if(uplinkResp==false)	
		return -3;
	char q[3];
	int first,second;
	uint8_t responseStatus;

	if(response.substring(0,6) == "$UP,00")
	{
		first=response.indexOf(',');
		second = response.indexOf(',',first+1);

		q[0]=response.charAt(second+1);
		q[1]=response.charAt(second+2);
		q[2]='\0';

		responseStatus=strtol(q,NULL,16);
		switch(responseStatus)
		{
			case 0: return 1; break;				//successfully uplink sent
			case 1: return -1; break;				//failure
		}	
	}
	else
		{Serial.println(1000);
		return 1000;}
}

/*	For calling checkDownlink function, the arguments  must be passed as
		checkDownlink(&port,&datalength,data)
	where data is an array of max size 50 
*/	

int LoRaUART::checkDownlink(uint8_t* port, uint8_t* dataLen, uint8_t* downData)
{
	String response="";
	char _incomingByte;

	//while(!altSerial->available());

	if(altSerial->available()>0)
	{
		while(altSerial->available()>0)
		{	
			_incomingByte = altSerial->read();
			response += _incomingByte;
		}	
	}
	else
		return -3;

	Serial.println("resp");
	Serial.println(response);
	int downSubstring = response.indexOf("$DOWN");
	char charArray[100];
	int index = 0;
	int i = downSubstring;
	for(; response.charAt(i)!='\n';i++,index++)
	{	
		*(charArray+index) = response.charAt(i);
	}	
	*(charArray+index) = response.charAt(i);
	index++;
	*(charArray+index) ='\0';
	String downresp = String(charArray);

	int first,second,third;
	char value[3];

	if(downresp.substring(0,5) == "$DOWN")
	{
		first=downresp.indexOf(',');
		second = downresp.indexOf(',',first+1);
		third = downresp.indexOf(',',second+1);

		value[0]=downresp.charAt(first+1);
		value[1]=downresp.charAt(first+2);
		value[2]='\0';
		*port = strtol(value,NULL,16);

		value[0]=downresp.charAt(second+1);
		value[1]=downresp.charAt(second+2);
		value[2]='\0';
		*dataLen = strtol(value,NULL,16);

		for(int j = third, a=0; downresp.charAt(j)!='\r'; j++)
		{
			if(downresp.charAt(j)==',')
			{	
				value[0]=downresp.charAt(j+1);
				value[1]=downresp.charAt(j+2);
				value[2]='\0';
				*(downData+a) = strtol(value,NULL,16);
				a++;
			}
		}
		return 1;
	}
	else
		return 0;
}