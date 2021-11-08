#ifndef __ARRAYS__
#define __ARRAYS__

void	printArray(const int* arr, int size);
void	initArray(int* arr, int size);
void	printMat(const int* mat, int rows, int cols);
void	initMat(int* mat, int rows, int cols);
void	printArrayChar(const char* arr, int size);
void	initArrayChar(char* arr, int size);
void	printMatChar(const char* mat, int rows, int cols);
void	initMatChar(char* mat, int rows, int cols);
void	initMatRand(int* mat, int rows, int cols);
int	sumSmallMat(int* mat, int rows, int cols,int bigRows);


#endif
