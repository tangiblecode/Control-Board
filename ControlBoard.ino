/*
http://tangiblecode.org

This sketch is part of "building your own" Tangible Code documentation.
http://tangiblecode.org/make/

Load this file onto the control board.

Tested on Arduino Uno

*/

//Main library for interfacing with push buttons, handles button deboucing.
#include <Pushbutton.h>

//Button pin definitions
#define BUTTON_PIN_1 8
#define BUTTON_PIN_2 9
#define BUTTON_PIN_3 10
#define BUTTON_PIN_4 11

#define DEFAULT_STATE_LOW 0

// Assign button variables
Pushbutton button1(BUTTON_PIN_1);
Pushbutton button2(BUTTON_PIN_2);
Pushbutton button3(BUTTON_PIN_3);
Pushbutton button4(BUTTON_PIN_4);

char moveState;

void setup() {
  Serial.begin(9600);
  moveState = 'G';
} //--(end setup)--

void loop() {
   checkRobot();
   Serial.println(moveState);
   moveRobot();
}

// Function to check the current state of the robot (check if the robot is moving)
void checkRobot () {
   if (Serial.available() > 0) {
    char moveStateIn = Serial.read();
    if (moveStateIn == 'G') {
      moveState = 'G';
    }
    delay(100);
  } 
}


// Function to move the robot 
void moveRobot () {
    if(moveState == 'G') {
      if (!button1.isPressed()){
        // Serial.println("Lights On");
        button1.waitForPress();
        Serial.println('F');
        moveState = 'S';
        //Serial.println(moveState);
      }
      if (!button2.isPressed()){
        //Serial.println("Lights On");
        button2.waitForPress();
        Serial.println('R');
        moveState = 'S';
        //Serial.println(moveState);
    }
    if (!button3.isPressed()){
        //Serial.println("Lights On");
        button3.waitForPress();
        Serial.println('L');
        moveState = 'S';
        //Serial.println(moveState);
    }
    if (!button4.isPressed()){
        //Serial.println("Lights On");
        button4.waitForPress();
        Serial.println('B');
        moveState = 'S';
        //Serial.println(moveState);
    }
  }
}
