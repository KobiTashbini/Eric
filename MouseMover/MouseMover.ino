#include <AbsMouse.h>

int last_nYAxis_ = 0;
int last_nXAxis_ = 0;

int buttonPin = 13;
int buttonPin2 = 2;
int buttonPin3 = 3;
int buttonPin4 = 4;
bool isMouseShouldMove = false;
bool buttonState = false;
bool buttonState2 = false;
bool buttonState3 = false;
bool buttonState4 = false;
float XAxis_ = 0;
float YAxis_ = 0;


void setup() {
  Serial.begin(9600);
  AbsMouse.init(1024, 720);
  pinMode(buttonPin, INPUT);
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);
  AbsMouse.report();
}

void loop() {

  Serial.println("isMouseShouldMove - ");
  if (digitalRead(buttonPin) == HIGH )
  {
    isMouseShouldMove = !isMouseShouldMove;
    Serial.println("isMouseShouldMove - ");
    Serial.println(isMouseShouldMove);
    if (!isMouseShouldMove)
    {
      AbsMouse.move(500, 500 );
      //  Serial.print("STOPPPPPPPPPPPP - ");
      //delay(20000000000);
    }
    delay(200);

  }
  if (isMouseShouldMove ==  true)
  {
    XAxis_ = 1023 - analogRead(A0);
    YAxis_ = 1023 - analogRead(A1);
    if(XAxis_ > 857)
    {
      XAxis_ = 857;
    }
    if(YAxis_ > 893)
    {
      YAxis_ = 893;
    }
    else if(YAxis_ < 195)
    {
      YAxis_ = 195;
    }
    int nYAxis_ = ((YAxis_ - 209) / (893 - 209)) * 720;
    int nXAxis_ = ((XAxis_ - 218) / (856 - 218)) * 1023;

    if(last_nYAxis_ != nYAxis_ && last_nXAxis_ != nXAxis_)
    {
      AbsMouse.move(nXAxis_, nYAxis_ );
      last_nYAxis_ = nYAxis_;
      last_nXAxis_ = nXAxis_;
    }
    

     Serial.println("nXAxis_");
     Serial.println(nXAxis_);
     Serial.print("XAxis_");
     Serial.println(XAxis_);

    Serial.print("nYAxis_");
     Serial.println(nYAxis_);
     Serial.print("YAxis_");
     Serial.println(YAxis_);
     Serial.print("isMouseShouldMove-");
    Serial.println("WIRKING ABS");
  }
  else
  {
    Serial.println("NOT WORKING ABS");
  }


  //for (int i = 0; i <= 1024; i++) {


  //buttonState = digitalRead(buttonPin);



  //if (buttonState == HIGH) {

  //AbsMouse.move(i, 200);
  // Serial.println(i);

  //}
  //delay(10);
  //}


  // for (int i = 0; i <= 720; i++) {


  // buttonState = digitalRead(buttonPin);

  //if (buttonState == HIGH) {

  // AbsMouse.move(200, i);
  // Serial.println(i);

  //}


  // }

  // do some stuff
  // AbsMouse.move(500, 200);
  // AbsMouse.press(MOUSE_LEFT);
  // AbsMouse.release(MOUSE_LEFT);
  // do some other stuff




  ////////////////////////
 if (digitalRead(buttonPin2) == HIGH )
  {
    if(!buttonState2)
    {
      buttonState2 = true;
    Serial.println("buttonPin2 clicked and not press MOUSE_LEFT");
    Serial.println(buttonState2);
    AbsMouse.press(MOUSE_LEFT );
    }
   
    
    
  }
  else
  {
    if(buttonState2)
    {
      buttonState2 = false;
      AbsMouse.release(MOUSE_LEFT);
      Serial.println("buttonState2 releaseed");
    }
    
    // AbsMouse.release(MOUSE_LEFT );
  }
  ///////////////////////////

  ///////////////////////////


  ////////////////////////////////////////
   ////////////////////////
 if (digitalRead(buttonPin3) == HIGH )
  {
    if(!buttonState3)
    {
      buttonState3 = true;
    Serial.println("buttonPin3 clicked and not press MOUSE_RIGHT");
    Serial.println(buttonState3);
    AbsMouse.press(MOUSE_RIGHT );
    }
   
    
    
  }
  else
  {
    if(buttonState3)
    {
      buttonState3 = false;
      AbsMouse.release(MOUSE_RIGHT);
      Serial.println("buttonState3 releaseed");
    }
    
    // AbsMouse.release(MOUSE_LEFT );
  }
  ///////////////////////////


 if (digitalRead(buttonPin4) == HIGH )
  {
    if(!buttonState4)
    {
      buttonState4 = true;
    Serial.println("buttonPin4 clicked and not press MOUSE_RIGHT");
    Serial.println(buttonState4);
    AbsMouse.press(MOUSE_MIDDLE );
    }
   
    
    
  }
  else
  {
    if(buttonState4)
    {
      buttonState4 = false;
      AbsMouse.release(MOUSE_MIDDLE);
      Serial.println("buttonState4 releaseed");
    }
    
    // AbsMouse.release(MOUSE_LEFT );
  }
  ///////////////////////////

  delay(50);
}
//////////////////////
