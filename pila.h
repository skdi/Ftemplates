#ifndef PILA_H
#define PILA_H
#include <iostream>

using namespace std;


template<typename T>
class nodo{
private:
    T * elem;
public:
    nodo<T> *next;
    nodo(const *n_elem):elem(n_elem){}
};


template<typename T>
class pila{
private:
    int size;
    nodo<T> *n_pila;
public:
    pila():n_pila(0){}
    void operator +(nodo<T> *elemento);
    nodo<T>* operator -();
    ~pila(){delete n_pila;}

};

template<typename T>
class cola{
private:
    int size;
    nodo<T> *n_cola;
public:
    cola():n_cola(0){}
    void operator +(nodo<T> *elemento);
    nodo<T>* operator -();
    ~cola(){delete[] n_cola;}
};


template<typename T>
class lista_e{
private:
    nodo<T>* head;
public:
    lista_e(nodo<T> *_head=0):head(_head){}
    void operator +(nodo<T> *elemento);
    nodo<T> *operator -();
    ~lista_e(){}

};


template<typename T>
class myvector{
private:
    int size,maxsize;
    nodo<T> array;
public:
    myvector():size(0),maxsize(8),array(0){}
    myvector(int tamano):size(0),maxsize(tamano),array(0){}
    void push_back(nodo<T> elemento);
    int get_size(){return size;}
    void nuevo();
    ~myvector(){delete array;}


};


#endif // PILA_H
