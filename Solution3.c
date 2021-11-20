#include "Solution3.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5
#define LEFTCOLS ((COLS + 1) / 2)

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
int checkUntilZero(int *row, int currentLenth, int start)
{
	if (currentLenth == 0)
		return start;
	int counterBlack = 0;
	for (int i = start; i < COLS; i++)
	{
		int currentValue = *(row + i);
		if (counterBlack == currentLenth)
		{
			printf("\n%d ) ====> \ncurrentValue =====> %d\n", i, currentValue);
			return i;
		}
		if (currentValue == 0)
		{
			if (counterBlack == currentLenth)
				return i;
			if (counterBlack > currentLenth)
				return -1;
			if (counterBlack < currentLenth && counterBlack > 0)
				return -1;
		}
		else
		{
			printf("\n%d ) ====> \ncurrentValue =====> %d\n", currentLenth, currentValue);
			if (counterBlack < currentLenth && counterBlack >= 0)
				counterBlack++;
			if (counterBlack > currentLenth)
				return -1;
			if (counterBlack == currentLenth)
				return i + 1;
		}
	}
	if (counterBlack == 0)
		return start;
	if (counterBlack == currentLenth)
		return COLS;
	if (counterBlack < currentLenth || counterBlack > currentLenth)
		return -1;

	return start;
}
int checkRowZero(int *row)
{
	for (int col = 0; col < COLS; col++)
	{
		int currentValue = *(row + col);
		if (currentValue != 0)
			return -1;
	}
	return 1;
}
int checkRow(int *row, int *leftNumsRow)
{
	int start = 0;
	int temp = 0;
	for (int col = 0; col < ((COLS + 1) / 2); col++)
	{
		int *current = leftNumsRow + col;
		int currentLenth = *current;
		printf("\n%d ) ====> \nSTART IS =====> %d\n", col + 1, start);
		temp = checkUntilZero(row, currentLenth, start);
		if (temp == -1)
		{
			return 0;
		}
		if (temp == COLS)
			return 1;
		start = temp;
	}
	if (start != -1)
	{
		if (start == 0)
		{
			if (checkRowZero(row) > 0)
				return 1;
			else
				return 0;
		}
		if (start == temp)
			return 0;
		else
			return 1;
	}
	else
	{
		return 0;
	}
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
		printRow(mat + (row * COLS), leftNums + (row * ((COLS + 1) / 2))); //checked row send (its good).
		if (0 == checkRow(mat + (row * COLS), leftNums + (row * ((COLS + 1) / 2))))
			return 0;
	}
	return 1;
}
void q3()
{
	printf("houston we have a problem  the user chose Q3\n");
	int mat[ROWS][COLS] = {{0, 0, 0, 0, 1}, {0, 0, 0, 0, 1}, {0, 1, 1, 1, 0}, {1, 1, 0, 1, 1}, {1, 1, 1, 1, 1}};
	int leftNums[ROWS][(COLS + 1) / 2] = {{0, 0, 1}, {0, 0, 1}, {3, 0, 1}, {0, 2, 2}, {0, 0, 5}};
	q3SetUp((int *)mat, (int *)leftNums);
	int answerBool = checkBoard((int *)mat, (int *)leftNums);
	printAnswer(answerBool);
}
