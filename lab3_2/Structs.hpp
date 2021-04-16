#ifndef Structs_hpp
#define Structs_hpp
#include <iostream>

struct CupGroup {
    int Quantity;
    double Price;
};

struct MyQueue {
    struct Node {
        CupGroup data;
        Node* next;
    };
    Node* Top = NULL;
    int Count = 0;
    double FullCost = 0;
    double Income = 0;
    bool Push(CupGroup);
    bool Pop(CupGroup&);
    void Info();
};

#endif
