#include "Solution3.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5
#define LEFTCOLS ((COLS + 1) / 2)

int checkRowZero(int *row, int size)
{
	for (int col = 0; col < size; col++)
	{
		int currentValue = *(row + col);
		if (currentValue != 0)
			return 0;
	}
	return 1;
}
int checkZeroCases(int *row, int *colIndex)
{
	if (*colIndex % COLS == 0)
		while (*row == 0)
		{
			row++;
			*colIndex += 1;
		}
	else
	{
		do
		{
			if (*row != 0)
				return 0;
			row++;
			*colIndex += 1;
		} while (*row == 0);
	}
	return 1;
}
int checkRowColor(int *row, int currentLenth, int *colIndex, int* blackCounter)
{
	if (checkZeroCases((int *)(row + *colIndex), colIndex) == 1)
	{
		if (*colIndex >= COLS)
			return *colIndex;
		row += *colIndex;
		for (int i = 0; i < currentLenth; i++)
		{
			if (*row == 0)
				return 0;
			*blackCounter += 1;
			row++;
			*colIndex += 1;
		}
		return 1;
	}
	return 0;
}

int checkRow(int *row, int *leftNumCol)
{
	int lenthSum = 0;
	int blackCounter = 0;
	int colIndex = 0;
	for (int j = 0; j < (COLS + 1) / 2; j++)
	{
		lenthSum += *leftNumCol;
		leftNumCol++;
	}
	if (lenthSum > COLS)
		return 0;
	else if (lenthSum == 0)
		return checkRowZero(row, COLS);
	leftNumCol -= ((COLS + 1) / 2);
	for (int j = 0; j < LEFTCOLS; j++)
	{
		if (*leftNumCol == 0)
			leftNumCol++;
		else
		{
			if (checkRowColor(row, *leftNumCol, &colIndex, &blackCounter) == 0)
				return 0;
			leftNumCol++;
		}
	}
	if (colIndex < COLS)
		if (checkRowColor(row, 0, &colIndex, &blackCounter) == 0)
			return 0;

	if (blackCounter != lenthSum){

return 0;

}
	return 1;
}

void printRow(int *row, int *leftNumsRow)
{
	printf("\nrow is :    ");
	printArray(row, COLS);
	printf("\nLEFFNUMS is :    ");
	printArray(leftNumsRow, ((COLS + 1) / 2));
	printf("\n");
}
int checkBoard(int *mat, int *leftNums)
{
	for (int row = 0; row < ROWS; row++)
	{
		printRow(mat + (row * COLS), leftNums + (row * LEFTCOLS)); //checked row send (its good).
		if (0 == checkRow(mat + (row * COLS), leftNums + (row * LEFTCOLS)))
			return 0;
	}
	return 1;
}
void q3SetUp(int *mat, int *leftNums)
{
	printf("The  game board:    \n");
	printMat(mat, ROWS, COLS);
	printf("The  left nums:    \n");
	printMat(leftNums, ROWS, (COLS + 1) / 2);
}
void printAnswer(int answerBool)
{
	if (answerBool == 0)
		printf("\n--------ANSWER IS FALSE--------\n");
	else
		printf("\n--------ANSWER IS TRUE--------\n");
}

void q3()
{
	printf("houston we have a problem  the user chose Q3\n");
	int mat[ROWS][COLS] = {{0, 0, 0, 0, 0}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 1, 0, 1, 1}, {1, 1, 1, 1, 1}};
	int leftNums[ROWS][(COLS + 1) / 2] = {{0, 0, 0}, {1, 1, 1}, {3, 0, 0}, {0, 2, 2}, {3, 0, 1}};
	q3SetUp((int *)mat, (int *)leftNums);
	int answerBool = checkBoard((int *)mat, (int *)leftNums);
	printAnswer(answerBool);
}
