#include "main.h"

pros::Motor conveyor(9, MOTOR_GEARSET_6, false, MOTOR_ENCODER_DEGREES);
int reverse1 = 1;
bool conveyor_lock = false;
bool conveyor_up = false;

void set_conveyor(bool up){// auton
  if (up){
    conveyor.move_velocity(600);
  }
  else{
    conveyor.move_velocity(0);
  }
}
void move_conveyor(){ //driver control
  if (master.get_digital(DIGITAL_R2)) {
    reverse1 = -1;
    conveyor_up = !conveyor_up;
    conveyor_lock = true;
    while(master.get_digital(DIGITAL_R2))pros::delay(10);
  }
  else if (!master.get_digital(DIGITAL_R2) && conveyor_lock==true) {
    reverse1 = 1;
    conveyor_lock = false;
  }

  if (conveyor_up)
    conveyor.move_velocity(600*reverse1);
  else
    conveyor.move_velocity(0);
}