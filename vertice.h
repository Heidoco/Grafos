#pragma once
#include "aresta.h"

class Vertice
{
public:
    int id;
    std::vector<Aresta> listaArestas;

    int estado = 0;
    int d = 0;
    Vertice *p = nullptr;



    Vertice(int id);
};