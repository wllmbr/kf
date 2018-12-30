#include "matrix.h"


void initMat(struct Matrix *a, uint8_t numRow, uint8_t numCol){

	a->rowLen = numRow;
	a->colLen = numCol;
	a->mat = (double *)malloc(sizeof(double) * numRow * numCol);
}

void delMat(struct Matrix *a){
	free(a->mat);
	return;
}


double matElementAccess(struct Matrix *a, uint8_t row, uint8_t col){
	// uint64_t index = (row + (col * a->rowLen)) * sizeof(double);
	uint64_t index = a->rowLen;
	index *= col;
	index += row;
	index *= sizeof(double);
	// printf("Accessing Memory Index %016llx\n", index);
	// fflush(stdout);
	double val = *(a->mat + index);
	// printf("Retrieved val %f",val);
	return val;
}
void matElementAssign(struct Matrix *a, uint8_t row, uint8_t col, double val){
	// uint16_t index = (row + (col * a->rowLen)) * sizeof(double);
	uint64_t index = a->rowLen;
	index *= col;
	index += row;
	index *= sizeof(double);
	// printf("Accessing Memory Index %016llx\n", index);
	// fflush(stdout);
	*(a->mat + index) = val;
}

void mulMat(struct Matrix *c, struct Matrix *a, struct Matrix *b){
	uint8_t row, col, i;

	if((a->colLen != b->rowLen) && (c->rowLen != a->rowLen) && (c->colLen != b->colLen)){
		printf("Matrix Dimensions don't agree\n");
		return;
	}
}

void addMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void subMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void divMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);

void invMat(struct Matrix *b, struct Matrix *a){
	/* Find matrix det, then scale the matrix A, place in B*/
	double matDet = findDet(a);
}

double findDet(struct Matrix *a){

	// printf("Working with Matrix: \n");
	// printMat(a);


	if(a->rowLen == 2){
		/* Solve simple 2x2 solution */
		double tbtd = ((matElementAccess(a,0,0)*matElementAccess(a,1,1)) - (matElementAccess(a,1,0)*matElementAccess(a,0,1)));
		// printf("Founrd 2x2 Det: %f\n", tbtd);
		return tbtd;
	} else {
		/* Recurvisevly hunt for 2x2 solutions */
		struct Matrix newMatrix;
		initMat(&newMatrix,a->rowLen -1, a->colLen-1);

		double detAccumulator = 0;
		uint8_t i;
		uint8_t colAdjust = 0;
		for(i = 0; i < a->rowLen; i++){

			/* If the scaler to be multiplied is 0, skip this step */
			if(matElementAccess(a,0,i) == 0){
				continue;
			}

			/* Construct new matrix */
			uint8_t row, col;
			for(row = 1; row < a->rowLen; row++){
				colAdjust = 0;
				for(col = 0; col < a->colLen; col++){
					/* Make sure we're only copying the correct values */
					if( col != i){
						matElementAssign(&newMatrix, row - 1, col - colAdjust, matElementAccess(a,row,col));
					} else {
						colAdjust = 1;
					}
				}
			}

			/* Find Determinant of new matrix */
			double subDet = findDet(&newMatrix);

			/* Create Det Component */
			subDet *= matElementAccess(a,0,i);

			/* Based upon index, determine if it needs to be added, or subtracted */
			if((i & 1) != 0){
				detAccumulator -= subDet;
			} else {
				detAccumulator += subDet;
			}
		}

		/* Delete "new" Matrix space */
		delMat(&newMatrix);

		return detAccumulator;
	}
}


void scalMult(double s, struct Matrix *a){
}

void printMat(struct Matrix *a){
	uint8_t r,c;
	printf("\n");
	for(r = 0; r < a->rowLen; r++){
		for(c = 0; c < a->colLen; c++){
			printf("%f\t",matElementAccess(a,r,c));
		}
		printf("\n");
	}
}