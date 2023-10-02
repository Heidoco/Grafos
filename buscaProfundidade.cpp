#include "buscaProfundidade.h"

BuscaProfundidade::BuscaProfundidade(){};

void BuscaProfundidade::VisitaVertice(Grafo *g,Vertice *v)
{
    estado[v] = 1;
    tempo++;
    tempoA[v] = tempo;

    for (auto &vertice : g->adj(v))
    {
        if (estado[vertice] == 0)
        {
            pai[vertice] = v;
            VisitaVertice(g, vertice); 
        }
        
    }

    estado[v] = -1;
    tempo++;
    tempoF[v] = tempo;
    
}

void BuscaProfundidade::DFS(Grafo *g, Vertice *v)
{
    for (auto &vertice : g->listarVertices())
    {
        pai[vertice] = nullptr;
        tempoA[vertice] = 0;
        tempoF[vertice] = 0;
        estado[vertice] = 0;
    }

    tempo = 0;
    VisitaVertice(g, v);
}

void BuscaProfundidade::DFSTodos(Grafo *g)
{
    for (auto &vertice : g->listarVertices())
    {
        pai[vertice] = nullptr;
        tempoA[vertice] = 0;
        tempoF[vertice] = 0;
        estado[vertice] = 0;
    }

    tempo = 0;

    for (auto &vertice : g->listarVertices())
    {
        if (estado[vertice] == 0)
        {
            VisitaVertice(g, vertice);
        }
    }

}

void BuscaProfundidade::ImprimeCaminho(Grafo *g, Vertice *v1, Vertice *v2)
{
    if (v1 == v2)
    {
        std::cout << v1->id << "\n";
    }
    else
    {
        if (pai[v2] == nullptr)
        {
            std::cout << "Nao existe caminho" << "\n";
        }
        else
        {
            ImprimeCaminho(g,v1,pai[v2]);
            std::cout << v2->id << "\n";
        }
    }
}