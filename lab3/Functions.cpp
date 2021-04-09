#include "Functions.hpp"
#include <fstream>

void ReadFile(MyStack& Stack, string FileName) {
    ifstream FileStream(FileName);
    if (!FileStream) {
        cout << "Ошибка при чтении файла, возможно он отсутствует!" << endl;
        return;
    }
    Cup cup;
    while(FileStream >> cup.Price >> cup.Color >> cup.Size >> cup.Picture) {
        Stack.Push(cup);
    }
    FileStream.close();
}

void FindCup(MyStack& S,Cup findCup) {
    Cup cup;
    MyStack second;
    while(S.Count != 0 && !(S.Top->data.IsEqual(findCup)) ) {
        S.Pop(cup);
        second.Push(cup);
    }
    if(S.Count!=0) {
        cout<<"Кружка найдена!"<<endl;
        S.Pop(cup);
    }
    else cout<<"Кружка отсутствует!"<<endl;
    while(second.Pop(cup)) S.Push(cup);
}
