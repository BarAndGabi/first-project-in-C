#include <stdio.h>
#include <ctype.h>
#include "arrays.h"
#include "arrays.h"
#include "functions4.h"
#include "exe.h"

#define SIZE 6
#define ROWS 5
#define COLS 3


void q_ReverseArr()
{
	int Arr[SIZE];	//Declare an array

	//call the function to insert values to the array
	initArray(Arr,SIZE);
	//call the function to print the array
	printArray(Arr,SIZE);

	reverseArray(Arr,SIZE);

	printf("array after reverse\n");
	printArray(Arr,SIZE);
}

#define COLS_Q 4
void q_PrintMat()
{
	int arr[] = {1,2,3,4,5,6};
	int mat[][COLS_Q] = {{1,2,3,4},{5,6,7,8},{9,10,11,12}};

	int rows = sizeof(mat)/(sizeof(int)*COLS_Q);
	printf("The array is\n");
	printMat(arr,1,sizeof(arr)/sizeof(int));
	printf("The matrix is\n");
	printMat((int*)mat,rows,COLS_Q);
}

void q_PrintArrReverse()
{
	int arr[] = {1,2,3,4,5,6};
	int size = sizeof(arr)/(sizeof(int));
	printf("The Original array is\n");
	printArray(arr,size);

	printf("\nPrint in reverse - method 1\n");
	printArrayRevers_Offset(arr,size);

	printf("\nPrint in reverse - method 2\n");
	printArrayRevers_WP(arr,size);
	printf("\n");
}

void q_PrintMixMatrix()
{
	int mat[ROWS][COLS];
	initMat((int*)mat,ROWS,COLS);
	int size1 = ROWS*COLS/2;
	int size2 = ROWS*COLS-size1;

	printf("The Original matrix is\n");
	printMat((int*)mat,ROWS,COLS);

	printf("The Mix reverse matrix is\n");
	printArrayRevers_Offset((int*)mat,size1);
	printArrayRevers_Offset((int*)mat+size1,size2);
	printf("\n");
}

void q_Palindrome()
{
	int res;
	int arr[] = {1,2,3,3,2,1};
	int size = sizeof(arr)/(sizeof(int));
	printf("The Original array is\n");
	printArray(arr,size);

	res = checkPalindromeArr(arr,size);
	if(res == 1)
		printf("This array is a palindrome\n");
	else

		printf("This array is NOT a palindrome\n");
}


