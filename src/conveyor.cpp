#include "main.h"

pros::Motor conveyor(9, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
bool conveyor_lock = false;
int count1 = 0;
int holdtime = 0;
int holdthreshold = 10;


void set_conveyor(bool up){// auton
  if (up) conveyor.move_velocity(600);
  else conveyor.move_velocity(0);
}

void move_conveyor(){ //driver control
  if (master.get_digital(DIGITAL_R2)) {
    if(!conveyor_lock){
      conveyor_lock = true;
    }
    holdtime++;
    if(holdtime > holdthreshold) conveyor.move_velocity(-600);
  } else {
    if(holdtime > 0  and holdtime <= 10) count1++;
    conveyor_lock = false;
    holdtime = 0;
    if(count1 %2 == 1) conveyor.move_velocity(600);
    else conveyor.move_velocity(0);
  }
}
