#include "pila.h"


template<typename T>
void pila<T>::operator +(nodo<T> *elemento){
    nodo<T>* temp=n_pila;
    while(temp->next!=0)
        temp=temp->next;
    temp->next=elemento;
    elemento->next=0;
}

template<typename T>
void pila<T>::push(nodo<T> *elemento){
    nodo<T>* temp=n_pila;
    while(temp->next!=0)
        temp=temp->next;
    temp->next=elemento;
    elemento->next=0;
}
template<typename T>
nodo<T> *pila<T>::pop(){

    if(n_pila!=0){
    nodo<T>* temp=n_pila->next;
    nodo<T>* prev=n_pila;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;
    }
    prev->next=0;
    return temp;}
    else cout<<"pila vacia"<<endl;
}

template<typename T>
nodo<T>* pila<T>::operator -(){
    if(n_pila!=0){
    nodo<T>* temp=n_pila->next;
    nodo<T>* prev=n_pila;
    while(temp->next!=0){
        prev=temp;
        temp=temp->next;
    }
    prev->next=0;
    return temp;}
    else cout<<"pila vacia"<<endl;
}

template<typename T>
void cola<T>::encolar(nodo<T> *elemento){

    nodo<T>* temp=n_cola;
    while(temp->next!=0)
        temp=temp->next;
    temp->next=elemento;
    elemento->next=0;
}

template<typename T>
void cola<T>::operator +(nodo<T> *elemento){

    nodo<T>* temp=n_cola;
    while(temp->next!=0)
        temp=temp->next;
    temp->next=elemento;
    elemento->next=0;
}

template<typename T>
nodo<T>* cola<T>::operator -(){
    if(n_cola!=0){
        nodo<T>* temp=n_cola->next;
        return temp;
    }
    else
        cout<<"fin de la cola"<<endl;

}

template<typename T>
nodo<T>* cola<T>::desencolar(){
    if(n_cola!=0){
        nodo<T>* temp=n_cola->next;
        return temp;
    }
    else
        cout<<"fin de la cola"<<endl;
}


template<typename T>
void lista_e<T>::operator +(nodo<T> *elemento)
{
    if(head==0)
        head=elemento;
    else{
        nodo<T> *ptr=head;
        while(ptr->next!=0)
            ptr=ptr->next;
        ptr->next=elemento;
    }
}

template<typename T>
nodo<T>* lista_e<T>::operator -(){
    nodo<T> *ant=head;
    nodo<T> *sig=head->next;
    while(ant!=0){
        delete ant;
        ant=sig;
        sig=sig->next;}
}




template<typename T>
void myvector<T>::nuevo(){
    maxsize=size*2;
    nodo<T> *temp=new nodo<T>[maxsize];
    for(int i=0;i<size;i++)
        temp[i]=array[i];
    delete[] array;
    array=temp;
}

template<typename T>
void myvector<T>::push_back(nodo<T> elemento){
    if(size+1>maxsize)
        nuevo();
    array[size]=elemento;
    size++;
}

template<typename T>
void myvector<T>::operator+ (nodo<T> elemento){
    if(size+1>maxsize)
        nuevo();
    array[size]=elemento;
    size++;
}
