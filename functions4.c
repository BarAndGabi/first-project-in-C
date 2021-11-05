#include "functions4.h"


void reverseArray(int* arr,int size)
{
	int temp,i;

	for (i=0; i<size/2; i++)
	{
		temp = *(arr+i);
		*(arr+i) = *(arr+(size-1)-i);
		*(arr+(size-1)-i) = temp;
	}
}

int checkPalindromeArr(const int* arr,int size)
{
	const int* start = arr;
	const int* end = arr+size-1;

	while(start < end)
	{
		if(*start != *end)
			return 0;
		start++;
		end--;
	}
	return 1;
}










