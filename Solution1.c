#include "Solution1.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

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
	if (*rowSM >= *rowBM)
	{
		printf("small rows to big, try again\n");
		return -1;
	}

	printf("COLS:	");
	scanf("%d", colSM);
	if (*colSM >= *colBM)
	{
		printf("small cols to big, try again\n");
		return -1;
	}
	printf("Your SMALL mat portion: rows_%d,cols_%d \n", *rowSM, *colSM);
	return 0;
}

int Q1_doFindMaxSubMatrix(int *mat, int BMrow, int BMcol, int SMrow, int SMcol)
{
	int temp, currentSum;
	currentSum = 0;

	for (int i = 0; i < BMrow - SMrow + 1; i++)
	{
		for (int j = 0; j < BMcol - SMcol + 1; j++)
		{
			temp = sumSmallMat((int *)mat, SMrow, SMcol, BMcol);
			if (currentSum < temp)
			{
				currentSum = temp;
			}
			mat++;
		}
	}

	return currentSum;
}
