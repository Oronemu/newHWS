#include <iostream>
#include <fstream>
#include "Structs.hpp"
#include "Functions.hpp"


int main(int argc, const char * argv[]) {
    
    CupGroup cg;
    CupGroup cg_rc;
    MyQueue Queue;
    ReadFile(Queue, "warehouse.txt");
    
    int choice;
    
    cout << "------Лабораторная №3.2------" << endl;
    cout << "1. Поступление товара" << endl;
    cout << "2. Продажа товара" << endl;
    cout << "3. Отчет" << endl;
    cout << "-----------------------------"<<endl;
    cout << "0. Выйти" << endl;
    
    do {
        cin>>choice;
        switch(choice) {
            case 1:{
                //system("clear");
                cout << "Заполните информацию о товаре:" << endl;
                cout << "Количество = ";
                cin >> cg.Quantity;
                cout << "Цена = ";
                cin >> cg.Price;
                Queue.Push(cg);
                break;
            }
            case 2: {
                //system("clear");
                cout << "Заполните информацию о товаре:" << endl;
                cout << "Количество = ";
                cin >> cg_rc.Quantity;
                cout << "Цена = ";
                cin >> cg_rc.Price;
                if (Queue.Count != 0) {
                    cg = Queue.Top -> data;
                }
                if(CheckSell(Queue, cg_rc)) {
                    while(cg_rc.Quantity) {
                        if(cg_rc.Quantity <= cg.Quantity) {
                            Queue.Income += cg_rc.Quantity * (cg_rc.Price - cg.Price);
                            Queue.FullCost -= cg.Price * cg_rc.Quantity;
                            cg.Quantity -= cg_rc.Quantity;
                            cg_rc.Quantity = 0;
                            Queue.Top -> data.Quantity = cg.Quantity;
                        }
                        else {
                            Queue.Income += cg.Quantity * (cg_rc.Price - cg.Price);
                            Queue.FullCost -= cg.Price * cg.Quantity;
                            cg_rc.Quantity -= cg.Quantity;
                            cg.Quantity = 0;
                        }
                        if(cg.Quantity == 0){
                            Queue.Pop(cg);
                            if (Queue.Count != 0)
                                cg = Queue.Top -> data;
                        }
                    }
                    cout << "Продажа выполнена." << endl;
                }
                else cout << "Продажа не выполнена." << endl;
                break;
            }
            case 3: {
                //system("clear");
                Queue.Info();
                cout << "Общая стоимость товаров = " << Queue.FullCost << endl;
                cout << "Доход от продажи = " << Queue.Income << endl;
                break;
            }
        }
    } while(choice != 0);
    while (Queue.Count !=0){
        Queue.Pop(cg);
    }
    return 0;
}
