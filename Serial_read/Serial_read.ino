#include <SoftwareSerial.h>

SoftwareSerial mySer(6,5); //RX TX
char buff[8]={0x01,0x03,0x00,0x00,0x00,0x02,0xC4,0x0B}; // array for sending addresses
unsigned char inData ;


void setup(){
//set to the normal baud, mines for the example
   
    Serial.begin(38400); 
   

     mySer.begin(38400);

}//~ end setup

void loop(){
//  mySer.write(buff);
  
    if(Serial.available()>1){
      inData = mySer.read();
      Serial.println(inData);
    }
    else{
      Serial.println("nan");
    }
    
  
}



/*
#include <SoftwareSerial.h>
SoftwareSerial mySerial(2,3);//Define software serial, 3 is TX, 2 is RX

unsigned char data[11]={0};
void setup()
{
 Serial.begin(115200);
 mySerial.begin(9600);
mySerial.print(FA 06 01 FF); //send command to Sensor
}

void loop()
{
  mySerial.print(buff);
  while(1)
  {
    if(mySerial.available()>0)//Determine whether there is data to read on the serial 
    {
      delay(50);
      for(int i=0;i<11;i++)
      {
        data[i]=mySerial.read();
      }
      unsigned char Check=0;
      for(int i=0;i<10;i++)
      {
        Check=Check+data[i];
      }
      Check=~Check+1;
      if(data[10]==Check)
      {
        if(data[3]=='E'&&data[4]=='R'&&data[5]=='R')
        {
          Serial.println("Out of range");
        }
        else
        {
          float distance=0;
          distance=(data[3]-0x30)*100+(data[4]-0x30)*10+(data[5]-0x30)*1+(data[7]-0x30)*0.1+(data[8]-0x30)*0.01+(data[9]-0x30)*0.001;
          Serial.print("Distance = ");
          Serial.print(distance,3);
          Serial.println(" M");
        }
      }
      else
      {
        Serial.println("Invalid Data!");
      }
    }
    delay(20);
  }
}
*/
