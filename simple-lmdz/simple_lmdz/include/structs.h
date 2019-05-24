#ifndef _STRUCTS_h
#define _STRUCTS_h

typedef struct sensor {
    char sensorName[8];
    int value_a[10], value_b[10];
    int keys[10];
    float sum_a, sum_b;
    float average_a, average_b;
    double Q_a, Q_b;
    float QowerA_a, QowerA_b;
}sensor;

typedef struct QD {
	int xq1_1, xq1_2, xq3_1, xq3_2;
	double Q1, Q3;
}QD;

typedef enum Capacity{
    zehn, zwanzig, dreissig, vierzig, funfzig,
    sechzig, siebzig, achtzig, neunzig, hundert,
}Capacity;

#endif