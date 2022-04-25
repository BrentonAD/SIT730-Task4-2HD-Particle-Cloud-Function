/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/brent/OneDrive/Documents/_UNIVERSITY/_MASTEROFAI/2022Tri1/SIT730-EmbeddedSystemDevelopment/Tasks/4/SIT730-Task4-2HD-Particle-Cloud-Function/src/Particle-Cloud-Function.ino"
/*
 * Project Particle-Cloud-Function
 * Description:
 * Author:
 * Date:
 */
void setup();
void loop();
#line 7 "c:/Users/brent/OneDrive/Documents/_UNIVERSITY/_MASTEROFAI/2022Tri1/SIT730-EmbeddedSystemDevelopment/Tasks/4/SIT730-Task4-2HD-Particle-Cloud-Function/src/Particle-Cloud-Function.ino"
SerialLogHandler logHandler;

int selectLight(String colour);

pin_t GREEN_LED = D6;
pin_t BLUE_LED = D5;
pin_t RED_LED = D4;

pin_t currentState;

void setup() {
  pinMode(GREEN_LED, OUTPUT);
  pinMode(BLUE_LED, OUTPUT);
  pinMode(RED_LED, OUTPUT);

  digitalWrite(GREEN_LED, LOW);
  digitalWrite(BLUE_LED, LOW);
  digitalWrite(RED_LED, LOW);

  Particle.function("selLight", selectLight);
}

void loop() {
}

int selectLight(String colour) {
  // Log Event (for debugging purposes)
  Log.info("Colour sent %s", colour);

  // Turn off currently lit LED
  if(currentState != '\0'){
    digitalWrite(currentState, LOW);
  }

  // Light correct LED
  if(colour == "green"){
    currentState = GREEN_LED;
    digitalWrite(GREEN_LED, HIGH);

    return 1;
  }
  else if (colour == "blue")
  {
    currentState = BLUE_LED;
    digitalWrite(BLUE_LED, HIGH);

    return 1;
  }
  else if (colour == "red")
  {
    currentState = RED_LED;
    digitalWrite(RED_LED, HIGH);

    return 1;
  }
  else
  {
    Log.info("%s not a valid colour. Please select 'green', 'blue', or 'red'", colour);

    return -1;
  }
  
}