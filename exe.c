#include <stdio.h>
#include <ctype.h>
#include "arrays.h"
#include "Solution1.h"
#include "Utill.h"
#include "exe.h"

#define SIZE 6
#define ROWS 5
#define COLS 3


void q1()
{
	int a[3][3] ={{13,-47,36},{-46,50,50},{4,50,49}};
	sumMat(a, 2, 2);
	int rowBM,colBM,rowSM,colSMl;
	printf("you chose Q1, get ready to be amazed\n");
	printf("you need to tell me how many rows and cols you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowBM);
	printf("COLS:	");
	scanf("%d",colBM);
	printf("Now tell me the portionof the small mat you would like:  \n");
	printf("ROWS:	");
	scanf("%d",rowSM);
	printf("COLS:	");
	scanf("%d",colSM);
		
}

void q2()
{
	printf("you chose Q2, your'e about to be sent to outter space\n");	
}

void q3()
{
	printf("houston we have a problem  the user chose Q3\n");	
}





