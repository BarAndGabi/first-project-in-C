#ifndef SOLUTION1_H_
#define SOLUTION1_H_

int Q1_doFindMaxSubMatrix(int *mat, int BMrow, int BMcol, int SMrow, int SMcol, int *indexRow, int *indexCol);
int Q1_bigMatChoose(int *rowBM, int *colBM, int rows, int cols);
int Q1_smallMatChoose(int *rowBM, int *colBM, int *rowSM, int *colSM);
int Q1_Menu(int *rowBM, int *colBM, int *rowSM, int *colSM, int rows, int cols);
int printSmallMat(int *mat, int rows, int cols, int bigRows);

#endif
