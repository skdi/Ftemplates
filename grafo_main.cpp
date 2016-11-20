#include <iostream>
#include "grafo.h"
using namespace std;

int main(){

    grafo *peru=new grafo();

    peru->set_vertice("arequipa");
    peru->set_vertice("lima");
    peru->set_vertice("cusco");
    vertice *arequipa=peru->get_vertice("arequipa");
    vertice *lima=peru->get_vertice("lima");
    vertice *cusco=peru->get_vertice("cusco");
    peru->set_arista(arequipa,lima,500);
    peru->set_arista(arequipa,cusco,300);
    peru->set_arista(lima,cusco,700);
    peru->imprime_grafo();
    peru->eliminar_vertice(arequipa);
    peru->imprime_grafo();
    peru->clear();


    return 0;
}
