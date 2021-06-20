#include "Functions.hpp"
#include <fstream>

void GetSeria(char*& data, int &n, Sweet A) {
    size_t s1 = A.producer.size();
    size_t s2 = A.type.size();
    int n1 = sizeof(int);
    int n2 = sizeof(int);
    int n3_size = sizeof(size_t);
    int n3 = s1;
    int n4_size = sizeof(size_t);
    int n4 = s2;
    n = n1 + n2 + n3_size + n3 + n4_size + n4;
    data = new char [n];
    char* d1 = reinterpret_cast<char*> (&A.carbohydrates);
    char* d2 = reinterpret_cast<char*> (&A.kilocalories);
    char* d3_size = reinterpret_cast<char*> (&s1);
    char* d3 = const_cast<char*> (A.producer.c_str());
    char* d4_size = reinterpret_cast<char*> (&s2);
    char* d4 = const_cast<char*> (A.type.c_str());
    for(int i = 0; i <= n1; i++) {
        data[i] = d1[i];
    }
    for(int i = 0; i <= n2; i++) {
        data[i + n1] = d2[i];
    }
    for(int i = 0; i <= n3_size; i++) {
        data[i + n1 + n2] = d3_size[i];
    }
    for(int i = 0; i <= n3; i++) {
        data[i + n1 + n2 + n3_size] = d3[i];
    }
    for(int i = 0; i <= n4_size; i++) {
        data[i + n1 + n2 + n3_size + n3] = d4_size[i];
    }
    for(int i = 0; i <= n4; i++) {
        data[i + n1 + n2 + n3_size + n3 + n4_size] = d4[i];
    }
}

void GetDeSeria(char* data, int n, Sweet& A) {
    int n1, n2, n3_size, n3, n4_size, n4;
    n1 = sizeof(int);
    n2 = sizeof(int);
    n3_size = sizeof(size_t);
    size_t p1 = *reinterpret_cast<size_t*> (data + n1 + n2);
    n3 = p1;
    string s1(data + n1 + n2 + n3_size, p1);
    n4_size = sizeof(size_t);
    size_t p2 = *reinterpret_cast<size_t*> (data + n1 + n2 + n3_size + n3);
    n4 = p2;
    string s2(data + n1 + n2 + n3_size + n3 + n4_size, p2);
    A.carbohydrates = *reinterpret_cast<int*> (data);
    A.kilocalories = *reinterpret_cast<int*> (data + n1);
    A.producer = s1;
    A.type = s2;
}

bool InputBinaryFile(MyQueue &Q) {
    fstream f_in("file.dat", ios::in | ios::binary);
    if(!f_in) {
        return false;
    }
    Sweet A;
    int n = 0;
    while(!f_in.eof()) {
        if(f_in.read((char*) &n, sizeof(int))) {
            char* data = new char[n];
            f_in.read(data, n);
            GetDeSeria(data, n, A);
            delete[] data;
            GetSeria(data, n, A);
            Q.Push(data, n);
        }
    }
    f_in.close();
    return true;
}

