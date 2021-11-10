#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>
#include "arrays.h"

void printArray(const int *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%5d", *arr);
		arr++;
	}

	printf("\n");
}
void printCharArray(const char *arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%5c", *arr);
		arr++;
	}

	printf("\n");
}
void initArray(int *arr, int size)
{
	int i;
	printf("Please enter %d elements for array\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", arr);
		arr++;
	}
}

void initArrayChar(char *arr, int size)
{
	int i;
	printf("Please enter %d elements for array\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%c", arr);
		arr++;
	}
}

void printMat(const int *mat, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%5d", *mat);
			mat++;
		}
		printf("\n");
	}
	printf("\n");
}
void printMatChar(const char *mat, int rows, int cols)
{
	int i, j;
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			printf("%5c", *mat);
			mat++;
		}
		printf("\n");
	}
	printf("\n");
}

void initMat(int *mat, int rows, int cols)
{
	int i, j;

	printf("Please enter %d numbers to matrix\n", cols * rows);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", mat);
			mat++;
		}
	}
}
void initMatRand(int *mat, int rows, int cols)
{
	int i, j;
	srand(time(NULL)); // initialize random seed
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			*mat = 1 + (rand() % (5 - (1) + 1));
			mat++;
		}
	}
}
void initMatZero(int *mat, int rows, int cols)
{
	int i, j;
	srand(time(NULL)); // initialize random seed
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			*mat = 0;
			mat++;
		}
	}
}
void initMatChar(char *mat, int rows, int cols)
{
	int i, j;

	printf("Please enter %d numbers to matrix\n", cols * rows);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%c", mat);
			mat++;
		}
	}
}
