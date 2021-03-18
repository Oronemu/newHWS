#ifndef functions_h
#define functions_h

#include <stdio.h>

int checkFile();
int GetN();
void newMatrix(double**& M, int n, int m);
void deleteMatrix(double**& M, int n, int m);
void printMatrix(double** M, int n, int m, const char* namematr);
void printVector(double* x, int n, const char* namematr);
void mult(double** M1, double** M2, int n1, int m1, int n2, int m2);
bool minor(double**& M, int n, int m, double& Det);
void transposition(double**& M, int n, int m, int k, double& Det);
bool solveGaus(double**& M, double* x, int n, int m, double& Det);
double determinant(double** M, int n, int m);
void choose(double**& M, int n, int m);
void clone(double**& M, int n, int m, double** M1);
double checkSolve(double** M1, int n, int m, double* x);
bool inverseMatrix(double** A, int n, int m, double& Det, double**& rev);

#endif
