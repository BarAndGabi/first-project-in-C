#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <time.h>

#include "Utill.h"

void intSwap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;//TRY
}
int getRand(int min,int max){
    return min + (rand() % (max - (min) + 1));
}
