#include "Solution2.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5
#define COLOR 3
void q2()
{
	//Solution2.h
	int mat[ROWS][COLS];
	int row;
	int col;
	printf("Mat portion: rows_%d,cols_%d \n", ROWS, COLS);
	initMatZero((int *)mat, ROWS, COLS);
	printf("The color amount : %d \n", COLOR);
	printf("the  mat:    \n");
	printMat((int *)mat, ROWS, COLS);
	int startValues[COLOR][2];
	for (int i = 0; i < COLOR; i++)
	{
		
	}
}