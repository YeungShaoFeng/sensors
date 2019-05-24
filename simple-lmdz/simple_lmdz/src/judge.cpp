#include "judge.h"

Capacity capacity;
double Qab;
int judgeKey = 0;

void judge(sensor* sen1, sensor* sen2) {
    judge_step(sen1);
    if (sen2 != NULL) {
        judge_step(sen2);
    }

}

void judge_step(sensor* sen) {
    Qab = sen->Q_a - sen->Q_b;
    //Q_a在ave_a中所占的百分比越大就说明压力越大
    sen->QowerA_a = (sen->Q_a / sen->average_a) * 100;
    sen->QowerA_b = (sen->Q_b / sen->average_b) * 100;
    switch (judgeKey)
    {
        case zehn: Serial.println("10%"); break;
        
        default: break;
    }

    
}

// void judge_step_compare(sensor* sen) {
//     int judgeKeyMod = 0;
//     judgeKeyMod =  0;



// }