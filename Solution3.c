#include "Solution3.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5

void q3SetUp(int *mat, int *leftNums)
{
	printf("The  game board:    \n");
	printMat(mat, ROWS, COLS);
	printf("The  left nums:    \n");
	printMat(leftNums, ROWS, (COLS + 1) / 2);
}
void printAnswer(int answerBool)
{
	if(answerBool==0)
		printf("\n--------ANSWER IS FALSE--------\n");
	else
		printf("\n--------ANSWER IS TRUE--------\n");

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
