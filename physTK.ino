/*
Physic Toolkit
July 25th, 2017
Robin Dupont (N0ciple)
*/

#include "Arduboy.h"

// make an instance of arduboy used for many functions
Arduboy arduboy;
bool pressState = false;
long int timer = 0;
long double timeDelta = 0;
float dist = 0;
const float g = 9.81;

void setup() {
  // initiate arduboy instance
  arduboy.begin();
  // here we set the framerate to 15, we do not need to run at
  // default 60 and it saves us battery life
  arduboy.clear();
  arduboy.print("Physic Toolkit");
  arduboy.print("\npress B");
  arduboy.display();
  while(!arduboy.pressed(B_BUTTON)){}

}


void loop() {

  // first we clear our screen to black
  arduboy.clear();
  if(arduboy.pressed(A_BUTTON)){
    if(!pressState){
      pressState = true;
      timer = millis();
    }else{
      timeDelta = millis() - timer;
      // Convert timeDelta to seconds
      timeDelta /= 1000;
      dist = 0.5 * g * pow(timeDelta,2);
      dist = (float)round(dist*100)/100;
      arduboy.setCursor(0,0);
      arduboy.print("Height = " + String(dist,10));
    }
    
  } else {
    arduboy.setCursor(0,0);
    arduboy.print("Height = " + String(dist,10));
  }

  if(arduboy.pressed(B_BUTTON)){
    dist = 0;
    timer = 0;
    pressState = false;

  }
 

  // then we finaly we tell the arduboy to display what we just wrote to the display
  arduboy.display();
}
