#include <Arduino.h>
#include <AccelStepper.h>
#include <MultiStepper.h>
#include <Servo.h>  
#include "Manipulator.h"

int Gripper_open = 0;
int Gripper_closed = 90;
int Rotatingunit_0 = 0;
int Rotatingunit_180 = 180;

//Kalibrierung: hier werden die Werte nach dem Kalibrieren eingetragen.
Manipulator _Station1CoreXY(4,4,4);
Servos _Station1Servo();

void setup() {

  //Initialisieren: Hier werden, die Motoren angelegt und der Maximal speed eingegeben.
  _Station1CoreXY.init();
  //Initialisieren: Hier werden, die Motoren angelegt und die null Positionen eingegeben.
  _Station1Servo.init(0, 10, 0); //(Greifer Grade offen, Greifer Grade geschlossen, Dreheinheit Grade Null Position)

  //Referenzieren: Er fährt bis zum Endschalter
  _Station1CoreXY.reference(0,0,0);

  
  Serial.begin(9600);
}

void loop() {

  //Liest aus, ob im seriellen Monitor der Wert 1 geschrieben wurde...
  if(Serial.read() == 1){

  //Fährt auf POS1
  _Station1CoreXY.motion(100, 200, 10); //(X-Position, Y-Position, Z-Position);
  //Öffnet den Greifer
  _Station1Servo.motionServo(open, 0); //(open||closed, Grade von 0 - 180);

  //Fährt mit der Z-Achse nach unten
  _Station1CoreXY.motion(, , 50);
  //schließt den Greifer
  _Station1Servo.motion(close, 0);
  //Fährt mit der Z-Achse nach oben
  _Station1CoreXY.motion(, , 10);

  //Fährt auf POS2
  _Station1CoreXY.motion(100, 200, 10); //(X-Position, Y-Position, Z-Position);
  //Öffnet den Greifer
  _Station1Servo.motionServo(, 180); //(open||closed, Grade von 0 - 180);

//Fährt mit der Z-Achse nach unten
  _Station1CoreXY.motion(, , 50);
  //Öffnet den Greifer
  _Station1Servo.motion(open);
  //Fährt mit der Z-Achse nach oben
  _Station1CoreXY.motion(, , 10);
  }
  
}
