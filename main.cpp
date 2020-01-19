#include <iostream>
#include "Grafo.h"
using namespace std;

int main()
{
    Grafo f;
    f.insertarVertice('A');
    f.insertarVertice('B');
    f.insertarVertice('C');
    f.insertarVertice('D');
    f.insertarVertice('E');
    f.insertarVertice('F');
    f.insertarVertice('G');


    f.insertarArista(f.localiza('A'), f.localiza('G'), 10);
    f.insertarArista(f.localiza('C'), f.localiza('A'), 10);
    f.insertarArista(f.localiza('D'), f.localiza('F'), 10);
    f.insertarArista(f.localiza('A'), f.localiza('D'), 10);


    cout<<f.toString()<<endl;

    return 0;
}
