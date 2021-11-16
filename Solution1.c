#include "Solution1.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5

int Q1_Menu(int *rowBM, int *colBM, int *rowSM, int *colSM, int rows, int cols)
{

	if (Q1_bigMatChoose(rowBM, colBM, rows, cols) == -1)
		return -1;
	if (Q1_smallMatChoose(rowBM, colBM, rowSM, colSM) == -1)
		return -1;

	return 0;
}
int Q1_bigMatChoose(int *rowBM, int *colBM, int rows, int cols)
{
	printf("you need to tell me how many rows and cols you would like:  \n");
	printf("ROWS:	");
	scanf("%d", rowBM);
	if (*rowBM > rows)
	{
		printf(" rows to big, try again\n");
		return -1;
	}
	printf("COLS:	");
	scanf("%d", colBM);
	if (*colBM > cols)
	{
		printf(" rows to big, try again\n");
		return -1;
	}
	printf("Your big mat portion: rows_%d,cols_%d \n", *rowBM, *colBM);
	return 0;
}
int Q1_smallMatChoose(int *rowBM, int *colBM, int *rowSM, int *colSM)
{
	printf("Now tell me the portion of the small mat you would like:  \n");
	printf("ROWS:	");
	scanf("%d", rowSM);
	if (*rowSM > *rowBM)
	{
		printf("small rows to big, try again\n");
		return -1;
	}

	printf("COLS:	");
	scanf("%d", colSM);
	if (*colSM > *colBM)
	{
		printf("small cols to big, try again\n");
		return -1;
	}
	printf("Your SMALL mat portion: rows_%d,cols_%d \n", *rowSM, *colSM);
	return 0;
}
int Q1_doFindMaxSubMatrix(int *mat, int BMrow, int BMcol, int SMrow, int SMcol, int *indexRow, int *indexCol)
{
	int temp, currentSum;
	currentSum = 0;
	int row, col;

	for (int i = 0; i < BMrow; i++)
	{
		if (i + SMrow < BMrow)
			for (int j = 0; j < BMcol; j++)
			{
				if (j + SMcol < BMcol)
				{
					temp = sumSmallMat((int *)mat, SMrow, SMcol, BMcol); //FUNC in arrays.c
					if (currentSum < temp)
					{
						col = j;
						row = i;
						currentSum = temp;
					}
				}
				mat++;
			}
	}

	*indexCol = col;
	*indexRow = row;
	return currentSum;
}
int printSmallMat(int *mat, int rows, int cols, int bigRows)
{
	int temp = 0;
	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < cols; j++)
		{
			temp = *((mat + (bigRows * i) + j));
			printf("%5d ", temp);
		}
		printf("\n");
	}
	return 0;
}
void q1()
{
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
	printSmallMat(((int *)mat) + (colBM * indexOfRow) + indexOfCol, rowSM, colSM, colBM);
}
