/********************************************************
 * PID Basic Example
 * Reading analog input 0 to control analog PWM output 3
 ********************************************************/

#include <PID_v1.h>
#include <Arduino.h>

#define PIN_INPUT PA0
#define PIN_OUTPUT PA1

//Define Variables we'll be connecting to
double Setpoint, Input, Output;

//Specify the links and initial tuning parameters
double Kp=4, Ki=4, Kd=4;
PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup()
{
  //initialize the variables we're linked to
  Input = analogRead(PIN_INPUT);
  Setpoint = 100;
  Serial.begin(115200);
  //turn the PID on
  myPID.SetMode(AUTOMATIC);
  pinMode(PA2, OUTPUT);
  analogWrite(PA2, HIGH);
}
int i = 0;

void loop()
{
  Input = analogRead(PIN_INPUT);
  Serial.print(i); Serial.print("\t");
  Serial.print("Ip:\t"); Serial.print(Input);
  myPID.Compute();
  analogWrite(PIN_OUTPUT, Output);
  Serial.print("\tOp:\t"); Serial.println(Output);
  //delay(10);
  i++;
}
