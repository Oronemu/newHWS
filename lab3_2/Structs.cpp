#include "Structs.hpp"
using namespace std;

bool MyQueue::Push(CupGroup cg) {
    if(!Top) {
        Top = new Node;
        Top -> next = NULL;
        Top -> data = cg;
        Count = 1;
        FullCost += cg.Price * cg.Quantity;
      }
      else {
        Node *temp;
        temp = Top;
        while(temp -> next != NULL) temp = temp -> next;
        temp -> next = new Node;
        temp -> next -> data = cg;
        temp -> next -> next = NULL;
        Count++;
        FullCost += cg.Price * cg.Quantity;
      }
      return true;
}

bool MyQueue::Pop(CupGroup& cg) {
    if(!Top) return false;
      Node* temp = Top -> next;
      cg = Top -> data;
      delete Top;
      Top = temp;
      Count--;
      return true;
}

void MyQueue::Info() {
    if(!Top) cout << "Склад пуст" << endl;
     else
     {
       cout << endl << "Информация о складе: " << endl;
       cout << "\tРазмер склада = " << Count << endl;
       cout << "\tКоличество товара в первой группе = " << Top -> data.Quantity << endl;
       cout << "\tЦена первой группы = " << Top -> data.Price << endl << endl;
     }
}
