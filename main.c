#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "matrix.h"

#define SQR_SIZE 7


int main(void){

	struct Matrix test;

	// initMat(&test,12,12);
	initMat(&test,SQR_SIZE,SQR_SIZE);
	uint8_t i,j;
	for(i = 0; i < SQR_SIZE; i++){
		for(j = 0; j < SQR_SIZE; j++){
			matElementAssign(&test,i,j,1.0);
		}
	}

	printf("Created Matrix\n");
	fflush(stdout);


	printf("Assigned elements\n");
	fflush(stdout);

	printMat(&test);
	printf("Det is %f\n",findDet(&test));

	delMat(&test);

}