#include <iostream>
#include <iomanip>
#include <math.h>
#include <cstdlib>
#include <fstream>
#include "functions.h"

using namespace std;

int main(){
    setlocale(LC_ALL, "Russian");
    
    int choice = 1;
    double det = 1;
    int n;

    int check = checkFile();
    if (!check){
        cout << "Файл содержит ошибку или не существует!" << endl;
        return 0;
    }

    cout << "Лабораторная работа №2" << endl;
    cout << "Введите размер матрицы: ";
    n = GetN();
    
    do {
        int m = n + 1;
        double** A;
        double** A1;
        double** rev;
        double* x = new double[n];

        newMatrix(A, n, m);
        choose(A, n, m);

        newMatrix(A1, n, m);
        clone(A, n, m, A1);

        newMatrix(rev, n, n);
        printMatrix(A, n, m, "A");

        if (solveGaus(A, x, n, m, det)){
            printVector(x, n, "x");
            cout << "Эпсилон  = " << checkSolve(A1, n, m, x) << endl << endl;
        } else cout << "Нет решений" << endl;
        
        cout << "Определитель матрицы = " << det * determinant(A, n, m) << endl;
        
        if (inverseMatrix(A1, n, m, det, rev)){
            printMatrix(rev, n, n, "Обратная матрица:");
            mult(A1, rev, n, m - 1, n, n);
        } else cout << "Обратной матрицы нет" << endl;

        deleteMatrix(A, n, m);
        deleteMatrix(A1, n, m);
        deleteMatrix(rev, n, n);
        delete[] x;
        x = NULL;
    } while (choice);
    return 0;
}

