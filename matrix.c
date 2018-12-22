#include "matrix.h"


void initMat(struct Matrix *a, uint8_t numRow, uint8_t numCol){

	a->rowLen = numRow;
	a->colLen = numCol;
	a->mat = (double *)malloc(sizeof(double) * numRow * numCol);
}


double matElementAccess(struct Matrix *a, uint8_t row, uint8_t col){
	// uint64_t index = (row + (col * a->rowLen)) * sizeof(double);
	uint64_t index = a->rowLen;
	index *= col;
	index += row;
	index *= sizeof(double);
	// printf("Accessing Memory Index %ld\n", index);
	fflush(stdout);
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
	// printf("Accessing Memory Index %d\n", index);
	fflush(stdout);
	*(a->mat + index) = val;
}

void mulMat(struct Matrix *c, struct Matrix *a, struct Matrix *b){
	uint8_t row, col, i;

	if((a->colLen != b->rowLen) && (c->rowLen != a->rowLen) && (c->colLen != b->colLen)){
		printf("Matrix Dimensions don't agree\n");
		return;
	}

	for(col = 0; col < )
}

void addMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void subMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void divMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);

void invMat(struct Matrix *b, struct Matrix *a){
	/* Find matrix det, then scale the matrix A, place in B*/
	double matDet = findDet(a);
}

double findDet(struct Matrix *a){

	double s = 1, det = 0, b[25][25];
	int i, j, m, n, c;
	if (k == 1)    {
		return (a[0][0]);
	} else {
		det = 0;
		for (c = 0; c < k; c++){
			m = 0;
			n = 0;
			for (i = 0;i < k; i++){
				for (j = 0 ;j < k; j++){
					b[i][j] = 0;
					if (i != 0 && j != c){
						b[m][n] = a[i][j];
						if (n < (k - 2)){
							n++;
						} else {
							n = 0;
							m++;
						}
					}
				}
			}
			det = det + s * (a[0][c] * determinant(b, k - 1));
			s = -1 * s;
		}
	}
	
	return (det);

}

void scalMult(double s, struct Matrix *a);

void printMat(struct Matrix *c);