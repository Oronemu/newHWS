#include "Structs.hpp"

void Cup::Info() {
    cout << "Цена: " << Price << endl;
    cout << "Цвет: " << Color << endl;
    cout << "Размер: " << Size << endl;
    cout << "Изображение: " << Picture << endl;
}

bool Cup::IsEqual(Cup cup) {
    if(cup.Price == Price &&
       cup.Color == Color &&
       cup.Size == Size &&
       cup.Picture == Picture) return true;
    
    return false;
}

bool MyStack::Push(Cup data) {
    if(!Top) {
        Top = new Node;
        Top -> prev = NULL;
        Count = 1;
    }
    else {
        Node *temp;
        temp = new Node;
        temp -> prev = Top;
        Top = temp;
        Count++;
    }
    Top -> data = data;
    return true;
}

bool MyStack::Pop(Cup &data) {
    if(!Top) return false;
    Node *temp = Top -> prev;
    data = Top -> data;
    delete Top;
    Top = temp;
    Count--;
    return true;
}

void MyStack::Info() {
    if(!Top) cout << "Стек пуст!" << endl;
    else {
        cout << endl << "\tИнформация о стеке: " << endl;
        cout << "\tРазмер стека = " << Count << endl;
        Top->data.Info();
    }
}

void MyStack::Deletion(Cup& cup) {
    while (Count !=0) Pop(cup);
}
