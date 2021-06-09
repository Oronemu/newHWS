#ifndef functions_hpp
#define functions_hpp

#include <stdio.h>
#include <stack>

using namespace std;

int** ReadFile(string, int&, int&);
void Delete(int**&, int);
int* Dijkstra(int**, int, int);
void DijkstraRoute(int**, int, int, int, int*, stack <int>&);

#endif 
