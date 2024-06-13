#include<SoftwareSerial.h>
SoftwareSerial ss(4,5);
int ir=2;
int buz=3;
int value;
int data;
void setup() 
{
  Serial.begin(9600);
  ss.begin(9600);
  pinMode(ir,INPUT);
  pinMode(buz,OUTPUT);
  // put your setup code here, to run once:
  digitalWrite(buz,LOW);

}

void loop() 
{
  
  // put your main code here, to run repeatedly:
  while(Serial.available())
  {
    data=Serial.read();
  if(data=='2')
  {
    value=digitalRead(ir);
  delay(200);
  if(value==0)
  {
    Serial.print('A');
    delay(1000);
  }
  else
  {
      Serial.print('B');  
      delay(1000);
  }
    
  }
  else if(data=='0')
  {
    digitalWrite(buz,LOW);
   
  }
  else if(data=='1')
  {
    digitalWrite(buz,HIGH);
    delay(500);
    ss.println("AT");
  delay(1000);
  ss.println("ATE0");
  delay(1000);
  ss.println("AT+CMGF=1");
  delay(1000);
  ss.println("AT+CMGS=\"6303493862\"");
  delay(1000);
  ss.println("INTRUDER DETECTED");
  delay(1000);
  ss.write(26);
  }
  }
}
