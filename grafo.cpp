#include "grafo.h"

int grafo::get_size()
{
    int cont=0;
    vertice *aux;
    aux=head;
    while(aux!=NULL){
        cont++;
        aux=aux->sig;
    }
    delete aux;
    return cont;
}

vertice *grafo::get_vertice(string nombre)
{
    vertice *aux;
    aux=head;
    while(aux!=NULL){
        if(aux->nombre==nombre)
            return aux;
        aux=aux->sig;
    }
    return NULL;
}

void grafo::set_vertice(string nombre)
{
    vertice *nuevo=new vertice;
    nuevo->nombre=nombre;
    nuevo->sig=NULL;
    nuevo->ady=NULL;
    if(vacio()){
        head=nuevo;
    }
    else{
        vertice *aux;
        aux=head;
        while(aux->sig!=NULL){
            aux=aux->sig;
        }
        aux->sig=nuevo;
    }
}

void grafo::set_arista(vertice *inicio, vertice *fin, int tam)
{
    arista *nueva=new arista;
    nueva->tam=tam;
    nueva->sig=NULL;
    nueva->ady=NULL;
    arista *aux;
    aux=inicio->ady;
    if(aux==NULL){
        inicio->ady=nueva;
        nueva->ady=fin;
    }
    else{
        while(aux->sig!=NULL)
            aux=aux->sig;
        aux->sig=nueva;
        nueva->ady=fin;
    }

}

void grafo::eliminar_arista(vertice *inicio, vertice *fin)
{
    arista *cur,*ant;
    int bandera=0;
    cur=inicio->ady;
    if(cur==NULL)
        cout<<"vertice sin aristas"<<endl;
    else if(cur->ady==fin){
        inicio->ady=cur->sig;
        delete cur;
    }
    else{
        while(cur!=NULL){
            if(cur->ady==fin){
                bandera=1;
                ant->sig=cur->sig;
                delete cur;
                break;
            }
            ant=cur;
            cur=cur->sig;
        }
    }
    if(bandera==0)
        cout<<"los vertices no estan unidos"<<endl;

}

void grafo::eliminar_vertice(vertice *vert)
{
    vertice *cur,*ant;
    arista *aux;
    cur=head;
    while(cur!=NULL){
        aux=cur->ady;
        while(aux!=NULL){
            if(aux->ady==vert){
                eliminar_arista(cur,aux->ady);
                break;
            }
            aux=aux->sig;
        }
        cur=cur->sig;
    }
    if(head==vert){
        head=head->sig;
        delete cur;
    }else{
        while(cur!=vert){
            ant=cur;
            cur=cur->sig;
        }
        ant->sig=cur->sig;
        delete cur;
    }

}

void grafo::imprime_grafo()
{
    vertice *vaux;
    arista *aaux;
    vaux=head;
    while(vaux!=NULL){
        cout<<vaux->nombre<<"->";
        aaux=vaux->ady;
        while(aaux!=NULL){
            cout<<aaux->ady->nombre<<"->";
            aaux=aaux->sig;
        }
        vaux=vaux->sig;
        cout<<endl;
    }

}

void grafo::clear()
{
    vertice *aux;
    while(head!=NULL){
        aux=head;
        head=head->sig;
        delete aux;
    }
}

