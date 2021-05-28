#include <iostream>
#include "DLList.hpp"
#ifndef Notebook_hpp
#define Notebook_hpp
using namespace std;
struct Notebook {
  double RAM;
  double ROM;
  string producer;
  string material;
};

void* Notebook_init(Notebook);
void Notebook_del(void*);
void Notebook_out(DLList);
void Notebook_cin(Notebook&);

#endif
