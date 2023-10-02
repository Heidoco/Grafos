#pragma once
#include "grafo.h"

class BuscaLargura
{
public:
    BuscaLargura();

    std::map<Vertice*, int > distancia;
    std::map<Vertice *, Vertice *> pai;
    std::map<Vertice*, int > estado;

    void BFS(Grafo *g, Vertice *vInicial);
    void imprimeCaminho(Vertice *v);

};
