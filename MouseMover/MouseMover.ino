#include <AbsMouse.h>
int data;
int last_analogX = 0;
int last_analogY = 0;

int buttonPin = 13;

int buttonPin3 = 3;
int buttonPin4 = 4;

int buttonPin2 = 2;
long shotCounter = 0;
bool mulShotButtonState = false;
bool oneShotButtonState = false;
//int oneShotButton = 9;
int oneShotButton = 2;
int mulShotButton = 8;
int celenoidOutput = 10;
bool isCelenoidOutputOn_M = false;
bool isCelenoidOutputOn_O = false;

const long oneShotinterval = 2;


unsigned long startShotMillis = 0;
unsigned long lastMulShot = 0;


bool isMouseShouldMove = true;
bool buttonState = false;
bool buttonState2 = false;
bool buttonState3 = false;
bool buttonState4 = false;
float XAxis_ = 0;
float YAxis_ = 0;

int xBorderLimitA = 857;
int xBorderLimitB = 219;
int yBorderLimitA = 893;
int yBorderLimitB = 195;

int xScaleValue = 218;
int yScaleValue = 209;

void setup() {
  Serial.begin(9600);
  AbsMouse.init(1024, 720);
  pinMode(buttonPin, INPUT);
  
 // pinMode(buttonPin2, INPUT_PULLUP);
 // digitalWrite(buttonPin2,HIGH);
  
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  pinMode(oneShotButton, INPUT);
  //digitalWrite(oneShotButton,HIGH);
  pinMode(mulShotButton, INPUT);
  // digitalWrite(mulShotButton,HIGH);
  pinMode(celenoidOutput, OUTPUT);


  AbsMouse.report();
}

