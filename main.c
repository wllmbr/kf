#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "matrix.h"


int main(void){

	struct Matrix test;

	initMat(&test,3,3);

	printf("Created Matrix\n");
	fflush(stdout);

	matElementAssign(&test,0,0,1);
	matElementAssign(&test,0,1,2);
	matElementAssign(&test,0,2,3);
	matElementAssign(&test,1,0,4);
	matElementAssign(&test,1,1,5);
	matElementAssign(&test,1,2,6);
	matElementAssign(&test,2,0,7);
	matElementAssign(&test,2,1,9);
	matElementAssign(&test,2,2,9);

	printf("Assigned elements\n");
	fflush(stdout);

	printMat(&test);
	printf("Det is %f\n",findDet(&test));

}