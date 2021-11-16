#include "Solution2.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>

#define ROWS 5
#define COLS 5
#define COLOR 3
int checkIfPointExist(startValues, row, col)
{
		for(int j=0;j<COLOR;j++){
			int checkRow=*(startValues+j*2);
			int checkCol=*(startValues+j*2+1);
			if(checkRow==row&&checkRowCol==col){
               return 0;
			}
		}
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
		int *pointerRow = startValues + (2 * i) + 0;
		int *pointerCol = startValues + (2 * i) + 1;
		*pointerRow = row;
		*pointerCol = col;
	}
}
void printStartValues(int *startValues)
{
	for (int i = 0; i < COLOR; i++)
	{
		int *pointerRow = startValues + (2 * i) + 0;
		int *pointerCol = startValues + (2 * i) + 1;
		printf("color number [[%d]] starts :\n\trow --%d--\n\tcol --%d--\n", (i + 1), *pointerRow, *pointerCol);
	}
}


<<<<<<< Updated upstream
int expandColor(int* mat,int matRow,int matCol,int pointerRow,int pointerCol,int colorNum,int turnNum){


=======
int expandColor(int* mat,int matRow,int matCol,int startRow,int startCol,int colorNum,int turnNum){
    int upRow,downRow,leftCol,rightCol,counter;
	counter=0;
    upRow=startRow-turnNum;
    downRow=startRow+turnNum;
    leftCol=startCol-turnNum;
    rightCol=startCol+turnNum;
    if(upRow<0){
     upRow=0;
    }
    else if(downRow>matRow){
    downRow=matRow;
    }
    else if(leftCol<0){
    leftCol=0;
    }
    else if(rightCol>matCol){
    rightCol=matCol;
    }
    for(int i=upRow;i<=downRow;i++){
        for(int j=leftCol;j<=rightCol;j++){
         if(*(mat+i*matCol+j)==0){
            *(mat+i*matCol+j)=colorNum;
             counter++;
          }  
         } 
        }
    return counter;
}




void colorTheBoard( int* mat,int matRow,int matCol,int* startValues,int colors){
    int sum,turnNum;
    turnNum=1;
while(sum<(matRow*matCol-colors)){
     for(int i=0;i<colors;i++){
        int startRow=*(startValues+VALUESCOL*i);
        int startCol=*(startValues+VALUESCOL*i+1);  
        sum=sum+expandColor((int*) mat,matRow,matCol,startRow,startCol,i+1,turnNum);
  } 
  printMat((int *)mat, matRow, matCol);
  printf("\nthe turn is:%d",turnNum);
  turnNum++;  
  }
>>>>>>> Stashed changes
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
<<<<<<< Updated upstream
=======
	colorStartPoints((int*)mat,(int *)startValues);

	//colorTheBoard((int*)mat,(int *)startValues);

>>>>>>> Stashed changes
}
