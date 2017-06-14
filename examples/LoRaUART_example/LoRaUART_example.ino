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

void setup()
{
  //set baud rate 9600 for communicating on USB serial
  Serial.begin(9600);
  
}

/* For every request, return of 1 by the function corresponds to successful request
                      return of -1 corresponds to invalid parameters sent
                      return of -2 corresponds to AT command error
                      
  The device address, network Key, application key, etc should be given in an array of 
  data type String with with data in hexadecimal value.
  For eg String deviceAddress = {"70","00","0C","43"};                      
*/

String deviceAddress[] = {"70","00","0C","43"};
String networkKey[] = {"D4","89","A4","95","6A","B7","84","58","DF","8F","AF","16","02","6C","22","E4"};
String applicationKey[] = {"E8","5B","6F","EB","9F","EB","88","AE","A8","47","73","32","EC","9D","EA","84"};
String uplinkData[] = {"00","00","00","00","03","16"};
String uplinkPort = "05";
String uplinkDataLength = "06";
int devAddrLength = 4;
int AppKeyLength = 16;
int netKeyLength = 16;


void loop()
{
  Serial.println("Testing LoRa module by sending a test command");
  switch(LoraModule.moduleTest())
  {
   case  1 : Serial.println("LoRa Module successfully tested");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  }

  Serial.println("Loading Default values to the various attributes of the module");
  switch(LoraModule.restoreDefault())
  {
   case  1 : Serial.println("Default values loaded successfully");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  }

  Serial.println("Set Device Address");
  switch(LoraModule.setDeviceAddress(deviceAddress, devAddrLength))
  {
   case  1 : Serial.println("Device Address set successfully");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  }

  Serial.println("Set Network Key");
  switch(LoraModule.setNetworkKey(networkKey, netKeyLength))
  {
   case  1 : Serial.println("Network Key Set successfully");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  }

  Serial.println("Set Application Key");
  switch(LoraModule.setApplicationKey(deviceAddress, devAddrLength))
  {
   case  1 : Serial.println("Application Key set successfully");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  } 

  Serial.println("Initialising LoRa module");
  switch(LoraModule.initLoRa())
  {
   case  1 : Serial.println("Module initialised successfully");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  }

  Serial.println("Activating LoRa module");
  switch(LoraModule.activateLoRa())
  {
   case  1 : Serial.println("Module activated successfully");
   case -1 : Serial.println("Invalid Parameters provided");
   case -2 : Serial.println("AT command error");
  }

/* The format of sendUplink method is : int sendUplink(String uplinkPort, String uplinkDataLength, String* uplinkData) 
   The data types of the arguments to it are all of String class i.e. the portnum, datalength, and 
   data should be a string object with values in hexadecimal equivalent.

   For example- if length of data is 10, then variable datalength should be given as String datalength = "0A"
*/

  Serial.println("Sending an Uplink request");
  switch(LoraModule.sendUplink(uplinkPort,uplinkDataLength, uplinkData))
  {
   case  1 : Serial.println("Uplink sent successfully");
   case -1 : Serial.println("Uplink failed");
  }

/* The checkDownlink method has been commented but it can be used as per user's choice simply by uncommenting
  it and setting the correct parameters
   
  Additionally, declare an array downlinkData globally with max size the data to be received
  i.e. String downlinkData[50];  
*/

// It can be uncommented from next line

/*   
  Serial.println("Checking Downlink");  

  if(module1.checkDownlink(&port,&datalength,downlinkData)==1)
  {
    Serial.println("Port number");
    Serial.println(port);
    Serial.println("Length of the data");
    Serial.println(datalength.toInt());
    Serial.println("Data received");

    for(int i=0; i<datalength.toInt(); i++)
    Serial.println(*(downlinkData+i));
   }
  else
    Serial.println("no downlink");
*/  
}
