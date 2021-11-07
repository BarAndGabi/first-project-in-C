#include <stdio.h>
#include <ctype.h>

#include "arrays.h"
 
void	printArray(const int* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%5d", *arr);
		arr++;
	}

	printf("\n");
}
void	printCharArray(const char* arr, int size)
{
	int i;
	for (i = 0; i < size; i++)
	{
		printf("%5c", *arr);
		arr++;
	}

	printf("\n");

}
void	initArray(int* arr, int size)
{
	int i;
	printf("Please enter %d elements for array\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", arr);
		arr++;
	}
}
 void	initArratRand(int* arr, int size)
{
	int i;
	printf("Please enter %d elements for array\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%d", arr);
		arr++;
	}
}
void	initArrayChar(char* arr, int size)
{
	int i;
	printf("Please enter %d elements for array\n", size);
	for (i = 0; i < size; i++)
	{
		scanf("%c", arr);
		arr++;
	}
}
 

void	printMat(const int* mat, int rows, int cols)
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
void	printMatChar(const char* mat, int rows, int cols)
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

void	initMat(int* mat, int rows, int cols)
{
	int i, j;

	printf("Please enter %d numbers to matrix\n", cols*rows);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%d", mat);
			mat++;
		}
	}
}
void	initMatChar(char* mat, int rows, int cols)
{
	int i, j;

	printf("Please enter %d numbers to matrix\n", cols*rows);
	for (i = 0; i < rows; i++)
	{
		for (j = 0; j < cols; j++)
		{
			scanf("%c", mat);
			mat++;
		}
	}
}
int	sumMat(int* mat, int rows, int cols,int bigRows)
{//sums the smallmat within the big mat
	int temp=0;
	int sum=0;
	for (int i=0;i<rows;i++)
		for(int j=0;j<cols;j++)
		{
		temp=*((mat+(bigRows*i)+j));
		sum=sum+temp;	
		}
	printf("\n\nthe answer:	%d \n",sum);
return 0;
}





