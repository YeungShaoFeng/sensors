#include <Wire.h>
#include <Arduino.h>
#include "I2Cdev.h"
#include "MPU6050.h"



MPU6050 accelgyro;

int16_t ax, ay, az;
int16_t gx, gy, gz;

#define LED_PIN 13
bool blinkState = false;
void mpu6050Setup();
// all 6 aixs acceleration's print
void printAllAcceleration(int16_t* ax, int16_t* ay, int16_t* az, int16_t*gx, int16_t* gy, int16_t* gz);
// a's acceleration's print
void printAsAcceleration(int16_t* ax, int16_t* ay, int16_t* az);
//g's acceleration's print
void printGsAcceleration(int16_t*gx, int16_t* gy, int16_t* gz);


void setup() {
    Serial.begin(9600);
    mpu6050Setup();
}

void loop() {
    accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);
    printAllAcceleration(&ax, &ay, &az, &gx, &gy, &gz);

    // blink LED to indicate activity
    blinkState = !blinkState;
    digitalWrite(LED_PIN, blinkState);

    delay(500);
}

void mpu6050Setup() {
    // join I2C bus (I2Cdev library doesn't do this automatically)
    Wire.begin();

    // initialize device
    Serial.println("Initializing I2C devices...");
    accelgyro.initialize();

    // verify connection
    Serial.println("Testing device connections...");
    Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

    // configure Arduino LED for
    pinMode(LED_PIN, OUTPUT);
}

// all 6 aixs acceleration's print
void printAllAcceleration(int16_t* ax, int16_t* ay, int16_t* az, int16_t*gx, int16_t* gy, int16_t* gz) {
    // display tab-separated accel/gyro x/y/z values
    Serial.print("a:\t");
    Serial.print(*ax / 16330.0 + 0.025); Serial.print("\t");      //
    Serial.print(*ay / 16330.0 + 0.015); Serial.print("\t");      // 
    Serial.println(*az / 17170.0 - 0.98);
    Serial.print("g:\t");
    Serial.print(*gx / 266.0 - 0.90); Serial.print("\t");
    Serial.print(*gy / 800.0 - 0.93); Serial.print("\t");
    Serial.println(*gz / 210.0 - 0.91);
}

// a's acceleration's print
void printAsAcceleration(int16_t* ax, int16_t* ay, int16_t* az) {
    // display tab-separated accel x/y/z values
    Serial.print("a:\t");
    Serial.print(*ax / 16330.0 + 0.025); Serial.print("\t");      //
    Serial.print(*ay / 16330.0 + 0.015); Serial.print("\t");      // 
    Serial.println(*az / 17170.0 - 0.98);
}

//g's acceleration's print
void printGsAcceleration(int16_t*gx, int16_t* gy, int16_t* gz) {
    // display tab-separated accel/gyro x/y/z values
    Serial.print("g:\t");
    Serial.print(*gx / 266.0 - 0.90); Serial.print("\t");
    Serial.print(*gy / 800.0 - 0.93); Serial.print("\t");
    Serial.println(*gz / 210.0 - 0.91);
}
