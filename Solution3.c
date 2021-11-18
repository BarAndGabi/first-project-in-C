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

int checkRow(int *row, int *leftNumsRow)
{
	for(int i=0;i<((COLS + 1) / 2);i++)
{
}

return 0;
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
		printRow(mat + (row * COLS), leftNums + (row * ((COLS + 1) / 2))); checked row send (its good).
		if (0 == checkRow(mat + (row * COLS), leftNums + (row * COLS)))
			return 0;
	}
	return 1;
}
void q3()
{
	printf("houston we have a problem  the user chose Q3\n");
	int mat[ROWS][COLS] = {{1, 1, 1, 1, 1}, {1, 0, 1, 0, 1}, {0, 1, 1, 1, 0}, {1, 1, 0, 1, 1}, {1, 1, 1, 1, 1}};
	int leftNums[ROWS][(COLS + 1) / 2] = {{0, 0, 5}, {1, 1, 1}, {0, 3, 0}, {0, 2, 2}, {0, 0, 5}};
	q3SetUp((int *)mat, (int *)leftNums);
	int answerBool = checkBoard((int *)mat, (int *)leftNums);
	printAnswer(answerBool);
}
