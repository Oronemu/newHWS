#include <iostream>
#include <fstream>
#include <sstream>
#include "DLList.hpp"
#include "Notebook.hpp"

using namespace std;
int main() {
    DLList List;
    Notebook A;
    void* S;
    int choice = 1;
    
    ifstream file("lab5.txt");
    string line;
    
    while(getline(file, line)) {
        istringstream line_F(line);
        line_F >> A.RAM >> A.ROM >> A.producer >> A.material;
        S = Notebook_init(A);
        List.AddNext(S);
    }
    file.close();
    
    while(choice)
    {
        cout << "------------Добавить элемент------------" << endl;
        cout << "1. Добавить в начало" << endl;
        cout << "2. Добавить в конец" << endl;
        cout << "3. Добавить на k-ю позицию" << endl;
        cout << "------------Удалить элемент-------------" << endl;
        cout << "4. Удалить первый элемент" << endl;
        cout << "5. Удалить последний элемент" << endl;
        cout << "6. Удалить с k-й позиции" << endl;
        cout << "--------------Отсортировать-------------" << endl;
        cout << "7. Отсортировать по ОЗУ" << endl;
        cout << "8. Отсортировать по Постоянной памяти" << endl;
        cout << "------------Очистить список-------------" << endl;
        cout << "9. Очистить список" << endl;
        cout << "------------Загрузить в файл------------" << endl;
        cout << "10. Загрузить информацию из списка в файл" << endl;
        cout << "---------------Информация---------------" << endl;
        cout << "11. Показать состояние списка" << endl;
        cout << "---------------------------------------" << endl;
        cout << "0. Выйти" << endl;
        cin >> choice;
        switch(choice) {
            case 1: {
                Notebook_cin(A);
                S = Notebook_init(A);
                List.AddFirst(S);
                Notebook_out(List);
                break;
            }
            case 2: {
                Notebook_cin(A);
                S = Notebook_init(A);
                List.AddLast(S);
                Notebook_out(List);
                break;
            }
            case 3: {
                int k;
                cout << "Введите номер позиции от " << 1 << " до " << List.Count + 1 << endl;
                cout << "k = "; cin >> k;
                k--;
                if(k >= 0 & k <= List.Count) {
                    Notebook_cin(A);
                    S = Notebook_init(A);
                    if(k == 0) {
                        List.AddFirst(S);
                    }
                    else {
                        if(k == List.Count) {
                            List.AddLast(S);
                        }
                        else {
                            List.Move_k(k - 1);
                            List.AddNext(S);
                        }
                    }
                    Notebook_out(List);
                }
                else cout << "ОШИБКА" << endl;
                break;
            }
            case 4: {
                if(List.DelFirst(S)) {
                    Notebook_del(S);
                    Notebook_out(List);
                }
                else {
                    cout << "ОШИБКА" << endl;
                }
                break;
            }
            case 5: {
                if(List.DelLast(S)) {
                    Notebook_del(S);
                    Notebook_out(List);
                }
                else {
                    cout << "ОШИБКА" << endl;
                }
                break;
            }
            case 6: {
                int k;
                if(!List.Count) {
                    cout << "ОШИБКА" << endl;
                    break;
                }
                cout << "Введите номер позиции от " << 1 << " до " << List.Count << endl;
                cout << "k = "; cin >> k;
                k--;
                if(k >= 0 & k <= List.Count) {
                    if(k == 0) {
                        List.DelFirst(S);
                    }
                    else {
                        if(k == (List.Count - 1)) {
                            List.DelLast(S);
                        }
                        else {
                            List.Move_k(k);
                            List.Del(S);
                        }
                    }
                    Notebook_out(List);
                }
                else cout << "ОШИБКА" << endl;
                break;
            }
            case 7: {
                void* tmp;
                for(int i = 0; i < List.Count; i++) {
                    List.MoveLast();
                    for(int j = (List.Count - 1); j >= (i + 1); j--) {
                        if(((Notebook*) List.C->data)->RAM < ((Notebook*) List.C->prev->data)->RAM) {
                            tmp = List.C->data;
                            List.C->data = List.C->prev->data;
                            List.C->prev->data = tmp;
                        }
                        List.MovePrev();
                    }
                }
                Notebook_out(List);
                break;
            }
            case 8: {
                void* tmp;
                for(int i = 0; i < List.Count; i++) {
                    List.MoveLast();
                    for(int j = (List.Count - 1); j >= (i + 1); j--) {
                        if(((Notebook*) List.C->data)->ROM < ((Notebook*) List.C->prev->data)->ROM) {
                            tmp = List.C->data;
                            List.C->data = List.C->prev->data;
                            List.C->prev->data = tmp;
                        }
                        List.MovePrev();
                    }
                }
                Notebook_out(List);
                break;
            }
            case 9: {
                List.MoveFirst();
                while(List.Del(S)) {
                    Notebook_del(S);
                }
                Notebook_out(List);
                break;
            }
            case 10: {
                ofstream file("lab5.txt");
                List.MoveFirst();
                for(int i = 0; i < List.Count; i++) {
                    A = *((Notebook*) List.C->data);
                    file << A.RAM << " "  << A.ROM << " "<< A.producer << " " << A.material << endl;
                    List.MoveNext();
                }
                file.close();
                cout << "Загружено" << endl;
                break;
            }
            case 11: {
                Notebook_out(List);
                break;
            }
        }
    }
    List.MoveFirst();
    while(List.Del(S)) {
        Notebook_del(S);
    }
    return 0;
}
