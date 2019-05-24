#include "getValue.h"

void getValue(sensor* sen1, sensor* sen2) {
    for (looper=0; looper<length; looper++) {
        getValue_step_1_a(sen1);
        if (sen2!=NULL) {
        getValue_step_2_a(sen2);
        }

        //delay(Delay);

        getValue_step_1_b(sen1);
        if (sen2!=NULL) {
        getValue_step_2_b(sen2);
        }
    aveRage(sen1, sen2);
    }
}

void getValue_step_1_a(sensor* sen1) {
    sen1->value_a[looper] = analogRead(SEN1_INPUT_PIN);
    sen1->sum_a += sen1->value_a[looper];
}

void getValue_step_1_b(sensor* sen1) {
    sen1->value_b[looper] = analogRead(SEN1_INPUT_PIN);
    sen1->sum_b += sen1->value_b[looper];
}

void getValue_step_2_a(sensor* sen2) {
    sen2->value_a[looper] = analogRead(SEN2_INPUT_PIN);
    sen2->sum_a += sen2->value_a[looper];
}

void getValue_step_2_b(sensor* sen2) {
    sen2->value_b[looper] = analogRead(SEN2_INPUT_PIN);
    sen2->sum_b += sen2->value_b[looper];
}


void aveRage(sensor* sen1, sensor* sen2) {
    sen1->average_a /= length;
    sen1->average_b /= length;
    if(sen2!=NULL) {
        sen2->average_a /= length;
        sen2->average_b /= length;

    }
}