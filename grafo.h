#ifndef GRAFO_H
#define GRAFO_H
#include <iostream>
#include <string>
using namespace std;


class arista;

class vertice{
public:
    vertice *sig;
    arista *ady;
    string nombre;
    friend class grafo;
};

class arista{
public:
    arista *sig;
    vertice *ady;
    int tam;
    friend class grafo;
};

class grafo{
private:
    vertice *head;
public:
    grafo():head(NULL){}
    bool vacio(){return head==NULL;}
    int get_size();
    vertice *get_vertice(string nombre);
    void set_vertice(string nombre);
    void set_arista(vertice *inicio,vertice *fin,int tam);
    void eliminar_arista(vertice *inicio,vertice *fin);
    void eliminar_vertice(vertice *vert);
    void imprime_grafo();
    void clear();


};

#endif // GRAFO_H
