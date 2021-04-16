#include "Functions.hpp"
#include <fstream>

using namespace std;

bool CheckSell(MyQueue Queue, CupGroup cg_rc) {
    CupGroup cg;
    MyQueue::Node *a;
    a = Queue.Top;
    int k = 0;
    if (Queue.Count != 0) {
        while(a -> data.Price <= cg_rc.Price & k != Queue.Count) {
            cg.Price = a -> data.Price;
            cg.Quantity = a -> data.Quantity;
            if (cg_rc.Quantity <= cg.Quantity) cg_rc.Quantity = 0;
            else cg_rc.Quantity -= cg.Quantity;
            if (cg_rc.Quantity == 0) return true;
            else {
                if(k < Queue.Count){
                    k++;
                    a = a -> next;
                } else return false;
            }
        }
    }
    return false;
}

void ReadFile(MyQueue& Queue, string FileName) {
    ifstream FileStream(FileName);
    if (!FileStream) {
        cout << "Ошибка при чтении файла, возможно он отсутствует!" << endl;
        return;
    }
    CupGroup cg;
    while(FileStream >> cg.Quantity >> cg.Price) {
        Queue.Push(cg);
    }
    FileStream.close();
}

