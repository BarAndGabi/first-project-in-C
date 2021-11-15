#include "Solution2.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5
#define COLOR 3
#define VALUESCOL 2

int expandRows(int *mat, int row, int col, int color, int round)
{
	int counter = 0;
	int coloredMatSize = 3 + ((round - 1) * 2);
	for (int i = col; i < coloredMatSize + col; i++)
	{
		if (i >= 0)
		{
			int *currentPointer = mat + (row * COLS) + i;
			if (*currentPointer == 0)
			{
				*currentPointer = color;
				counter++;
			}
		}
	}
	return counter;
}
int expandCols(int *mat, int row, int col, int color, int round)
{
	int counter = 0;
	int coloredMatSize = 3 + ((round - 1) * 2);
	for (int i = row + 1; i < coloredMatSize - 1 + row; i++)
	{
		if (i >= 0)
		{
			int *currentPointer = mat + (i * COLS) + col;
			if (*currentPointer == 0)
			{
				*currentPointer = color;
				counter++;
			}
		}
	}
	return counter;
}

int expandColor(int *mat, int row, int col, int color, int round)
{
	row = row - round;
	col = col - round;
	int counter = 0;
	int coloredMatSize = 3 + ((round - 1) * 2);
	counter += expandRows(mat, row, col, color, round);						 //expand row above
	counter += expandRows(mat, row + coloredMatSize - 1, col, color, round); //expand row under
	counter += expandCols(mat, row, col, color, round);						 //expand left col
	counter += expandCols(mat, row, col + coloredMatSize - 1, color, round); //expand RIGHT COL
	return counter;
}

void colorStartPoints(int *mat, int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{
		int row = *(startValues + (VALUESCOL * i) + 0);
		int col = *(startValues + (VALUESCOL * i) + 1);
		int *currentColorPlace = mat + (row * COLS) + col;
		*currentColorPlace = i + 1;
	}
	printf("\nthe  mat firsts painted:    \n");
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
	int row = 2;
	int col = 2;
	for (int i = 0; i < COLOR; i++)
	{

		//int row = getRand(0, ROWS - 1);
		//int col = getRand(0, COLS - 1);
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
	printf("\n\n%d\n", expandColor((int *)mat, 2, 2, 1, 1));
	printMat((int *)mat, ROWS, COLS);
	//colorTheBoard((int*)mat,(int *)startValues);
}
