#include <stdio.h>
#include <ctype.h>
#include "arrays.h"
#include "Solution1.h"
#include "Utill.h"
#include "exe.h"

#define SIZE 6
#define ROWS 5
#define COLS 3

void q1Menu(int* rowBM,int* colBM,int* rowSM,int* colSM)
{
printf("you need to tell me how many rows and cols you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowBM);
	printf("COLS:	");
	scanf("%d",colBM);
	printf("Now tell me the portion of the small mat you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowSM);
	printf("COLS:	");
	scanf("%d",colSM);
}
void q1()
{
	printf("you chose Q1, get ready to be amazed\n");
	int rowBM,colBM,rowSM,colSM;
	q1Menu(&rowBM,&colBM,&rowSM,&colSM);
	int mat[rowBM][colBM];
	initMatRand((int*) mat,  rowBM,  colBM);
	printMat((int*) mat,  rowBM,  colBM);	
		
}

void q2()
{
	printf("you chose Q2, your'e about to be sent to outter space\n");	
}

void q3()
{
	printf("houston we have a problem  the user chose Q3\n");	
}





