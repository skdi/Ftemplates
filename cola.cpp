#include "cola.h"
#include <iostream>
using namespace std;


template<class T>
cola<T>::cola(): sig(NULL), ant(NULL), contador(0)//inicializo los parametros
{
}

template<class T>
bool cola<T>::vacia(){//funcion auxiliar para saber si la cola tiene elementos

    return(contador == 0);
}

template<class T>
void cola<T>::encolar(T data){

    Node *newOne = new Node;//asigno espacio de memoria al nuevo nodo
    newOne->dato = data;//asigno el dato
    newOne->next = NULL;//apunto la siguiente posicion a null

    if(vacia()){//
        sig = newOne;//si esta vacia apunta al nodo creado
    }
        else{
            ant->next = newOne;
        }
        ant = newOne;//actualizo posicion
        contador++;
}

template<class T>
void cola<T>::descolar(){
    if(vacia()){
        cout << "cola vacia" << endl;
    }
        else{
            Node *temp = sig;//creo un nodo auxiliar
            if(sig == ant){//comparo si mis punteros estan en la misma posicion
                sig = NULL;
                ant = NULL;
            }
            else{
                sig = sig->next;//en caso contrario apunto al siguiente nodo
            }
            delete temp;//libero memoria
            contador--;//decremento el contador
        }
}
