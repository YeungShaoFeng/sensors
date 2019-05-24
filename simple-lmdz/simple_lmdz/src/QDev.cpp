#include "QDev.h"

//func QDev
int QDev(sensor* sen1, sensor* sen2) {
	QD A = { 0, 0, 0, 0, 0, 0 };
	if ((length + 1) % 4 == 0) {
		A.xq1_1 = (length + 1) / 4;
		A.xq3_1 = A.xq1_1 * 3;
		position1(sen1, &A);
		if (sen2 != NULL) {
			position1(sen2, &A);
		}
	}
	else {
		A.xq1_1 = (int)((length + 1) / 4);
		A.xq1_2 = A.xq1_1 + 1;
		A.xq3_1 = (int)(3 * ((length + 1) / 4));
		A.xq3_2 = A.xq3_1 + 1;
		position2(sen1, &A);
		if (sen2 != NULL) {
			position2(sen2, &A);
		}
	}
	return 0;
}

int position1(sensor* sen, QD* ptr) {
	//value_a's QDev
	ptr->Q1 = sen->value_a[ptr->xq1_1];
	ptr->Q3 = sen->value_a[ptr->xq3_1];
	sen->Q_a = ptr->Q3 - ptr->Q1;
	//value_b's QDev
	ptr->Q1 = sen->value_b[ptr->xq1_1];
	ptr->Q3 = sen->value_b[ptr->xq3_1];
	sen->Q_b = ptr->Q3 - ptr->Q1;
	return 0;
}

int position2(sensor* sen, QD* ptr) {
	ptr->Q1 = 0.25 * sen->value_a[ptr->xq1_1] + 0.75 * sen->value_a[ptr->xq1_2];
	ptr->Q3 = 0.25 * sen->value_a[ptr->xq3_1] + 0.75 * sen->value_a[ptr->xq3_2];
	sen->Q_a = ptr->Q3 - ptr->Q1;
	
	ptr->Q1 = 0.25 * sen->value_b[ptr->xq1_1] + 0.75 * sen->value_b[ptr->xq1_2];
	ptr->Q3 = 0.25 * sen->value_b[ptr->xq3_1] + 0.75 * sen->value_b[ptr->xq3_2];
	sen->Q_b = ptr->Q3 - ptr->Q1;
	return 0;
}