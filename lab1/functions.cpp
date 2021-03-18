#include "functions.hpp"
#include <iostream>
#include <fstream>

using namespace std;

void printArr(double* arr, int n) {
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

double* createArr(int n) {
    double* arr = new double[n];
    return arr;
}

void fillArr(double* arr, int n) {
  fstream A("array.txt", ios::in);
  for (int i = 0; i < n; i++) {
    A >> arr[i];
  }
  A.close();
}

void reassignArr(double*& arr, int &n, int k, double num) {
    k--;
    if (k >= 0 && k <= n) {
        double *buff = new double[n + 1];
        for (int i = 0; i < k; i++)
            buff[i] = arr[i];
        buff[k] = num;
        n++;
        for (int i = k + 1; i < n; i++)
            buff[i] = arr[i - 1];
        delete[] arr;
        arr = buff;
    }
    else cout << "Ошибка. Возможно введена неверная позиция элемента.";
}

void delArr(double*& arr, int &n, int k) {
    k--;
    if (k >= 0 && k <= n) {
        double* buff = new double[n - 1];
        for (int i = 0; i < k; i++)
            buff[i] = arr[i];
        n--;
        for (int i = k; i < n; i++)
            buff[i] = arr[i + 1];
        delete[] arr;
        arr = buff;
    }
    else cout << "Ошибка. Возможно введена неверная позиция элемента.";
}

void numAfterNum(double*& arr, int &n, double num, double x) {
    int k = 0;
    for (int i = 0; i < n; i++) {
      if (arr[i] == x) {
        k = i + 1;
        break;
      }
    }
    if (k > 0) {
      double* buff = new double[n + 1];
      for (int i = 0; i < k; i++) {
        buff[i] = arr[i];
      }
      n++;
      buff[k] = num;
      for (int i = k + 1; i < n; i++) {
        buff[i] = arr[i - 1];
      }
      delete[] arr;
      arr = buff;
    }
    else cout << "Ошибка. Элемент не найден, попробуйте заново." << endl;
}

void delAllTargetNums(double*& arr, int &n, double x) {
  int k = 0;
  for (int i = 0; i < n; i++) {
    if (arr[i] == x) {
      k++;
    }
  }
  if (k > 0) {
    k = 0;
    double* buff = new double[n - k];
    for (int i = 0; i < n; i++) {
      if (arr[i] == x) {
        k++;
      }
      else buff[i - k] = arr[i];
    }
    n -= k;
    delete[] arr;
    arr = buff;
  }
  else cout << "Ошибка. Элемент не найден, попробуйте заново." << endl;
}

void inputMethod(double &number) {
    int m = 1;
    double a = -100;
    double b = 100;
    
    cout << endl << "-----------------------------------" << endl;
    cout << "Каким образом вы хотите добавить число?" << endl;
    cout << "1. Случайное число" << endl;
    cout << "2. Ввести собственоручно" << endl;
    cout << "-----------------------------------" << endl << endl;
    cin >> m;
    
    switch (m) {
        case 1: {
            number = a + (b - a) * (double)rand() / RAND_MAX;
            m = 0;
            break;
        }
        case 2: {
            cout << "Введите число: ";
            cin >> number;
            m = 0;
            break;
        }
        default: {
            cout << "Возникла непредвиденная ошибка, попробуйте снова." << endl;
            break;
        }
    }
}

 int checkFile() {
   double a;
   int k = 0;
   fstream A("array.txt", ios::in);
   while (A >> a) {
     k++;
   }
   A.close();
   return k;
 }
