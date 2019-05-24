#include <Arduino.h>
#include <Stepper.h>
#include <Wire.h>
#include "myhead.h"

//*****ADXL345******
#define DEVICE (0x53)      //ADXL345 device address
#define TO_READ (6)        //num of bytes we are going to read each time (two bytes for each axis)

void writeTo(int device, byte address, byte val);
void readFrom(int device, byte address, int num, byte buff[]);
void RP_calculate();

byte buff[TO_READ] ;        //6 bytes buffer for saving data read from the device
char str[512];              //string buffer to transform data before sending it to the serial port
int regAddress = 0x32;      //first axis-acceleration-data register on the ADXL345
int x, y, z;                        //three axis acceleration data
double roll = 0.00, pitch = 0.00;       //Roll & Pitch are the angles which rotate by the axis X and y 
//*******************************

//FSR********************************************************
sensor sen1 = {"sensor1", 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, };

void Print(sensor* sen);
//**********************
void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(PA1, OUTPUT);
  pinMode(PA0, INPUT);

  Wire.begin();         // join i2c bus (address optional for master)
  //Serial.begin(9600);  // start serial for output

  //Turning on the ADXL345
  writeTo(DEVICE, 0x2D, 0);      
  writeTo(DEVICE, 0x2D, 16);
  writeTo(DEVICE, 0x2D, 8);

}

void loop() {
  // put your main code here, to run repeatedly:
  analogWrite(PA1, HIGH);
  getValue(&sen1, NULL);
  rearrange(&sen1, NULL);
  QDev(&sen1, NULL);
  judge(&sen1, NULL);
  {
    Print(&sen1);
  }

  delay(Delay);


  readFrom(DEVICE, regAddress, TO_READ, buff); //read the acceleration data from the ADXL345
                                              //each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
                                              //thus we are converting both bytes in to one int
  x = (((int)buff[1]) << 8) | buff[0];   
  y = (((int)buff[3])<< 8) | buff[2];
  z = (((int)buff[5]) << 8) | buff[4];

  //we send the x y z values as a string to the serial port
  Serial.print("The acceleration info of x, y, z are:");
  sprintf(str, "%d %d %d", x, y, z);  
  Serial.print(str);
  Serial.write(10);
  //Roll & Pitch calculate
  RP_calculate();
  Serial.print("Roll:"); Serial.println( roll ); 
  Serial.print("Pitch:"); Serial.println( pitch );
  Serial.println("");
}

//FSR--------------------functions
void Print(sensor* sen) {
  // int i;
  // Serial.println("value_a: ");
  // for (i=0; i<length; i++) {
  //   Serial.print(sen->value_a[i]);
  //   Serial.print(", ");
  // }
  // Serial.println();
  // Serial.println("value_b: ");
  // for (i=0; i<length; i++) {
  //   Serial.print(sen->value_b[i]);
  //   Serial.print(", ");
  // }
  // Serial.println();
  
  // Serial.print("sum_a:     ");
  // Serial.print(sen->sum_a);
  // Serial.print(" | ");
  // Serial.print("sum_b:     ");
  // Serial.println(sen->sum_b);

  // Serial.print("average_a: ");
  // Serial.print(sen->average_a);
  // Serial.print("     #|#     ");
  // Serial.print("average_b: ");
  // Serial.println(sen->average_b);
  // Serial.println();

  // Serial.print("Q_a:       ");
  // Serial.print(sen->Q_a);
  // Serial.print("       #|#     ");
  // Serial.print("Q_b:       ");
  // Serial.println(sen->Q_b);
  // Serial.println();

  Serial.print("Q/A_a: ");
  Serial.print(sen->QowerA_a);
  Serial.print("%");
  Serial.print("   #|#   ");
  Serial.print("Q/A_b: ");
  Serial.print(sen->QowerA_b);
  Serial.print("%");
  Serial.print("   #|#   ");
  if (sen->QowerA_a > sen->QowerA_b) {
    Serial.print(1);
    Serial.print("   ");
  } else if (sen->QowerA_a == sen->QowerA_b) {
    Serial.print(0);
    Serial.print("   ");
  } else {
    Serial.print(-1);
    Serial.print("   ");
  }
  Serial.println();

}


//ADXL345---------------- Functions
//Writes val to address register on device
void writeTo(int device, byte address, byte val) {
  Wire.beginTransmission(device); //start transmission to device 
  Wire.write(address);        // send register address
  Wire.write(val);        // send value to write
  Wire.endTransmission(); //end transmission
}

//reads num bytes starting from address register on device in to buff array
void readFrom(int device, byte address, int num, byte buff[]) {
  Wire.beginTransmission(device); //start transmission to device 
  Wire.write(address);        //sends address to read from
  Wire.endTransmission(); //end transmission

    Wire.beginTransmission(device); //start transmission to device
  Wire.requestFrom(device, num);    // request 6 bytes from device

  int i = 0;
  while(Wire.available())    //device may send less than requested (abnormal)
  { 
    buff[i] = Wire.read(); // receive a byte
    i++;
  }
  Wire.endTransmission(); //end transmission
}

//calculate the Roll&Pitch
void RP_calculate(){
  double x_Buff = float(x);
  double y_Buff = float(y);
  double z_Buff = float(z);
  roll = atan2(y_Buff , z_Buff) * 57.3;
  pitch = atan2((- x_Buff) , sqrt(y_Buff * y_Buff + z_Buff * z_Buff)) * 57.3;
}