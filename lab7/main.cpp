#include <iostream>
#include <fstream>
#include <stack>
#include "functions.hpp"

using namespace std;

int main() {
    stack <int> route;
    ofstream outroute;
    outroute.open("route.txt");
    int n, m, s, end;
    int** A = ReadFile("graph.txt", n, m);
    
    if(A == NULL | n != m) {
        cout << "Непредвиденная ошибка";
        outroute << "Непредвиденная ошибка";
        return 0;
    }
    
    cout << "Начальная вершина: "; cin >> s;
    s--;
    int* d = Dijkstra(A, n, s);
    cout << "----------" << endl;
    outroute << "----------" << endl;
    for(int i = 0; i < n; i++) {
        cout << s + 1 << " > " << i + 1 << " = " << d[i] << endl;
        outroute << s + 1 << " > " << i + 1 << " = " << d[i] << endl;
    }

    cout << "Конечная вершина: "; cin >> end;
    end--;
    DijkstraRoute(A, n, s, end, d, route);
    cout << "----------" << endl;
    cout << "Маршрут: " << endl;
    outroute << "----------" << endl;
    outroute << "Маршрут: " << endl;
    while(!route.empty()) {
        cout  << " > " << route.top();
        outroute  << " > " << route.top();
        route.pop();
    }
    outroute.close();
    Delete(A, n);
    delete[] d;
    return 0;
}
