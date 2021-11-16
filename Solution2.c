#include "Solution2.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 6
#define COLOR 2
#define VALUESCOL 2

int expandRows(int *mat, int row, int col, int color, int round)
{
	int counter = 0;
	int coloredMatSize = 3 + ((round - 1) * 2);
	for (int i = col; i < coloredMatSize + col; i++)
	{
		if (i >= 0 && i < COLS)
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
	for (int i = row; i < coloredMatSize + row; i++)
	{
		if (i >= 0 && i < ROWS)
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
	if (row >= 0)
		counter += expandRows(mat, row, col, color, round); //expand row above
	if (row + coloredMatSize - 1 < ROWS)
		counter += expandRows(mat, row + coloredMatSize - 1, col, color, round); //expand row under
	if (col >= 0)
		counter += expandCols(mat, row, col, color, round); //expand left col
	if (col + coloredMatSize - 1 < COLS)
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
void colorTheBoard(int *mat, int *startValues)
{
	int round = 1;
	int counter = 3;//3 slots have been painted at start.
	while (round <= COLS || round <= ROWS)
	{
		for (int color = 0; color < COLOR; color++)
		{
			int *pointerRow = startValues + (VALUESCOL * color) + 0;
			int *pointerCol = startValues + (VALUESCOL * color) + 1;
			counter = counter + expandColor((int *)mat, *pointerRow, *pointerCol, color + 1, round);
		}
		printf("ROUND  _--%d--_   \n", round);
		printMat((int *)mat, ROWS, COLS);
		if (counter > COLS * ROWS)
			break;
		round++;
	}
}
void q2SetUP(int *mat, int *startValues)
{
	printf("Mat portion: rows_%d,cols_%d \n", ROWS, COLS);
	initMatZero(mat, ROWS, COLS);
	printf("The color amount : %d \n", COLOR);
	printf("the  mat:    \n");
	printMat(mat, ROWS, COLS);
	initStartValues(startValues);
	printStartValues(startValues);
	colorStartPoints((int *)mat, (int *)startValues);
}
void q2()
{
	if (checkColorAmount() == 0)
	{
		printf("Too much colors for the mat");
		return;
	}
	int startValues[COLOR][2];
	int mat[ROWS][COLS];
	q2SetUP((int *)mat, (int *)startValues);
	colorTheBoard((int *)mat, (int *)startValues);
}
