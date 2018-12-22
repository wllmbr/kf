#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#include "matrix.h"


int main(void){

	struct Matrix *test;
	test = (struct Matrix *)malloc(sizeof(struct Matrix));

	initMat(test,2,2);

	printf("Created Matrix\n");
	fflush(stdout);

	matElementAssign(test,0,0,1);
	matElementAssign(test,0,1,2);
	matElementAssign(test,1,0,3);
	matElementAssign(test,1,1,4);

	printf("Assigned elements\n");
	fflush(stdout);

	printf("%f\t", matElementAccess(test,0,0));
	printf("%f\t", matElementAccess(test,0,1));
	printf("\n");
	printf("%f\t", matElementAccess(test,1,0));
	printf("%f\t", matElementAccess(test,1,1));
	printf("\n");

}