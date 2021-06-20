#ifndef Structs_hpp
#define Structs_hpp
#include <stdio.h>
#include <string>

using namespace std;

struct Sweet {
    string producer;
    string type;
    int carbohydrates; //Углеводы
    int kilocalories;
    void Info();
};

struct MyQueue {
    struct Node {
        char* data;
        int nnn;
        Node* next;
    };
    
    Node* First = NULL;
    int Count = 0;
    bool Push(char*, int n);
    bool Pop(char*&, int& n);
};

#endif
