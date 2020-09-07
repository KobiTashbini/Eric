#include <AbsMouse.h>
int data;
int last_analogX = 0;
int last_analogY = 0;

int buttonPin = 13;
int buttonPin2 = 2;
int buttonPin3 = 3;
int buttonPin4 = 4;

bool oneShotButtonState = false;
int oneShotButton = 8;
int mulShotButton = 9;
int celenoidOutput = 10;
bool isCelenoidOutputOn = false;
const long oneShotinterval = 10;

unsigned long startOneShotMillis = 0;

bool isMouseShouldMove = false;
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
  pinMode(buttonPin2, INPUT_PULLUP);
  pinMode(buttonPin3, INPUT_PULLUP);
  pinMode(buttonPin4, INPUT_PULLUP);

  pinMode(oneShotButton, INPUT);
  pinMode(mulShotButton, INPUT);
  pinMode(celenoidOutput, OUTPUT);


  AbsMouse.report();
}

void loop() {

  if ( digitalRead(oneShotButton) == HIGH && !isCelenoidOutputOn && !oneShotButtonState) {
    Serial.print("igitalRead(oneShotButton) : ");

    digitalWrite(celenoidOutput, HIGH);
    Serial.println("digitalWrite(celenoidOutput, HIGH)");
    isCelenoidOutputOn = true;
    oneShotButtonState = true;
    startOneShotMillis = millis();
  }
  else if (digitalRead(oneShotButton) == LOW)
  {
    oneShotButtonState = false;

  }


    if ( digitalRead(mulShotButton) == HIGH && !isCelenoidOutputOn ) {
    Serial.print("igitalRead(mulShotButton) : ");

    digitalWrite(celenoidOutput, HIGH);
    Serial.println("digitalWrite(celenoidOutput, HIGH)");
    isCelenoidOutputOn = true;
    oneShotButtonState = true;
    startOneShotMillis = millis();
  }
  else if (digitalRead(oneShotButton) == LOW)
  {
    oneShotButtonState = false;

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
      Serial.println(xBorderLimitA);
    } else if (data == 'x') {
      xBorderLimitA = xBorderLimitA - 1;

      //Serial.println("xBorderLimit : ");
      // Serial.println(xBorderLimit);
      Serial.println(xBorderLimitA);

    }

    if (data == 'W') {
      xBorderLimitB = xBorderLimitB + 1;


      Serial.println(xBorderLimitB);
    } else if (data == 'w') {
      xBorderLimitB = xBorderLimitB - 1;

      Serial.println(xBorderLimitB);

    }

    else if (data == 'Y') {
      yBorderLimitA = yBorderLimitA - 1;

      //Serial.println("yBorderLimitA : ");
      //Serial.println(yBorderLimitA);
      Serial.println(yBorderLimitA);

    } else if (data == 'y') {
      yBorderLimitA = yBorderLimitA + 1;

      //   Serial.println("yBorderLimitA : ");
      //Serial.println(yBorderLimitA);
      Serial.println(yBorderLimitA);

    }
    else if (data == 'Z') {
      yBorderLimitB = yBorderLimitB + 1;

      // Serial.println("yBorderLimitB : ");
      // Serial.println(yBorderLimitB);
      Serial.println(yBorderLimitB);

    } else if (data == 'z') {
      yBorderLimitB = yBorderLimitB - 1;

      //  Serial.println("yBorderLimitB : ");
      //     Serial.println(yBorderLimitB);
      Serial.println(yBorderLimitB);

    }
    else if (data == 'H') {

      yScaleValue = yScaleValue + 1;

      //Serial.println("yScaleValue : ");
      //      Serial.println(yScaleValue);
      Serial.println(yScaleValue);
    } else if (data == 'h') {

      yScaleValue = yScaleValue - 1;

      // Serial.println("yScaleValue : ");
      //      //   Serial.println(yScaleValue);
      Serial.println(yScaleValue);
    }
    else if (data == 'W') {
      xScaleValue = xScaleValue + 1;

      //Serial.println("xScaleValue : ");
      //   Serial.println(xScaleValue);
      Serial.println(xScaleValue);
      //
    } else if (data == 'w') {
      xScaleValue = xScaleValue - 1;

      //   Serial.println("xScaleValue : ");
      //   Serial.println(xScaleValue);
      Serial.println(xScaleValue);

    }




    else if (data == 'R') {
      xBorderLimitA = 857;
      xBorderLimitB = 219;
      yBorderLimitA = 893;
      yBorderLimitB = 195;
      xScaleValue = 218;
      yScaleValue = 209;
      Serial.println("RestoreSuccess");
    }

    else
    {
      Serial.println('M');
    }
  }








  //Serial.println("isMouseShouldMove - ");
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
  //Serial.println("currentAnalogX - ");
  //Serial.println(currentAnalogX);
  if (isMouseShouldMove ==  true && (last_analogX != currentAnalogX || last_analogY != currentAnalogY ))
  {
    last_analogX = currentAnalogX;
    last_analogY = currentAnalogY;

    XAxis_ = 1023 - analogRead(A0);
    YAxis_ = 1023 - analogRead(A1);
    // Serial.println("XAxis_ - ");
    //Serial.println(XAxis_);
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
      //   Serial.println("buttonPin2 clicked and not press MOUSE_LEFT");
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
      //   Serial.println("buttonState2 releaseed");
    }

    // AbsMouse.release(MOUSE_LEFT );
  }

  if (digitalRead(buttonPin3) == HIGH )
  {
    if (!buttonState3)
    {
      buttonState3 = true;
      //  Serial.println("buttonPin3 clicked and not press MOUSE_RIGHT");
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
      //  Serial.println("buttonState3 releaseed");
    }

    // AbsMouse.release(MOUSE_LEFT );
  }
  ///////////////////////////


  if (digitalRead(buttonPin4) == HIGH )
  {
    if (!buttonState4)
    {
      buttonState4 = true;
      //  Serial.println("buttonPin4 clicked and not press MOUSE_RIGHT");
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
      //  Serial.println("buttonState4 releaseed");
    }

  }
  ///////////////////////////
  unsigned long currentMillis = millis();
  if ((currentMillis - startOneShotMillis >= oneShotinterval) && isCelenoidOutputOn)
  {
    digitalWrite(celenoidOutput, LOW);
    isCelenoidOutputOn = false;
    Serial.println("digitalWrite(celenoidOutput, LOW)");
  }

  delay(50);
}
//////////////////////
