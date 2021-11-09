#include <stdio.h>
#include <ctype.h>
#include "arrays.h"
#include "Solution1.h"
#include "Solution2.h"
#include "Solution3.h"
#include "Utill.h"
#include "exe.h"

#define ROWS 5
#define COLS 5
#define COLOR 3

void q1()
{
	//Solution1.h
	int sum = 0;
	printf("you chose Q1, get ready to be amazed\n");
	printf("Mat portion: rows_%d,cols_%d \n", ROWS, COLS);
	int rowBM, colBM, rowSM, colSM;
	int indexOfRow, indexOfCol;
	while (Q1_Menu(&rowBM, &colBM, &rowSM, &colSM, ROWS, COLS) == -1)
	{
		//menu is running
	}
	int mat[ROWS][COLS];
	initMatRand((int *)mat, rowBM, colBM);
	printf("the big mat:    \n");
	printMat((int *)mat, rowBM, colBM);
	sum = Q1_doFindMaxSubMatrix((int *)mat, rowBM, colBM, rowSM, colSM, &indexOfRow, &indexOfCol);
	printf("\n the sum is :   %d  \n and it starts in row index:%d\n and col index:%d\n", sum, indexOfRow, indexOfCol);
	printSmallMat(((int *)mat) + (colSM * indexOfRow) + indexOfCol, rowSM, colSM, colBM);
}

void q2()
{
	//Solution2.h
	int mat[ROWS][COLS];
	printf("Mat portion: rows_%d,cols_%d \n", ROWS, COLS);
	initMatZero((int *)mat, ROWS, COLS);
	printf("The color amount : %d \n", COLOR);
	printf("the  mat:    \n");
	printMat((int *)mat, ROWS, COLS);
	//int startValues[COLOR][2];
}

void q3()
{
	//Solution3.h
	printf("houston we have a problem  the user chose Q3\n");
}
