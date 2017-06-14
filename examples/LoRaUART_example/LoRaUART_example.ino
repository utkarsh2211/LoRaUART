#include <SoftwareSerial.h>
#include <LoRaUART.h>

LoRaUART module1(10,11);
bool t = true;
String eui[50];//= {"00","04","09","00"};
String port;// = "05";
String datalength;// = "04";
int x;

void setup() {
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:

/*Serial.println("Initialising LoRa");
int test = module1.initLoRa();
Serial.println(test);
/*int t=millis();
while(t-millis()<200)
{
}*/

while(t){
Serial.println("Downlink");  

if(module1.checkDownlink(&port,&datalength,eui)==1)
{
  Serial.println("Port num");
  Serial.println(port);
  Serial.println("datalength");
  Serial.println(datalength);
  Serial.println(datalength.toInt());
  Serial.println("data");
  x=datalength.toInt();
  for(int n=0;n<x;n++)
    Serial.println(*(eui+n));
   t=false;
}
else
  Serial.println("no downlink");
  
/*
for(int i=0; i<=3;i++)
Serial.println(eui[i]);*/
}
/*t=millis();
while(t-millis()<200)
{
  
}*/
/*Serial.println("Test Module");
Serial.println(module1.moduleTest());
Serial.println("getbaud");
Serial.println(module1.getBaudRate());
*/
}
