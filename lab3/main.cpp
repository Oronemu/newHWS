#include <iostream>
#include "Structs.hpp"
#include "Functions.hpp"

using namespace std;

int main(int argc, const char * argv[]) {
    Cup cup;
    MyStack stack;
    
    ReadFile(stack, "cups.txt");
    int choice;
    
    cout << "----------Лабораторная №3----------" << endl;
    cout << "1. Показать верхний элемент стека" << endl;
    cout << "2. Добавить кружку" << endl;
    cout << "3. Вытащить кружку" << endl;
    cout << "4. Очистить стек" << endl;
    cout << "-----------------------------------"<<endl;
    cout << "0. Выйти" << endl;
    
    do {
        cin>>choice;
        switch(choice) {
            case 1:{
                stack.Info();
                break;
            }
            case 2: {
                cout<<"Добавить:"<<endl;
                cout<<"Цена: ";
                cin>>cup.Price;
                cout<<"Цвет: ";
                cin>>cup.Color;
                cout<<"Размер: ";
                cin>>cup.Size;
                cout<<"Изображение: ";
                cin>>cup.Picture;
                stack.Push(cup);
                break;
            }
            case 3: {
                cout<<"Найти:"<<endl;
                cout<<"Цена: ";
                cin>>cup.Price;
                cout<<"Цвет: ";
                cin>>cup.Color;
                cout<<"Размер: ";
                cin>>cup.Size;
                cout<<"Изображение: ";
                cin>>cup.Picture;
                FindCup(stack,cup);
                break;
            }
            case 4: {
                stack.Deletion(cup);
                break;
            }
        }
    } while(choice != 0);
}
