#ifndef _JUDGE_h
#define _JUDGE_h

#include <Arduino.h>
//#include <stddef.h>
#include "pre-def.h"
#include "structs.h"

#ifdef _JUDGE_h
// Capacity capacity;
// double Qab;
// int judgeKey = 0;
#endif

void judge(sensor* sen1, sensor* sen2);
void judge_step(sensor* sen);
void judge_step_compare(sensor* sen);

#endif