#ifndef SOLUTION2_H_
#define SOLUTION2_H_

void q2();
void colorStartPoints(int *mat, int *startValues);
int checkIfPointExist(int *startValues, int row, int col, int i);
void initStartValues(int *startValues);
void printStartValues(int *startValues);
int checkColorAmount();
int expandRows(int *mat, int row, int col, int color, int round);
int expandCols(int *mat, int row, int col, int color, int round);
void q2SetUP(int *mat, int *startValues);
void colorTheBoard(int *mat, int *startValues);
int expandColor(int *mat, int row, int col, int color, int round);

#endif
