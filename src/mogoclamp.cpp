#include "main.h"

pros::ADIDigitalOut mogoclamp('A');

bool pistonState = false;
bool prevPistonState = false;
bool mogoState = false;

void mogoclamp_auto (bool clamp){ //auton
  mogoclamp.set_value(clamp);
}

void mogoclamp_Toggle(){ //driver control
    pistonState = master.get_digital(DIGITAL_Y);
    if(pistonState == true && prevPistonState == false){
      mogoState = !mogoState;
      mogoclamp.set_value(mogoState);
    }
    prevPistonState = pistonState;
}
