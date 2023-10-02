#pragma once
#include "grafo.h"

class BuscaProfundidade
{
public:
    BuscaProfundidade();

    std::map<Vertice*, int > tempoA;
    std::map<Vertice*, int > tempoF;
    std::map<Vertice *, Vertice *> pai;
    std::map<Vertice*, int > estado;

    int tempo = 0;

    void DFS(Grafo *g, Vertice* v);
    void DFSTodos(Grafo *g);
    void VisitaVertice(Grafo *g, Vertice *v);
    void ImprimeCaminho(Grafo *g, Vertice *v1, Vertice *v2);
    void ResumeBusca(Grafo *g);

};