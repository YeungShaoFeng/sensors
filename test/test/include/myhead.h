#include <io.h>

#include "pre-def.h"
#include "sensor-s.h"
#include "getValue.h"
#include "valuePrint.h"

sensor sen1 = {"sensor1", 0, 0, 0, 0, 0, 0, 0, };
sensor sen2 = {"sensor2", 0, 0, 0, 0, 0, 0, 0, };

extern const int length = sizeof(sen1.value_a) / sizeof(sen1.value_a[0]);
extern const int Delay = 1000 / length;
