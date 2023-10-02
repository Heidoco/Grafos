#include "vertice.h"

Vertice::Vertice(int id) : id(id){}

std::vector<Aresta*> Vertice::listarArestas()
{
    std::vector<Aresta*> arestas;

    for (Aresta& a : listaArestas)
    {
        arestas.push_back(&a);
    }
    
    return arestas;
}