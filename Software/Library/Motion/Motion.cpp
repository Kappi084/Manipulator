#include "Motion.h"
  
 // Define the stepper motor and the pins that is connected to

Manipulator::Manipulator()
 :_stepperA(1, 2, 5),
 _stepperB(1, 3, 6),
 _stepperZ(1, 4, 7)
 {
}
 
void Manipulator::init(int steps_per_mm_X, int steps_per_mm_Y, int steps_per_mm_Z) {
    _steps_per_mm_X = steps_per_mm_X;
    _steps_per_mm_Y = steps_per_mm_Y;
    _steps_per_mm_Z = steps_per_mm_Z;

    _stepperA.setMaxSpeed(1000); // Set maximum speed value for the stepper
    _stepperB.setMaxSpeed(1000);
    _stepperZ.setMaxSpeed(1000);

    _stepperA.setAcceleration(100);
    _stepperB.setAcceleration(100);
    _stepperZ.setAcceleration(100);

    // Adding the 3 steppers to the steppersControl instance for multi stepper control
    _steppersControl.addStepper(_stepperA);
    _steppersControl.addStepper(_stepperB);
    _steppersControl.addStepper(_stepperZ);
}

void Manipulator::motion(int linear_X, int linear_Y, int linear_Z, int speed) {
    int MotorA;
    int cal_X;
    int MotorB;
    int cal_Y;
    int MotorZ;
    int cal_Z;
    //long gotoposition[3];

    _stepperA.setMaxSpeed(speed); // Set maximum speed value for the stepper
    _stepperB.setMaxSpeed(speed);
    _stepperZ.setMaxSpeed(speed);

// um die stpmm auszurechen kann diese Anleitung verwendet werden. https://all3dp.com/2/extruder-calibration-calibrate-e-steps/
    cal_X = _steps_per_mm_X * linear_X;
    cal_Y = _steps_per_mm_Y * linear_Y;
    cal_Z = _steps_per_mm_Z * linear_Z;

    MotorA = cal_X + cal_Y;
    MotorB = cal_X - cal_Y;
    MotorZ = cal_Z;
    
    gotoposition[0] = MotorA;  // 800 steps - full rotation with quater-step resolution
    gotoposition[1] = MotorB;
    gotoposition[2] = MotorZ;

    _steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
    _steppersControl.runSpeedToPosition(); // Blocks until all steppers are in position
}

void Manipulator::reference (int X_Distanz, int Y_Distantz, int Z_Distantz)
{

    Serial.begin(9600);
    int limit_switch_Pin_X = 9; // the number of the Endstop pin
    int limit_switch_Pin_Y = 10;
    int limit_switch_Pin_Z = 11;
  
    int calibration_A = 0;
    int calibration_B = 0;
    int calibration_Z = 0;

   // int buttonState = digitalRead(buttonPin);

    //Reference X
    pinMode(limit_switch_Pin_X, INPUT_PULLUP);
    pinMode(limit_switch_Pin_Y, INPUT_PULLUP);
    pinMode(limit_switch_Pin_Z, INPUT_PULLUP);

    while (digitalRead(limit_switch_Pin_X) == HIGH) 
    {
        gotoposition[0] = calibration_A;
        gotoposition[1] = calibration_B;
        _steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
        _steppersControl.runSpeedToPosition();
        calibration_A = calibration_A + 10;
        calibration_B = calibration_A;
        delay(10);
    }


    Serial.println();
    Serial.print("Calibration X");
    Serial.println();
    Serial.print("Motor A ");
    Serial.print(calibration_A);
    Serial.print("\t");
    Serial.print("Motor B ");
    Serial.print(calibration_B);
    Serial.print("\t");


    delay(500);
  

    while (digitalRead(limit_switch_Pin_Y) == HIGH) 
    {
        gotoposition[0] = calibration_A;
        gotoposition[1] = calibration_B;
        _steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
        _steppersControl.runSpeedToPosition();
        calibration_A = calibration_A + 10;
        calibration_B = calibration_B - 10;
        delay(10);
    }


        Serial.println();
    Serial.print("Calibration Y");
    Serial.println();
    Serial.print("Motor A ");
    Serial.print(calibration_A);
    Serial.print("\t");
    Serial.print("Motor B ");
    Serial.print(calibration_B);
    Serial.print("\t");

    


    delay(500);

    while (digitalRead(limit_switch_Pin_Z) == HIGH) 
    {
        gotoposition[2] = calibration_Z;
        _steppersControl.moveTo(gotoposition); // Calculates the required speed for all motors
        _steppersControl.runSpeedToPosition();
        calibration_Z = calibration_Z + 1;
        delay(500);
    }

    calibration_A = _stepperA.currentPosition();
    calibration_B = _stepperB.currentPosition();

    MotorA_zero = calibration_A;
    MotorB_zero = calibration_B;
    MotorZ_zero = calibration_Z;
    delay(1000);

    Serial.println();
    Serial.print("Calibration A und B");
    Serial.println();
    Serial.print("Motor A ");
    Serial.print(MotorA_zero);
    Serial.print("\t");
    Serial.print("Motor B ");
    Serial.print(MotorB_zero);
    Serial.print("\t");

}

Servos::Servos(){
    
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
/*
void Servos::motion(String Pos_Gripper, int Pos_TurnUnit) {
    int angle = 0;
    if(Pos_Gripper == "open" || "oeffnen"){
        for (angle = _Gripper_degrees_closed; angle > _Gripper_degrees_open; angle--) {
            _Gripper.write(angle);
            delay(15);
        }
        int angle = 0;
    }
    if(Pos_Gripper == "close" || "schliessen"){
        for (angle = _Gripper_degrees_open; angle > _Gripper_degrees_closed; angle++) {
            _Gripper.write(angle);
            delay(15);
        }
        int angle = 0;
    }
    _TurnUnit.write(Pos_TurnUnit - _TurnUnit_degrees_ZeroPos);
}
*/
void Servos::motion(String Pos_Gripper, int Pos_TurnUnit) {
    _Gripper_degrees_open = 100;
    _Gripper_degrees_closed = 10;
    if(Pos_Gripper == "open" || Pos_Gripper == "oeffnen"){
      _Gripper.write(_Gripper_degrees_open);
      delay(15);
    }
    if(Pos_Gripper == "close" || Pos_Gripper == "schliessen"){
      _Gripper.write(_Gripper_degrees_closed);
      delay(15);
    }
    _TurnUnit.write(Pos_TurnUnit - _TurnUnit_degrees_ZeroPos);
  }
