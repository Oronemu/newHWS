#include <iostream>
#include <fstream>
#include "Structs.hpp"
#include "Functions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    MyQueue Q;
    char* data;
    int n = 0;
    int m = 1;
    Sweet A;
    InputBinaryFile(Q);
    while(m) {
        cout << "------------------------------" << endl;
        cout << "1. Добавить элемент в очередь" << endl;
        cout << "2. Удалить элемент из очереди" << endl;
        cout << "3. Очистить очередь" << endl;
        cout << "------------------------------" << endl;
        cout << "0. Выход" << endl;
        cin >> m;
        switch(m) {
            case 1: { //Добавить элемент
                cout << "------------------------------" << endl;
                cout << "Введите информацию о конфете:" << endl;
                cout << "Углеводы = "; cin >> A.carbohydrates;
                cout << "Килокалории = "; cin >> A.kilocalories;
                cout << "Производитель = "; cin >> A.producer;
                cout << "Тип = "; cin >> A.type;
                GetSeria(data, n, A);
                Q.Push(data, n);
                break;
            }
            case 2: { //Удалить элемент
                Sweet A_x;
                bool metka = false;
                cout << "------------------------------" << endl;
                cout << "Введите ифнормацию о конфете:" << endl;
                cout << "Углеводы = "; cin >> A_x.carbohydrates;
                cout << "Килокалории = "; cin >> A_x.kilocalories;
                cout << "Производитель = "; cin >> A_x.producer;
                cout << "Тип = "; cin >> A_x.type;
                int Y = Q.Count;
                for(int i = 0; i < Y; i++) {
                    Q.Pop(data, n);
                    GetDeSeria(data, n, A);
                    delete[] data;
                    if(A.carbohydrates != A_x.carbohydrates ||
                       A.kilocalories != A_x.kilocalories ||
                       A.producer != A_x.producer ||
                       A.type != A_x.type) {
                        GetSeria(data, n, A);
                        Q.Push(data, n);
                    }
                    else {
                        metka = true;
                        break;
                    }
                }
                if(!metka) cout << "Продукт не найден" << endl;
                break;
            }
            case 3: { //Очистить очередь
                while(Q.Count) {
                    Q.Pop(data, n);
                    GetDeSeria(data, n, A);
                    delete[] data;
                    A.Info();
                }
                break;
            }
        }
    }
    while(Q.Count) {
        Q.Pop(data, n);
        delete[] data;
    }
}
