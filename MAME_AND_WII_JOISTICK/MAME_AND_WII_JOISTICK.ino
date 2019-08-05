

#include <Joystick.h>

Joystick_ Joystick;
enum gunMode {
  MAME, 
  WII,

};
 enum gunMode gunModeState = WII;
int data; 
int XAxis_ = 0;                    
int YAxis_ = 0;
 int incomingValue = 0;
int zAxis_ = 0; 
int RxAxis_ = 0;  
int oRxAxis_ = 0;                 
int RyAxis_ = 0;  
int RzAxis_ = 0;          
int Throttle_ = 0;   
int number = 0;  
//int buttonState2 = 0;   
     int lastState = 0;

const bool initAutoSendState = true; 

void setup()
{
  Serial.begin(9600);
   
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);
  pinMode(6, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  pinMode(9, INPUT_PULLUP);
  pinMode(10, INPUT_PULLUP);
  pinMode(11, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  Joystick.begin();
  }
  // Constant that maps the phyical pin to the joystick button.
const int pinToButtonMap = 2;

// Last state of the button
int lastButtonState[11] = {0,0,0,0,0,0,0,0,0,0,0};
void loop(){

char buffer[] = {' ',' ',' ',' ',' ',' ',' '}; // Receive up to 7 bytes
 if (Serial.available())
 {
   Serial.readBytesUntil('\n', buffer, 7);
  incomingValue = atoi(buffer);


 }

  
//Serial.println("------BEGIN--------");
// 
//zAxis_ = analogRead(A0);  
//zAxis_ = map(zAxis_,0,1023,0,255);
// Joystick.setZAxis(zAxis_);  


  //void setXAxis(int16_t value);
  //void setYAxis(int16_t value);
  //void setZAxis(int16_t value);
  //void setRxAxis(int16_t value);
  //void setRyAxis(int16_t value);
  //void setRzAxis(int16_t value);

//XAxis_ = analogRead(A0);
// XAxis_ = map(XanalogReadAxis_,0,1023,0,1023);
// Joystick.setXAxis(XAxis_);
//
// YAxis_ = analogRead(A1);
// YAxis_ = map(YAxis_,0,1023,0,1023);
// Joystick.setYAxis(YAxis_);


//RxAxis_ = analogRead(A0);
// RxAxis_ = map(RxAxis_,0,1023,0,255);
// Joystick.setRxAxis(RxAxis_);



 RxAxis_ = analogRead(A0);
 RyAxis_ = analogRead(A1);
  
//Serial.println(RxAxis_);

if(gunModeState == MAME)
{
      if(RxAxis_ < 512)
      {
       RxAxis_ = map(RxAxis_,0,512,110,390); 
      //Serial.print("MAP:0-512-");
      //Serial.println(RxAxis_);
      }
      else
      {
      RxAxis_ = map(RxAxis_,513,1023,582,980);
      //Serial.print("MAP:582-1023-");
      //Serial.println(RxAxis_);
      }
       
  
     
      RyAxis_ = map(RyAxis_,0,1023,0,1023);
      if(RyAxis_ < 512)
      {
       RyAxis_ = map(RyAxis_,0,512,0,362); 
      //Serial.print("MAP:0-512-");
      //Serial.println(RyAxis_);
      }
      else
      {
      RyAxis_ = map(RyAxis_,513,1023,570,1023);
      //Serial.print("MAP:582-1023-");
      //Serial.println(RyAxis_);
      }


}
else
{

 RyAxis_ = map(RyAxis_,0,1023,0,1023);
}


//Joystick.setRyAxis(RyAxis_);
    Joystick.setRxAxis(RxAxis_);   
    Joystick.setRyAxis(RyAxis_);

 // Read pin values
  for (int index = 0; index < 11; index++)
  {
    int currentButtonState = !digitalRead(index + pinToButtonMap);
    if (currentButtonState != lastButtonState[index])
    {
      Joystick.setButton(index, currentButtonState);
      lastButtonState[index] = currentButtonState;
    }
  }
 delay(10);
 Serial.println("------BEGIN--------");
//number++;
}// USB 5 AXIS Controller 