#pragma once
#include "vertice.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

class Grafo
{
public:
    Grafo();

    std::vector<Vertice> listaVertices;
    std::vector<Aresta> listaArestas;
    
    int getOrdem();
    int getTamanho();
    int getA(Vertice *v1, Vertice *v2);
    int grauE(Vertice *v);
    int grauS(Vertice *v);
    int grau(Vertice *v);

    void vertice();
    void aresta();
    void insereV(Vertice vertice);
    void RemoveV(int id);
    void InsereA(Vertice* v1, Vertice* v2);
    void RemoveA(Vertice* v1, Vertice* v2); 
    void descreve();
    void BFS(Grafo *g, Vertice *vInicial);

    std::vector<Vertice*> adj(Vertice* v);
    std::vector<Vertice*> verticesA(int id); 
    std::vector<Aresta> arestasE(Vertice *v);
    std::vector<Aresta> arestasS(Vertice *v);

    Vertice* oposto(Vertice *v, Aresta* e);

};