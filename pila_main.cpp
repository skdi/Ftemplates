#include "pila.h"
#include <iostream>
using namespace std;

int main()
{
    typedef nodo<int>* entero;

    pila<entero> a,b;
    entero q,w;
    int qw=5;
    int wq=3;
    q->elem=&qw;
    w->elem=&wq;
    a.push(q);







}
