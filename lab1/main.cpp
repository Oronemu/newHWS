#include <iostream>
#include <fstream>
#include <stdlib.h>
#include "functions.hpp"

using namespace std;
int main() {
    
    int choice = 1;
    int n = checkFile();
    double num;

    if (!n) {
        cout << "Возникла ошибка при чтении файла, убедитесь в наличии чисел в нем." << endl;
        return 0;
    }
    
    double* arr = createArr(n);
    fillArr(arr, n);

    do {
        cout << "Считанный массив: ";
        printArr(arr, n);
        cout << "<!В случае отсутствия каких-либо  чисел убедитесь, что массив не содержит каких-либо букв и сторонник знаков!>" << endl;
        cout << endl << "---------------------------------------------------" << endl;
        cout << "Лабораторная по ЯП №1. Одномерные динамические массивы." << endl;
        cout << "Введите номер задания (1-8)" << endl;
        cout << "0 - выход из программы." << endl;
        cout << "---------------------------------------------------" << endl << endl;
        cin >> choice;
        switch (choice) {
            case 1: {
                inputMethod(num);
                reassignArr(arr, n, n + 1, num);
                break;
            }
            case 2: {
                inputMethod(num);
                reassignArr(arr, n, 1, num);
                break;
            }
        case 3: {
            unsigned int k;
            cout << "Введите позицию элемента: "; cin >> k;
            inputMethod(num);
            reassignArr(arr, n, k, num);
            break;
        }
            case 4: {
                delArr(arr, n, n);
                break;
            }
            case 5: {
                delArr(arr, n, 1);
                break;
            }
            case 6: {
                unsigned int k;
                cout << "Введите позицию элемента: "; cin >> k;
                delArr(arr, n, k);
                break;
            }
            case 7: {
                double x;
                cout << "Введите элемент, после которого будет добавлен новый элемент: "; cin >> x;
                inputMethod(num);
                numAfterNum(arr, n, num, x);
                break;
            }
            case 8: {
                double x;
                cout << "Введите элемент, которвый вы хотите удалить: "; cin >> x;
                delAllTargetNums(arr, n, x);
                break;
            }
        }
    } while (choice);
  delete[] arr;
}

