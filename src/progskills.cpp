#include "main.h"

const int DRIVE_SPEED = 110;
const int TURN_SPEED  = 90;
const int SWING_SPEED = 90;

void drive(int distance, double speed_factor) {
    chassis.set_drive_pid(distance, DRIVE_SPEED*speed_factor, true);
    chassis.wait_drive();
}

void turn(int angle, double speed_factor) {
    chassis.set_turn_pid(angle, TURN_SPEED*speed_factor);
    chassis.wait_drive();
    pros::delay(300);
}

void clamp(int i, int delay_time, bool activation) {
    if(i == 0) {
        mogoclamp_auto(activation);
    } else if (i == 1) {
        liftclamp_auto(activation);
    } else {
        //do nothing
    }
    pros::delay(delay_time);

}

void skillspath() { //code to test the first part of the prog skills to put 2 mogos on the platform

    clamp(0, 100, true); //mogoclamp
    drive(5, 1.0);
    turn(90, 0.8);
    drive(20, 1.0);
    clamp(1, 100, true); //liftclamp
    turn(45, 0.8);
    drive(20, 1.0);
    set_lift_position(300, 100);
    drive(2, 1.0);
    clamp(1, 100, false); //liftclamp
    drive(-2, 1.0);
    set_lift_position(0, 100);
    clamp(0, 100, false); //mogoclamp
    turn(180, 0.8);
    clamp(1, 100, true); //liftclamp
    turn(180, 0.8);
    set_lift_position(300, 100);
    drive(2, 1.0);
    clamp(1, 100, false); //liftclamp
    drive(-2, 1.0);





}
