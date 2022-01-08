#include "main.h"
#pragma once

#include "EZ-Template/drive/drive.hpp"

extern Drive chassis;

void drive(int distance, double speed_factor);
void turn(int angle, double speed_factor);
void clamp(int i, int delay_time, bool activation);
void skillspath();
