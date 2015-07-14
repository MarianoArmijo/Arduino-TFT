// UTouch_Buttons

#include <UTFT.h>
#include <UTouch.h>

// Initialize display

UTFT myGLCD(ITDB24E_8,38,39,40,41);
UTouch  myTouch(7, 6, 5, 4, 3);

// Declare which fonts we will be using
extern uint8_t BigFont[];

int ch1 = 13; // variable who connect servo´s pin

int x, y;

/*************************
**   Custom functions   **
*************************/

// Draw buttons menu
void drawStart()
{
  //Text Menus
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect(100, 10, 220, 50);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (100, 10, 220, 50);
    myGLCD.setColor(0, 0, 255);
    myGLCD.print("MENUS:", CENTER, 22);
    
  // Menu Turn
    myGLCD.setBackColor(0, 255, 0);
    
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (10, 60, 85, 100);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 60, 85, 100);
    myGLCD.print("Turn", 15, 70);

  // Menu Switch
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (95, 60, 200, 100);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (95, 60, 200, 100);
    myGLCD.print("Switch", 100, 70);
    
}

void drawMenuTurn()
{
  // Text SET
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect(10, 10, 305, 50);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 10, 305, 50);
    myGLCD.setColor(0, 0, 255);
    myGLCD.print("Set the velocity", 30, 15);
    myGLCD.print("of the turn:", 30, 30);

  // Button High
    myGLCD.setBackColor(0, 255, 0);
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (10, 60, 85, 100);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 60, 85, 100);
    myGLCD.print("High", 15, 70);

  // Button Low
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (95, 60, 155, 100);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (95, 60, 155, 100);
    myGLCD.print("Low", 100, 70);
    
  // Button access to drawStart()
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (10, 110, 85, 150);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 110, 85, 150);
    myGLCD.print("Home", 15, 120);
    
    myGLCD.setBackColor (0, 0, 0);
  
}

void drawMenuSwitch()
{
  // Text Switch
    myGLCD.setBackColor(0, 0, 0);
    myGLCD.setColor(0, 0, 0);
    myGLCD.fillRoundRect(10, 10, 250, 40);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 10, 250, 40);
    myGLCD.setColor(0, 0, 255);
    myGLCD.print("Switch on/off:", 20, 18);
    
// Draw button OFF
    myGLCD.setBackColor(0, 255, 0);
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (10, 50, 60, 90);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 50, 60, 90);
    myGLCD.print("OFF", 11, 60);
    
// Draw button ON
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (70, 50, 120, 90);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (70, 50, 120, 90);
    myGLCD.print("ON", 79, 60);

  // Button access to drawStart()
    myGLCD.setColor(0, 255, 0);
    myGLCD.fillRoundRect (10, 100, 85, 140);
    myGLCD.setColor(255, 255, 255);
    myGLCD.drawRoundRect (10, 100, 85, 140);
    myGLCD.print("Home", 15, 110);
    
    myGLCD.setBackColor (0, 0, 0);
}

// Draw a red frame while a button is touched
void writeRedFrame(int x1, int y1, int x2, int y2)
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
  
  drawStart();
  
  pinMode(ch1, OUTPUT);
  
}

void loop() {

  while (true){

      if (myTouch.dataAvailable())
      {
      
        myTouch.read();
        x=myTouch.getX();
        y=myTouch.getY();
       
        if ((y>=60) && (y<=100))  
        {
          
          // Button: Menu Turn
          if ((x>=10) && (x<=85))  
          {
            writeRedFrame(10, 60, 85, 100);
            myGLCD.clrScr();
          
            myTouch.setPrecision(PREC_MEDIUM);
          
            myGLCD.setFont(BigFont);
            myGLCD.setBackColor(0, 255, 0);

            drawMenuTurn();
            
                while (true) {
                  
                  if (myTouch.dataAvailable())
                  {
                  
                    myTouch.read();
                    x=myTouch.getX();
                    y=myTouch.getY();

                    if ((y>=60) && (y<=100)) //Fits buttons row
                    {
                      
                      if ((x>=10) && (x<=85))  // Button: Turn High (10, 60, 85, 100)
                      {
                        writeRedFrame(10, 60, 85, 100);
                        // Increase velocity
              
                        myGLCD.setColor(255, 0, 0);
                        myGLCD.print("HIGH VELOCITY!", CENTER, 192);
                        delay(2000);
                        myGLCD.print("               ", CENTER, 192);
                      }
                      if ((x>=95) && (x<=155))  // Button: Turn Low (95, 60, 155, 100)
                      {
                        writeRedFrame(95, 60, 155, 100);
                        // Decrease velocity
              
                        myGLCD.setColor(255, 0, 0);
                        myGLCD.print("LOW VELOCITY!", CENTER, 192);
                        delay(2000);
                        myGLCD.print("              ", CENTER, 192);
                      }
                    }
                    
                   if((y>=110) && (y<=150)) // Second buttons row
                   {
                    if((x>=10) && (x<=85)){ // Button Home (10, 110, 85, 150)
                      
                        writeRedFrame(10, 110, 85, 150);
                        myGLCD.clrScr();

                        myTouch.setPrecision(PREC_MEDIUM);
                      
                        myGLCD.setFont(BigFont);
                        myGLCD.setBackColor(0, 255, 0);
                        
                        drawStart();
                        loop();
                    }
                    }
                  }
                }
            }
          
          // Button: Menu Switch
          if ((x>=95) && (x<=200))  
          {
            writeRedFrame(95, 60, 200, 100);
            
            myGLCD.clrScr();
          
            myTouch.setPrecision(PREC_MEDIUM);
          
            myGLCD.setFont(BigFont);
            myGLCD.setBackColor(0, 255, 0);

            drawMenuSwitch();
            
                while (true) {
                  
                  if (myTouch.dataAvailable())
                  {
                  
                    myTouch.read();
                    x=myTouch.getX();
                    y=myTouch.getY();

                    if ((y>=50) && (y<=90))  // First buttons row 
                    {
                      
                      if ((x>=10) && (x<=60))  // Button: Turn OFF (10, 50, 60, 90)
                      {
                        writeRedFrame(10, 50, 60, 90);
                        digitalWrite(ch1, LOW);
              
                        myGLCD.setColor(255, 0, 0);
                        myGLCD.print("FAN OFF!", CENTER, 192);
                        delay(2000);
                        myGLCD.print("          ", CENTER, 192);
                      }
                      if ((x>=70) && (x<=120))  // Button: Turn ON (70, 50, 120, 90)
                      {
                        writeRedFrame(70, 50, 120, 90);
                        digitalWrite(ch1, HIGH);
              
                        myGLCD.setColor(255, 0, 0);
                        myGLCD.print("FAN ON!", CENTER, 192);
                        delay(2000);
                        myGLCD.print("         ", CENTER, 192);
                      }
                    }
                    
                   if ((y>=100) && (y<=140)) // Second buttons row
                   {
                    if((x>=10) && (x<=85)) // Button Start (10, 100, 85, 140)
                    {
                      writeRedFrame(10, 100, 85, 140);
                      myGLCD.clrScr();

                      myTouch.setPrecision(PREC_MEDIUM);
                    
                      myGLCD.setFont(BigFont);
                      myGLCD.setBackColor(0, 255, 0);
                      
                      drawStart();
                      loop();
                    }
                    }
                  }
              }
          }
        }
      }
  }
}

