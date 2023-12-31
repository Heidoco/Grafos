#pragma once
#include "vertice.h"
#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>
#include <map>


class Grafo
{
public:
    Grafo();

    std::vector<Vertice> listaVertices;
    std::vector<Aresta> listaArestas;
    
    int getOrdem();
    int getTamanho();
    Aresta* getA(Vertice *v1, Vertice *v2);
    int grauE(Vertice *v);
    int grauS(Vertice *v);
    int grau(Vertice *v);

    void vertice();
    void aresta();
    void insereV(Vertice vertice);
    void RemoveV(int id);
    void InsereA(Vertice* v1, Vertice* v2);
    void InsereA(Vertice* v1, Vertice* v2, int id);
    void InsereA(Vertice* v1, Vertice* v2, int id, int peso);   
    void RemoveA(Vertice* v1, Vertice* v2);
    void RemoveA(int id); 
    void descreve();

    std::vector<Vertice*> adj(Vertice* v);
    std::vector<Vertice*> listarVertices();
    std::vector<Vertice*> verticesA(int id); 
    std::vector<Aresta> arestasE(Vertice *v);
    std::vector<Aresta> arestasS(Vertice *v);

    Vertice* oposto(Vertice *v, Aresta* e);

};