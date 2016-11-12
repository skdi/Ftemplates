#include "pila.h"
#include <iostream>
using namespace std;


template <class T>
pila<T>::pila(int tamano){

    size=tamano;//asigno tamanio a mi pila
    top=-1;//posicion auxiliar inicial
    ps=new T[size];//espacio de memoria para mi pila
}


template <class T>
void pila<T>::push(T valor){

    if(!lleno())
        ps[++top]=valor;//en la posicion 0 pongo el valor
    else
        cout<<"la pila esta llena"<<endl;

}

template <class T>
T pila<T>::pop(){
    if(!vacio())
        ps[top--];
    else
        cout<<"la pila esta vacia"<<endl;
}

template <class T>
bool pila<T>::lleno(){
    return top==size-1;//si top es igual a size -1 entonce TRUE
}

template <class T>
bool pila<T>::vacio(){
    return top==-1;//si top es igual a -1 entonce TRUE
}
