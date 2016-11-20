#include "grafo.h"


int grafo::get_size()
{
    int cont=0;//contador auxiliar
    vertice *aux;//vertice auxiliar
    aux=head;//inicializo posicion
    while(aux!=NULL){//recorrido de vertices
        cont++;//aumento al contador
        aux=aux->sig;//actualizo posicion
    }
    return cont;//retorno el tamanio del contador determinado por el numero de vertices
}

vertice *grafo::get_vertice(string nombre)
{
    vertice *aux;//vertice auxiliar
    aux=head;//inicializado en head
    while(aux!=NULL){//para el recorrido de este
        if(aux->nombre==nombre)//comparacion de nombre
            return aux;//si existe retorna los datos del vertice pedido
        aux=aux->sig;//actualizo posicion
    }
    return NULL;//en caso no se encuentre retorno null
}

void grafo::set_vertice(string nombre)
{
    vertice *nuevo=new vertice;//separo espacio de memoria para mi nuevo vertice
    nuevo->nombre=nombre;//inicializo nombre
    nuevo->sig=NULL;//no apunta a nada
    nuevo->ady=NULL;
    if(vacio()){//si mi grafo esta vacio
        head=nuevo;//a la primera posicion inserto mi nuevo vertice
    }
    else{
        vertice *aux;//en caso contrario creo un auxiliar
        aux=head;//lo dirijo hacia la primera posicion
        while(aux->sig!=NULL){//recorre todos los vertices
            aux=aux->sig;//actualizo posicion
        }
        aux->sig=nuevo;//en siguiente de la posicion final inserto mi nuevo vertice
    }
}

void grafo::set_arista(vertice *inicio, vertice *fin, int tam)
{
    arista *nueva=new arista;//separo espacio de memoria para mi arista
    nueva->tam=tam;//inicializo su tamanio
    nueva->sig=NULL;//no apunta a nada
    nueva->ady=NULL;
    arista *aux;//creo una arista auxiliar
    aux=inicio->ady;//asigno a auxiliar la posicion adyacente de mi vertice inicial
    if(aux==NULL){//si la posicion adyacente de mi primer veertice es null
        inicio->ady=nueva;//ingreso mi arista en esa posicion
        nueva->ady=fin;//la nueva arista apunta al siguiente vertice
    }
    else{
        while(aux->sig!=NULL)//si no es null
            aux=aux->sig;//actualizo posicion
        aux->sig=nueva;//al final de ingreso nuevo arista
        nueva->ady=fin;//y la enlazo con el siguiente vertice
    }

}

void grafo::eliminar_arista(vertice *inicio, vertice *fin)
{
    arista *cur,*ant;//aristas auxiliares para los enlazes
    int bandera=0;
    cur=inicio->ady;//inicializo cur en la posicion adyacente de mi primer vertice
    if(cur==NULL)//si cur esta vacio
        cout<<"vertice sin aristas"<<endl;
    //en caso se encuentre en la 2da posicion
    else if(cur->ady==fin){//si el vertice adyacente es igual al vertice final
        inicio->ady=cur->sig;//la posicion adyacente de mi vertice inicial apunta a la siguiente posicion de cur
        delete cur;//que seria vertice final y luego elimino la arista
    }
    else{//para el resto de posicion
        while(cur!=NULL){//recorro el grafo
            if(cur->ady==fin){//si el vertice adyacente es igual al vertice final
                bandera=1;//se encontro
                ant->sig=cur->sig;//salta una posicion
                delete cur;//borro la arista
                break;//salgo del while
            }
            ant=cur;
            cur=cur->sig;//actualizo posicion
        }
    }
    if(bandera==0)//por default si no se encontro en todo el grafo
        cout<<"los vertices no estan unidos"<<endl;

}

void grafo::eliminar_vertice(vertice *vert)
{
    vertice *cur,*ant;//creo 2 vertices auxiliares
    arista *aux;//1 arista auxiliar
    cur=head;//inicializo mi posicion
    //eliminar las aristas del vertice
    while(cur!=NULL){//recorro los vertices
        aux=cur->ady;// a auxiliar le paso la posicion adyacente de mi posicion actual(tambien es una arista)
        while(aux!=NULL){//recorro las aristas
            if(aux->ady==vert){//si la arista apunta al vertice pedido
                eliminar_arista(cur,aux->ady);//llamo a eliminar arista y le paso los datos
                break;//del vertice actual y el vertice encontrado
            }
            aux=aux->sig;//actualizo posicion de aristas
        }
        cur=cur->sig;//actualizo posicion de vertices
    }
    //eliminar el vertice en si
    if(head==vert){//si esta en la primera posicion
        head=head->sig;//apunto a la 2da posicion
        delete cur;//elimino el vertice
    }else{//sino esta en la primera posiciopn
        while(cur!=vert){//recorro y actualizo posicion
            ant=cur;
            cur=cur->sig;
        }
        ant->sig=cur->sig;//enlazo la  anterior posicion con la siguiente del vertice
        delete cur;//elimino el vertice actual
    }

}

void grafo::imprime_grafo()
{
    vertice *vaux;
    arista *aaux;
    vaux=head;//inicializo posicion
    while(vaux!=NULL){//recorrido del vertices
        cout<<vaux->nombre<<"->";//muestro el nombre del vertice y una flecha ->
        aaux=vaux->ady;//inicializo reccorrido de las aristas en el vertice actual
        while(aaux!=NULL){//recorrido de aristas
            cout<<aaux->ady->nombre<<"->";//imprimo el nombre de la arista y una flecha
            aaux=aaux->sig;//actualizo posicion de aristas
        }
        vaux=vaux->sig;//actualizo posicion de vertices
        cout<<endl;
    }

}

void grafo::clear()
{
    vertice *aux;
    while(head!=NULL){//rrecorro los vertices
        aux=head;//asigno head a la un auxiliar
        head=head->sig;//actualizo head
        delete aux;//borro auxliar
    }
}
