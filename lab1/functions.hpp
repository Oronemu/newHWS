#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>

double* createArr(int n);
void printArr(double* arr, int n);
void fillArr(double* arr, int n);
void reassignArr(double*& arr, int &n, int k, double number);
void delArr(double*& arr, int &n, int k);

void numAfterNum(double*& arr, int &n, double number, double x);
void delAllTargetNums(double*& arr, int &n, double x);

int checkFile();
void inputMethod(double &number);

#endif
