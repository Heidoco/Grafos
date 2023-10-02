#pragma once
#include "aresta.h"

class Vertice
{
public:
    int id;
    std::vector<Aresta> listaArestas;

    Vertice(int id);
};