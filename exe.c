#include <stdio.h>
#include <ctype.h>
#include "arrays.h"
#include "Solution1.h"
#include "Utill.h"
#include "exe.h"

#define ROWS 5
#define COLS 5

void q1Menu(int* rowBM,int* colBM,int* rowSM,int* colSM)
{
	int a=0;
	while(a=0)
	{
printf("you need to tell me how many rows and cols you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowBM);
	if(rowBM>ROWS)
	{
		a++;
		printf("small rows to big")
	}
	printf("COLS:	");
	scanf("%d",colBM);
	if(colBM>COLS)
	{
		a++;
		printf("small rows to big")
	}
	printf("Now tell me the portion of the small mat you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowSM);
	if(rowSM>rowBM)
	{
		a++;
		printf("small rows to big")
	}

	printf("COLS:	");
	scanf("%d",colSM);
		if(colSM>colBM)
	{
		a++;
		printf("small cols to big")
	}
	}
}
void q1()
{
	int answerROW,answerCOL;
	int sum=0;
	printf("you chose Q1, get ready to be amazed\n");
	int rowBM,colBM,rowSM,colSM;
	q1Menu(&rowBM,&colBM,&rowSM,&colSM);
	int mat[ROWS][COLS];
	initMatRand((int*) mat,  rowBM,  colBM);
	printf("the big mat:    \n");
	printMat((int*) mat,  rowBM,  colBM);
	sum=Q1_doFindMaxSubMatrix((int*) mat, rowBM, colBM, rowSM, colSM, &answerROW ,&answerCOL);
	printf("\n the sum is :   %d  \n",sum);	
		
}

void q2()
{
	printf("you chose Q2, your'e about to be sent to outter space\n");	
}

void q3()
{
	printf("houston we have a problem  the user chose Q3\n");	
}





