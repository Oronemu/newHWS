#include <iostream>
#include "Notebook.hpp"
using namespace std;
void* Notebook_init(Notebook B) {
    Notebook* A = new Notebook;
  A->RAM = B.RAM;
  A->ROM = B.ROM;
  A->producer = B.producer;
  A->material = B.material;
  void* S = (void*) A;
  return S;
}
void Notebook_del(void* S) {
  delete (Notebook*) S;
}
void Notebook_out(DLList List) {
  Notebook A;
  List.MoveFirst();
  if(!List.Count) {
    cout << "Список пуст" << endl;
    return;
  }
  for(int i = 0; i < List.Count; i++) {
    A = *((Notebook*) List.C->data);
    cout << "-----------------------------" << endl;
    cout << "ОЗУ = " << A.RAM << endl;
    cout << "Постоянная память = " << A.ROM << endl;
    cout << "Производитель = " << A.producer << endl;
    cout << "Материал = " << A.material << endl;
    List.MoveNext();
  }
}
void Notebook_cin(Notebook& A) {
  cout << "Введите информацию:" << endl;
  cout << "ОЗУ = "; cin >> A.RAM;
  cout << "Постоянная память = "; cin >> A.ROM;
  cout << "Производитель = "; cin >> A.producer;
  cout << "Материал = "; cin >> A.material;
}
