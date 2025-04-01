#include "Motion.h"
  
 // Define the stepper motor and the pins that is connected to

Manipulator::Manipulator(int steps_per_mm_X, int steps_per_mm_Y, int steps_per_mm_Z)
 :_stepperA(1, 2, 5),
 _stepperB(1, 3, 6),
 _stepperZ(1, 4, 7)
 {
    _steps_per_mm_X = steps_per_mm_X;
    _steps_per_mm_Y = steps_per_mm_Y;
    _steps_per_mm_Z = steps_per_mm_Z;
}
 
void Manipulator::init() {

    _stepperA.setMaxSpeed(10000); // Set maximum speed value for the stepper
    _stepperB.setMaxSpeed(10000);
    _stepperZ.setMaxSpeed(10000);

    // Adding the 3 steppers to the steppersControl instance for multi stepper control
    _steppersControl.addStepper(_stepperA);
    _steppersControl.addStepper(_stepperB);
    _steppersControl.addStepper(_stepperZ);
}

void Manipulator::motion (int linear_X, int linear_Y, int linear_Z, int speed) {
    int MotorA;
    int cal_X;
    int MotorB;
    int cal_Y;
    int MotorZ;
    int cal_Z;
    long gotoposition[3];

    _stepperA.setSpeed(500); // Set maximum speed value for the stepper
    _stepperB.setSpeed(500);
    _stepperZ.setSpeed(500);

// um die stpmm auszurechen kann diese Anleitung verwendet werden. https://all3dp.com/2/extruder-calibration-calibrate-e-steps/
    cal_X = _steps_per_mm_X * linear_X;
    cal_Y = _steps_per_mm_Y * linear_Y;
    cal_Z = _steps_per_mm_Z * linear_Z;

    MotorA = cal_X + cal_Y;
    MotorB = cal_X - cal_Y;

    gotoposition[0] = MotorA;  // 800 steps - full rotation with quater-step resolution
    gotoposition[1] = MotorB;
    gotoposition[2] = MotorZ;

    _steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
    _steppersControl.runSpeedToPosition(); // Blocks until all steppers are in position
}


void Servos::Servos();{

}


void Servos::init(int Gripper_degrees_open, int Gripper_degrees_closed, int TurnUnit_degrees_ZeroPos) {
    _Gripper.attach(9);
    _TurnUnit.attach(10);
    _Gripper.write(_Gripper_degrees_open);
    _Gripper.write(_TurnUnit_degrees_ZeroPos);
    _Gripper_degrees_open = Gripper_degrees_open;
    _Gripper_degrees_closed = Gripper_degrees_closed;
    _TurnUnit_degrees_ZeroPos = TurnUnit_degrees_ZeroPos;
}

void Servos::motion(char Pos_Gripper, int Pos_TurnUnit) {
    if(Pos_Gripper = open || offen){
        _Gripper.write(_Gripper_degrees_open);
    }
    if(Pos_Gripper = closed || geschlossen){
        _Gripper.write(_Gripper_degrees_closed);
    }
    _TurnUnit.write(Pos_TurnUnit - _TurnUnit_degrees_ZeroPos);
}

