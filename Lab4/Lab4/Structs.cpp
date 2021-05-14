#include "Structs.hpp"
#include <iostream>

bool MyQueue::Push(char* data, int n) {
    if(!First) {
        First = new Node;
        First -> next = NULL;
        First -> data = new char[n];
        for(int i = 0; i <= n; i++) {
            (First -> data)[i] = data[i];
        }
        Count = 1;
        First -> nnn = n;
    }
    else {
        Node *temp;
        temp = First;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = new Node;
        temp -> next -> data = new char[n];
        for(int i = 0; i <= n; i++) {
            (temp -> next -> data)[i] = data[i];
        }
        temp -> next -> nnn = n;
        temp -> next -> next = NULL;
        Count++;
    }
    return true;
}

bool MyQueue::Pop(char*& data, int& n) {
    if(!First) return false;
    Node* temp = First -> next;
    n = First -> nnn;
    data = new char[n];
    for(int i = 0; i <= First -> nnn; i++) {
        data[i] = (First -> data)[i];
    }
    delete[] (First -> data);
    delete First;
    First = temp;
    Count--;
    return true;
}

void Sweet::Info() {
    cout << "Углеводы = " << carbohydrates << endl;
    cout << "Килокалории = " << kilocalories << endl;
    cout << "Производитель = " << producer << endl;
    cout << "Тип = " << type << endl << endl;
}
