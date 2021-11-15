#include "Solution2.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 6
#define COLOR 3
#define VALUESCOL 2

void colorStartPoints(int *mat, int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{
		int row = *(startValues + (VALUESCOL * i) + 0);
		int col = *(startValues + (VALUESCOL * i) + 1);
		int *currentColorPlace = mat + (row * COLS) + col;
		*currentColorPlace = i + 1;
	}
	printf("\nthe  mat firts painted:    \n");
	printMat((int *)mat, ROWS, COLS);
}

int checkIfPointExist(int *startValues, int row, int col, int i)
{
	for (int j = 0; j < i; j++)
	{
		int checkRow = *(startValues + j * 2);
		int checkCol = *(startValues + j * 2 + 1);
		if (checkRow == row && checkCol == col)
		{
			return 0;
		}
	}
	return 1;
}

void initStartValues(int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{

		int row = getRand(0, ROWS - 1);
		int col = getRand(0, COLS - 1);
		while (checkIfPointExist((int *)startValues, row, col, i + 1) == 0)
		{
			row = getRand(0, ROWS - 1);
			col = getRand(0, COLS - 1);
		}
		int *pointerRow = startValues + (VALUESCOL * i) + 0;
		int *pointerCol = startValues + (VALUESCOL * i) + 1;
		*pointerRow = row;
		*pointerCol = col;
	}
}
void printStartValues(int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{

		int *pointerRow = startValues + (VALUESCOL * i) + 0;
		int *pointerCol = startValues + (VALUESCOL * i) + 1;

		printf("color number [[%d]] starts :\n\trow --%d--\n\tcol --%d--\n", (i + 1), *pointerRow, *pointerCol);
	}
}
int checkColorAmount()
{
	if (COLOR > COLS * ROWS)
		return 0;
	return 1;
}
void q2()
{
	//Solution2.h
	if (checkColorAmount() == 0)
	{
		printf("Too much colors for the mat");
		return;
	}
	int mat[ROWS][COLS];
	printf("Mat portion: rows_%d,cols_%d \n", ROWS, COLS);
	initMatZero((int *)mat, ROWS, COLS);
	printf("The color amount : %d \n", COLOR);
	printf("the  mat:    \n");
	printMat((int *)mat, ROWS, COLS);
	int startValues[COLOR][2];
	initStartValues((int *)startValues);
	printStartValues((int *)startValues);
	colorStartPoints((int *)mat, (int *)startValues);

	//colorTheBoard((int*)mat,(int *)startValues);
}
