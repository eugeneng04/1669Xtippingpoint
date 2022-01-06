#include "main.h"

pros::ADIDigitalOut liftclamp('B');

bool pistonState1 = false;
bool prevPistonState1 = false;
bool mogoState1 = false;

void liftclamp_auto (bool clamp){ //auton
  liftclamp.set_value(clamp);
}

void liftclamp_Toggle(){
    pistonState1 = master.get_digital(DIGITAL_R1);
    if(pistonState1 == true && prevPistonState1 == false){
      mogoState1 = !mogoState1;
      liftclamp.set_value(mogoState1);
    }
    prevPistonState1 = pistonState1;
}