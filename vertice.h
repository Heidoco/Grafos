#pragma once
#include "aresta.h"

class Vertice
{
public:
    int id;
    std::vector<Aresta> listaArestas;

    std::vector<Aresta*> listarArestas();

    Vertice(int id);
};