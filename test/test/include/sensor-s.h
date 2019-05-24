#ifndef _SENSOR_S_h
#define _SENSOR_S_h

typedef struct sensor {
    char senName[8];
    int key;
    int value_a[10], value_b[10];
    int sum_a, sum_b;
    float average_a, average_b;
}sensor;

extern sensor sen1;
extern sensor sen2;

#endif