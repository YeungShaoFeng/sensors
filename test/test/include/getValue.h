#ifndef _GETVALUE_h
#define _GETVALUE_h

#include <Arduino.h>

#include "pre-def.h"
#include "sensor-s.h"

void getValue(sensor* sen1, sensor* sen2);
void getValue_step_1_a(sensor* sen1);
void getValue_step_1_b(sensor* sen1);
void getValue_step_2_a(sensor* sen2);
void getValue_step_2_b(sensor* sen2);
void aveRage(sensor* sen1, sensor* sen2);

#endif