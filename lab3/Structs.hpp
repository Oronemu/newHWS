#ifndef Structs_hpp
#define Structs_hpp
#include <iostream>

using namespace std;

struct Cup {
    int Price;
    string Color;
    string Size;
    string Picture;
    void Info();
    bool IsEqual(Cup);
};

struct MyStack {
    struct Node {
        Cup data;
        Node *prev;
    };
    Node *Top = NULL;
    int Count;
    bool Push(Cup);
    bool Pop(Cup&);
    void Info();
    void Deletion(Cup&);
};

#endif 
