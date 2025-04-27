#ifndef MOTION_H
#define MOTION_H

#include "Arduino.h"
#include "AccelStepper.h"
#include "MultiStepper.h"
#include "Servo.h"

class Manipulator {
public:
    Manipulator();
    void init(int steps_per_mm_X, int steps_per_mm_Y, int steps_per_mm_Z);
    void motion(int linear_X, int linear_Y, int linear_Z, int speed);
    void reference(int X_Distanz, int Y_Distantz, int Z_Distantz);
    long gotoposition[3];
private:
    int MotorA_zero;
    int MotorB_zero;
    int MotorZ_zero;
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
    void motion(String Pos_Gripper, int Pos_TurnUnit);
private:
    int _Gripper_degrees_open = 100;
    int _Gripper_degrees_closed = 10;
    int _TurnUnit_degrees_ZeroPos;
    Servo _Gripper;
    Servo _TurnUnit;
};
#endif
