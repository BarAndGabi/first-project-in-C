#include <stdio.h>
#include <ctype.h>

#include "Utill.h"

void intSwap(int *pa, int *pb)
{
    int temp = *pa;
    *pa = *pb;
    *pb = temp;
}
