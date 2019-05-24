#include <Arduino.h>
#include "valuePrint.h"


void valuePrint(sensor *sen1, sensor *sen2) {
	//Serial.print("  ");
	valuePrint_step_a(sen1);
	valuePrint_step_b(sen1);
	if (sen2 != NULL) {
		valuePrint_step_a(sen2);
		valuePrint_step_b(sen2);
	}
}

void valuePrint_step_a(sensor* sen) {
	Serial.println(sen->senName);
	Serial.println("values_a: ");
	for (looper = 0; looper < length; looper++) {
		Serial.print(sen->value_a[looper]);
		Serial.print(", ");
	}
	Serial.println();
}

void valuePrint_step_b(sensor* sen) {
	Serial.println("values_b: ");
	for (looper = 0; looper < length; looper++) {
		Serial.print(sen->value_b[looper]);
		Serial.print(", ");
	}
	Serial.println();
}