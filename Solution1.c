#include "Solution1.h"
#include "Utill.h"
#include "arrays.h"
#include <stdio.h>


int Q1_doFindMaxSubMatrix(int* mat,int BMrow,int BMcol,int SMrow,int SMcol){
    int temp,currentSum;
    currentSum=0;

    for(int i=0;i<BMrow-SMrow+1;i++){
        for(int j=0;j<BMcol-SMcol+1;j++){
         temp=sumSmallMat((int*)mat,SMrow, SMcol,BMcol);
         if(currentSum<temp){
         currentSum=temp;
	
         }
         mat++;
       }
     }

      return currentSum;
}





































