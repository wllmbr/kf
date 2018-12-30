#ifndef MATRIX_H
#define MATRIX_H

#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

struct Matrix{
	uint8_t rowLen;
	uint8_t colLen;
	double  *mat;
};

void initMat(struct Matrix *a, uint8_t numRow, uint8_t numCol);
void delMat(struct Matrix *a);

double matElementAccess(struct Matrix *a, uint8_t row, uint8_t col);
void matElementAssign(struct Matrix *a, uint8_t row, uint8_t col, double val);

void mulMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void addMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void subMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);
void divMat(struct Matrix *c, struct Matrix *a, struct Matrix *b);

double findDet(struct Matrix *a);

void scalMult(double s, struct Matrix *a);

void printMat(struct Matrix *a);

#endif