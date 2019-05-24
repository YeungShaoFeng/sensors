#include "rearrange.h"

//func rearrange
void rearrange(sensor* sen1, sensor* sen2) {
	//rearenge the values in the values array
	//from the least to the greatest
	rearrange_step(sen1);
	if (sen2 != NULL) {
		rearrange_step(sen2);
	}
}

void rearrange_step(sensor* sen) {
	int i, j, temp, isSorted;
	//The average_a of the sensor obj
	for (i = 0; i < length - 1; i++) {
		isSorted = 1;
		for (j = 0; j < length - 1 - i; j++) {
			if (sen->value_a[j] > sen->value_a[j + 1]) {
				temp = sen->value_a[j];
				sen->value_a[j] = sen->value_a[j + 1];
				sen->value_a[j + 1] = temp;
				isSorted = 0;
			}
		}
		if (isSorted) break;
	}
	//The average_b of the sensor obj
	for (i = 0; i < length - 1; i++) {
		isSorted = 1;
		for (j = 0; j < length - 1 - i; j++) {
			if (sen->value_b[j] > sen->value_b[j + 1]) {
				temp = sen->value_b[j];
				sen->value_b[j] = sen->value_b[j + 1];
				sen->value_b[j + 1] = temp;
				isSorted = 0;
			}
		}
		if (isSorted) break;
	}
}