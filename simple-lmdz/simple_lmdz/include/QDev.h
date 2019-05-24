#ifndef _QDEV_h
#define _QDEV_h

#include <stddef.h>
#include "pre-def.h"
#include "structs.h"

int QDev(sensor* sen1, sensor* sen2);
int position1(sensor* sen, QD* ptr);
int position2(sensor* sen, QD* ptr);


#endif