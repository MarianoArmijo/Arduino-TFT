// UTouch_Buttons

#include <UTFT.h>
#include <UTouch.h>

// Initialize display

UTFT myGLCD(ITDB24E_8,38,39,40,41);
UTouch  myTouch(7, 6, 5, 4, 3);

// Declare which fonts we will be using
extern uint8_t BigFont[];

int ch1 = 13; // pin of the arduino to connect the channel 1 of the relay

int x, y;

/*************************
**   Custom functions   **
*************************/

void drawButtons()
{
// Draw button OFF
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (10, 10, 60, 60);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 10, 60, 60);
    myGLCD.print("OFF", 11, 30);
    
// Draw button ON
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (70, 10, 120, 60);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (70, 10, 120, 60);
    myGLCD.print("ON", 79, 30);
    
    myGLCD.setBackColor (0, 0, 0);
}

// Draw a red frame while a button is touched
void waitForIt(int x1, int y1, int x2, int y2)
{
  myGLCD.setColor(255, 0, 0);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
  while (myTouch.dataAvailable())
    myTouch.read();
  myGLCD.setColor(255, 255, 255);
  myGLCD.drawRoundRect (x1, y1, x2, y2);
}

/*************************
**  Required functions  **
*************************/

void setup()
{
// Initial setup
  myGLCD.InitLCD();
  myGLCD.clrScr();

  myTouch.InitTouch();
  myTouch.setPrecision(PREC_MEDIUM);

  myGLCD.setFont(BigFont);
  myGLCD.setBackColor(0, 255, 0);
  drawButtons();
  
  pinMode(ch1, OUTPUT);
  
}

void loop() {
  
  while (true) {
    
    if (myTouch.dataAvailable())
    {
      myTouch.read();
      x=myTouch.getX();
      y=myTouch.getY();
      
      if ((y>=10) && (y<=60))  // Upper row
      {
        if ((x>=10) && (x<=60))  // Button: 1
        {
          waitForIt(10, 10, 60, 60);
          digitalWrite(ch1, LOW);
          
          myGLCD.setColor(255, 0, 0);
          myGLCD.print("FAN OFF!", CENTER, 192);
          delay(3000);
          myGLCD.print("          ", CENTER, 192);
        }
        if ((x>=70) && (x<=120))  // Button: 2
        {
          waitForIt(70, 10, 120, 60);
          digitalWrite(ch1, HIGH);

          myGLCD.setColor(255, 0, 0);
          myGLCD.print("FAN ON!", CENTER, 192);
          delay(3000);
           myGLCD.print("         ", CENTER, 192);
        }
      }
    }
  }
}

