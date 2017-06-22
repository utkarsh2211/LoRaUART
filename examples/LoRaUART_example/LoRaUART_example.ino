/* Both SoftwareSerial.h and LoRaUART.h libraries should be included for the program to run successfully 
  
   The circuit:
   RX is digital pin 10 (connect to TX of other device)
   TX is digital pin 11 (connect to RX of other device)

   Here in the example code pin 10 and 11 are defined to be Rx and Tx for arduino but these can be configured to any other
   digital pins on the development board provided they support software serial communication  
 */

#include <SoftwareSerial.h>
#include <LoRaUART.h>

LoRaUART LoraModule(10,11); // Rx, Tx

uint8_t deviceAddress[] = {0x70,0x00,0xD0,0x50};
uint8_t networkKey[] = { /* 0xD4,0x89,0xA4,0x95,0x6A,0xB7,0x84,0x58,0xDF,0x8F,0xAF,0x16,0x02,0x6C,0x22,0xE4*/ 0xCF,0xC9,0x22,0xD2,0x34,0xA6,0x87,0x39,0x34,0x6F,0x0A,0xB7,0x12,0x99,0x42,0x75};
uint8_t applicationKey[] = {/*0xE8,0x5B,0x6F,0xEB,0x9F,0xEB,0x88,0xAE,0xA8,0x47,0x73,0x32,0xEC,0x9D,0xEA,0x84*/ 0xBC,0x3B,0x40,0xFE,0x0E,0x55,0xDF,0x9B,0x06,0x8B,0x79,0x91,0x96,0x00,0x4C,0x56};
uint8_t uplinkData[] = {0x00,0x00,0x00,0x00,0x03,0x16};
uint8_t uplinkPort = 5;
uint8_t uplinkDataLength = 6;
uint8_t port;
uint8_t datalength;
uint8_t downlinkData[50];
bool t=true;
bool x= true;

void setup()
{
  //set baud rate 9600 for communicating on USB serial
  Serial.begin(9600);

// The LoRa module can be tested by uncommenting the moduleTest() method provided below  
/*
  Serial.println("Testing LoRa module by sending a test command");
  switch(LoraModule.moduleTest())
  {
   case  1 : Serial.println("LoRa Module successfully tested");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(1000);
*/

  Serial.println("Loading Default values to the various attributes of the module");
  switch(LoraModule.restoreDefault())
  {
   case  1 : Serial.println("Default values loaded successfully");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
   default : Serial.println("Error");break;
  }
  delay(1000);
  
  Serial.println("Set Device Address");
  switch(LoraModule.setDeviceAddress(deviceAddress))
  {
   case  1 : Serial.println("Device Address set successfully");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(1000);

  Serial.println("Set Network Key");
  switch(LoraModule.setNetworkKey(networkKey))
  {
   case  1 : Serial.println("Network Key Set successfully");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(1000);

  Serial.println("Set Application Key");
  switch(LoraModule.setApplicationKey(applicationKey))
  {
   case  1 : Serial.println("Application Key set successfully");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(1000); 

  Serial.println("Initialising LoRa module");
  switch(LoraModule.initLoRa())
  {
   case  1 : Serial.println("Module initialised successfully");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(1000);

  Serial.println("Activating LoRa module");
  switch(LoraModule.activateLoRa())
  {
   case  1 : Serial.println("Module activated successfully");break;
   case -1 : Serial.println("Invalid Parameters provided");break;
   case -2 : Serial.println("AT command error");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(10000); 
}

/* For every request, return of 1 by the function corresponds to successful request
                      return of -1 corresponds to invalid parameters sent
                      return of -2 corresponds to AT command error
                      return of -3 corresponds to request timeout
                      
  The device address, network Key, application key, etc should be given in an array of 
  data type uint8_t with data in hexadecimal value.
  For eg uint8_t deviceAddress = {0x70,0x00,0x0C,0x43};                      
*/

void loop()
{
/* The format of sendUplink method is : int sendUplink(uint8_t uplinkPort, uint8_t uplinkDataLength, uint8_t* uplinkData) 
   The data types of the arguments to it are all of uint8_t type i.e. the portnum, datalength, and 
   data should be integers with values in hexadecimal equivalent.

   Delay of at least 30 seconds should be given after calling sendUplink method 
*/
  Serial.println("Sending an Uplink request");
  switch(LoraModule.sendUplink(uplinkPort,uplinkDataLength, uplinkData))
  {
   case  1 : Serial.println("Uplink sent successfully");break;
   case -1 : Serial.println("Uplink failed");break;
   case -3 : Serial.println("Request timeout");break;
  }
  delay(30000);

/* The checkDownlink method has been commented but it can be used as per user's choice simply by uncommenting
  it and setting the correct parameters
   
  Additionally, declare an array downlinkData globally with max size the data to be received
  i.e. uint8_t downlinkData[50];  
*/

// It can be uncommented from next line
/*
   
  Serial.println("Checking Downlink");  

  if(LoraModule.checkDownlink(&port,&datalength,downlinkData)==1)
  {
    Serial.println("Port number");
    Serial.println(port);
    Serial.println("Length of the data");
    Serial.println(datalength);
    Serial.println("Data received");

    for(int i=0; i<datalength; i++)
    Serial.println(*(downlinkData+i)); 
  }
  else
    Serial.println("No downlink");  
*/        
}

