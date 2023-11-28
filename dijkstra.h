#pragma once
#include "grafo.h"
#include <list>
#include <unordered_set>

class Dijkstra
{
public:
    Dijkstra();
    std::map<Vertice *, Vertice *> predecessor;
    std::list<Vertice *> filaPrioridade;
    std::map<Vertice *, int> peso;

    Vertice *removeMinimo();
    bool pertence(Vertice *v);

    void imprimeCaminho(Grafo g, Vertice *s, Vertice *v);

    void dijkstra(Grafo g, Vertice *s);
};