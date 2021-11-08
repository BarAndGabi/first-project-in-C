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

int q1Menu(int* rowBM,int* colBM,int* rowSM,int* colSM)
{
	
	printf("you need to tell me how many rows and cols you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowBM);
	if(*rowBM > ROWS)
	{
		printf(" rows to big, try again\n");
		return -1;
	}
	printf("COLS:	");
	scanf("%d",colBM);
	if(*colBM > COLS)
	{
		printf(" rows to big, try again\n");
		return -1;
	}
	printf("Now tell me the portion of the small mat you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowSM);
	if(*rowSM >= *rowBM)
	{
		printf("small rows to big, try again\n");
		return -1;
	}

	printf("COLS:	");
	scanf("%d",colSM);
	if(*colSM >= *colBM)
	{
		printf("small cols to big, try again\n");
		return -1;
	}
	return 0;
	
}
void q1()
{
	//Solution1.h
	int sum=0;
	printf("you chose Q1, get ready to be amazed\n");
	int rowBM,colBM,rowSM,colSM;
	while(q1Menu(&rowBM,&colBM,&rowSM,&colSM)==-1)
{
	}
	int mat[ROWS][COLS];
	initMatRand((int*) mat,  rowBM,  colBM);
	printf("the big mat:    \n");
	printMat((int*) mat,  rowBM,  colBM);
	sum=Q1_doFindMaxSubMatrix((int*) mat, rowBM, colBM, rowSM, colSM);
	printf("\n the sum is :   %d  \n",sum);	
		
}

void q2()
{
	//Solution2.h
	printf("you chose Q2, your'e about to be sent to outter space\n");	
}

void q3()
{
	//Solution3.h
	printf("houston we have a problem  the user chose Q3\n");	
}





