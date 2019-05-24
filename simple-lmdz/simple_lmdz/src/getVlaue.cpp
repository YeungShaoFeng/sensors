#include "getValue.h"

//func getValue
void getValue(sensor* sen1, sensor* sen2) {
  int i;
  sen1->sum_a = 0;
  for (i=0; i<length; i++) {
    sen1->value_a[i] = analogRead(PA0);
    sen1->sum_a += sen1->value_a[i];
  }
  sen1->sum_b = 0;
  for (i=0; i<length; i++) {
    sen1->value_b[i] = analogRead(PA0);
    sen1->sum_b += sen1->value_b[i];
  }
  sen1->average_a = sen1->sum_a / length;
  sen1->average_b = sen1->sum_b / length;
}