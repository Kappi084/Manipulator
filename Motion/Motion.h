#ifndef MOTION_H
#define MOTION_H

#include "Arduino.h"
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "Servo.h"

class Manipulator {
public:
    Manipulator(int steps_per_mm_X, int steps_per_mm_Y, int steps_per_mm_Z);
    void init();
    void motion (int linear_X, int linear_Y, int linear_Z, int speed);
private:
    int _steps_per_mm_X;
    int _steps_per_mm_Y;
    int _steps_per_mm_Z;
    AccelStepper _stepperA;
    AccelStepper _stepperB;
    AccelStepper _stepperZ;
    MultiStepper _steppersControl;
};

class Servos {
public:
    Servos();
    void init(int Gripper_degrees_open, int Gripper_degrees_closed, int TurnUnit_Grade_Zeropos);
    void motion(int Pos_Gripper, int Pos_TurnUnit);
private:
    int _Gripper_degrees_open;
    int _Gripper_degrees_closed;
    int _TurnUnit_degrees_ZeroPos;
    Servo _Gripper;
    Servo _TurnUnit;
};
#endif
