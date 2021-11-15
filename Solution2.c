#include "Solution2.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5
#define COLOR 3
int checkIfPointExist(startValues, row, col)
{
    int check;
		for(int j=0;j<COLOR;j++){
			int checkRow=*(startValues+j*2);
			int checkCol=*(startValues+j*2+1);
			if(checkRow==row&&checkRowCol==col){
               check=0;
			}
		}
		if(check=0)
		return 0;
		else
		return 1;
	}

}

void initStartValues(int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{
		int row = getRand(0, ROWS - 1);
		int col = getRand(0, COLS - 1);
		while (checkIfPointExist(startValues, row, col) == 1)
		{
			row = getRand(0, ROWS - 1);
			col = getRand(0, COLS - 1);
		}
		int *pointerRow = startValues + (COLS * i) + 0;
		int *pointerCol = startValues + (COLS * i) + 1;
		*pointerRow = row;
		*pointerCol = col;
	}
}
void printStartValues(int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{
		int *pointerRow = startValues + (COLS * i) + 0;
		int *pointerCol = startValues + (COLS * i) + 1;

		printf("color number [[%d]] starts :\n\trow --%d--\n\tcol --%d--\n", (i + 1), *pointerRow, *pointerCol);
	}
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
	int startValues[COLOR][2];
	initStartValues((int *)startValues);
	printStartValues((int *)startValues);
}
