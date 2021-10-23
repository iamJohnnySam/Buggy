#include <Servo.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_PCD8544.h>

//MOTOR::   PIN MAPPING
#define mtr3N 9
#define mtr3P 8
#define mtr4N 6
#define mtr4P 7
#define mtr1N 5
#define mtr1P 4
#define mtr2N 2
#define mtr2P 3

//PROGRAM:: PARAMERERS
#define rDeadband 2

//SERVO::   LIMITS
#define minClaw 90
#define maxClaw 130

// ROBOT::  SERVO OBJECTS
Servo robotBase;
Servo robotShoulder;
Servo robotElbow;
Servo robotClaw;

//LCD::     LCD OBJECT
Adafruit_PCD8544 LCD = Adafruit_PCD8544(33, 35, 37, 39, 41);

//VARIABLES:: CAR CONFIGURATION
bool enTrainingWheel = false;
bool enRobot = true;

//VARIABLES:: CAR PARAMETERS
int forwardSpeed = 255;

//VARIABLES:: ROBOT PARAMETERS
int tElbow, pElbow, tShoulder, pShoulder, tBase, pBase, rSpeed;

void setup() {
  Serial.begin(9600);
  Serial.println ("iamJohnnySam");
  configureMotor();
  attachServos();
  homeServos();
  configureLCD();
}

void loop() {
  debuggingMode();
  moveRobot();
}
