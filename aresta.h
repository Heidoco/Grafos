#pragma once
#include <vector>
#include <stdio.h>
#include <iostream>

class Vertice;

class Aresta
{
public:
    
    
    Vertice* origem;
    Vertice* destino;
    int id;

    Aresta();
    Aresta(Vertice* origem, Vertice* destino);
    Aresta(Vertice* origem, Vertice* destino, int id);

};