void loop() {
//Serial.println(digitalRead(oneShotButton));
    
 
  if ( digitalRead(oneShotButton) == HIGH && !isCelenoidOutputOn_O && !oneShotButtonState) {
    oneShotButtonState = true;
  //  Serial.print("!digitalRead(oneShotButton) == HIGH");

    digitalWrite(celenoidOutput, HIGH);
    Serial.print("digitalWrite(celenoidOutput, HIGH);");
   // AbsMouse.press(MOUSE_LEFT );
     isCelenoidOutputOn_O = true;
   // Serial.println("digitalWrite(celenoidOutput, HIGH)");
    
    // digitalWrite(celenoidOutput, LOW);
   // Serial.println("digitalWrite(celenoidOutput, LOW)");
    //  isCelenoidOutputOn = false;
    
   
    startShotMillis = millis();
    // Serial.println( shotCounter);
     shotCounter++;
   
  }
  else if (digitalRead(oneShotButton) == LOW)
  {
     // Serial.print("!digitalRead(oneShotButton) == LOW");
    
    oneShotButtonState = false;
  //  AbsMouse.release(MOUSE_LEFT );

  }


    if ( digitalRead(mulShotButton) == HIGH && !isCelenoidOutputOn_M  ) {
   // Serial.print("igitalRead(mulShotButton) : ");

    digitalWrite(celenoidOutput, HIGH);
   Serial.println("digitalWrite(celenoidOutput, HIGH)");
    isCelenoidOutputOn_M = true;
    mulShotButtonState = true;
    lastMulShot = millis();

     Serial.println( shotCounter);
     shotCounter++;
  }
  else if (digitalRead(mulShotButton) == LOW)
  {
    mulShotButtonState = false;

  }

  //Serial.println("SSSSSSS");
  // Serial.write("A");
  if (Serial.available()) {
    data = Serial.read();
    //Serial.println("dataReaded" );
    //Serial.println(data);
    // Serial.write("Z");
    if (data == 'X') {
      xBorderLimitA = xBorderLimitA + 1;

      //Serial.println("xBorderLimit : ");
      // Serial.println(xBorderLimit);
      // Serial.println("A");
      //  Serial.write("A");
    //  Serial.println(xBorderLimitA);
    } else if (data == 'x') {
      xBorderLimitA = xBorderLimitA - 1;

      //Serial.println("xBorderLimit : ");
      // Serial.println(xBorderLimit);
   //   Serial.println(xBorderLimitA);

    }

    if (data == 'W') {
      xBorderLimitB = xBorderLimitB + 1;


    //  Serial.println(xBorderLimitB);
    } else if (data == 'w') {
      xBorderLimitB = xBorderLimitB - 1;

   //   Serial.println(xBorderLimitB);

    }

    else if (data == 'Y') {
      yBorderLimitA = yBorderLimitA - 1;

      //Serial.println("yBorderLimitA : ");
      //Serial.println(yBorderLimitA);
    //  Serial.println(yBorderLimitA);

    } else if (data == 'y') {
      yBorderLimitA = yBorderLimitA + 1;

      //   Serial.println("yBorderLimitA : ");
      //Serial.println(yBorderLimitA);
 //     Serial.println(yBorderLimitA);

    }
    else if (data == 'Z') {
      yBorderLimitB = yBorderLimitB + 1;

      // Serial.println("yBorderLimitB : ");
      // Serial.println(yBorderLimitB);
    //  Serial.println(yBorderLimitB);

    } else if (data == 'z') {
      yBorderLimitB = yBorderLimitB - 1;

      //  Serial.println("yBorderLimitB : ");
      //     Serial.println(yBorderLimitB);
   //   Serial.println(yBorderLimitB);

    }
    else if (data == 'H') {

      yScaleValue = yScaleValue + 1;

      //Serial.println("yScaleValue : ");
      //      Serial.println(yScaleValue);
  //    Serial.println(yScaleValue);
    } else if (data == 'h') {

      yScaleValue = yScaleValue - 1;

      // Serial.println("yScaleValue : ");
      //      //   Serial.println(yScaleValue);
     // Serial.println(yScaleValue);
    }
    else if (data == 'W') {
      xScaleValue = xScaleValue + 1;

      //Serial.println("xScaleValue : ");
      //   Serial.println(xScaleValue);
    //  Serial.println(xScaleValue);
      //
    } else if (data == 'w') {
      xScaleValue = xScaleValue - 1;

      //   Serial.println("xScaleValue : ");
      //   Serial.println(xScaleValue);
    //  Serial.println(xScaleValue);

    }




    else if (data == 'R') {
      xBorderLimitA = 857;
      xBorderLimitB = 219;
      yBorderLimitA = 893;
      yBorderLimitB = 195;
      xScaleValue = 218;
      yScaleValue = 209;
    //  Serial.println("RestoreSuccess");
    }

    else
    {
    //  Serial.println('M');
    }
  }








 // Serial.println("isMouseShouldMove - ");
 // Serial.println(isMouseShouldMove);
  
  if (digitalRead(buttonPin) == HIGH )
  {
    isMouseShouldMove = !isMouseShouldMove;
    // Serial.println("isMouseShouldMove - ");
    // Serial.println(isMouseShouldMove);
    if (!isMouseShouldMove)
    {
      AbsMouse.move(500, 500 );
      //  Serial.print("STOPPPPPPPPPPPP - ");
      //delay(20000000000);
    }
    delay(200);

  }
  int currentAnalogX = analogRead(A0);
  int currentAnalogY = analogRead(A1);
 // Serial.println("currentAnalogX - ");
 // Serial.println(currentAnalogX);
  // Serial.println("currentAnalogY - ");
//  Serial.println(currentAnalogY);
  if (isMouseShouldMove ==  true && (last_analogX != currentAnalogX || last_analogY != currentAnalogY ))
  {
    last_analogX = currentAnalogX;
    last_analogY = currentAnalogY;

    XAxis_ = 1023 - analogRead(A0);
    YAxis_ = 1023 - analogRead(A1);
     //Serial.println("XAxis_ - ");
   // Serial.println(XAxis_);
    if (XAxis_ > xBorderLimitA)
    {
      XAxis_ = xBorderLimitA;
    }
    if (XAxis_ < xBorderLimitB)
    {
      XAxis_ = xBorderLimitB;
    }
    if (YAxis_ > yBorderLimitA)
    {
      YAxis_ = yBorderLimitA;
    }
    else if (YAxis_ < yBorderLimitB)
    {
      YAxis_ = yBorderLimitB;
    }
    // int nYAxis_ = ((YAxis_ - yScaleValue) / (yBorderLimitA - yScaleValue)) * 720;
    // int nXAxis_ = ((XAxis_ - xScaleValue) / ((xBorderLimit - 1) - xScaleValue)) * 1023;
    int nYAxis_ = ((YAxis_ - yScaleValue) / (893 - yScaleValue)) * 720;
    int nXAxis_ = ((XAxis_ - xScaleValue) / ((856) - xScaleValue)) * 1023;


    AbsMouse.move(nXAxis_, nYAxis_ );




    // Serial.println("nXAxis_");
    // Serial.println(nXAxis_);
    // Serial.print("XAxis_");
    // Serial.println(XAxis_);

    // Serial.print("nYAxis_");
    //  Serial.println(nYAxis_);
    //  Serial.print("YAxis_");
    //  Serial.println(YAxis_);
    //  Serial.print("isMouseShouldMove-");
    // Serial.println("WIRKING ABS");
  }
  else
  {
    //Serial.println("NOT WORKING ABS");
  }




  ////////////////////////
  if (digitalRead(buttonPin2) == HIGH )
  {
    if (!buttonState2)
    {
      buttonState2 = true;
        Serial.println("buttonPin2 clicked and  press MOUSE_LEFT");
      //   Serial.println(buttonState2);
      AbsMouse.press(MOUSE_LEFT );
    }



  }
  else
  {
    if (buttonState2)
    {
      buttonState2 = false;
      AbsMouse.release(MOUSE_LEFT);
        Serial.println("buttonState2 releaseed");
    }

    // AbsMouse.release(MOUSE_LEFT );
  }

  if (digitalRead(buttonPin3) == HIGH )
  {
    if (!buttonState3)
    {
      buttonState3 = true;
       Serial.println("buttonPin3 clicked and  press MOUSE_RIGHT");
      //  Serial.println(buttonState3);
      AbsMouse.press(MOUSE_RIGHT );
    }



  }
  else
  {
    if (buttonState3)
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
    if (!buttonState4)
    {
      buttonState4 = true;
        Serial.println("buttonPin4 clicked and  press MOUSE_MIDDLE");
      // Serial.println(buttonState4);
      AbsMouse.press(MOUSE_MIDDLE );
    }



  }
  else
  {
    if (buttonState4)
    {
      buttonState4 = false;
      AbsMouse.release(MOUSE_MIDDLE);
       Serial.println("buttonState4 releaseed");
    }

  }

unsigned long currentMillis = millis();
if((currentMillis - lastMulShot >= oneShotinterval) && isCelenoidOutputOn_M)
{
  digitalWrite(celenoidOutput, LOW);
  isCelenoidOutputOn_M = false;

}

  
  ///////////////////////////
  
  if ((currentMillis - startShotMillis >= oneShotinterval) && isCelenoidOutputOn_O)
  {
    
    digitalWrite(celenoidOutput, LOW);
    isCelenoidOutputOn_O = false;
   Serial.println("digitalWrite(celenoidOutput, LOW)");

   Serial.print("currentMillis:");
  Serial.println(currentMillis);
   Serial.print("startShotMillis:");
  Serial.println(startShotMillis);
   Serial.print("oneShotinterval:");
   Serial.println(oneShotinterval);
  }
  else
  {
//Serial.print("ERROR:");
//Serial.print("currentMillis:");
  // Serial.println(currentMillis);
  // Serial.print("startShotMillis:");
 //  Serial.println(startShotMillis);
 //  Serial.print("oneShotinterval:");
  // Serial.println(oneShotinterval);
 ///  Serial.print("isCelenoidOutputOn:");
  // Serial.println(isCelenoidOutputOn);
//Serial.println("(currentMillis - startShotMillis >= oneShotinterval) && isCelenoidOutputOn");
    
    //Serial.println((currentMillis - startShotMillis >= oneShotinterval) && isCelenoidOutputOn);
    
  }

  delay(50);
}
//////////////////////
