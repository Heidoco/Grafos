#include "buscaLargura.h"

BuscaLargura::BuscaLargura(){};

void BuscaLargura::BFS(Grafo *g, Vertice *vInicial)
{
    for (auto &v : g->listarVertices())
    {
        pai[v] = nullptr;
        distancia[v] = -1;
        estado[v] = 0;
    }

    estado[vInicial] = 1;
    distancia[vInicial] = 0;
    std::queue<Vertice *> q;
    q.push(vInicial);
    
    while (!q.empty())
    {
        Vertice *u = q.front();
    
        q.pop();

        if (distancia[u] == 0)
        {
            std::cout << "P(" << u->id << ") = NULL\n";
        }
        else
        {
            std::cout << "P(" << u->id << ") = " << pai[u]->id << "\n";
        }
        
        for (auto &v : g->adj(u))
        {
            if (estado[v] == 0)
            {
                q.push(v);
                estado[v] = 1;
                pai[v] = u;
                distancia[v] = distancia[u] + 1;
            }
        }
        estado[u] = -1;
    }
}

void BuscaLargura::imprimeCaminho(Vertice *v) {
    if (v == nullptr) {
        return; 
    }

    imprimeCaminho(pai[v]); // Recursivamente imprime o pai

    if (pai[v] != nullptr) {
        std::cout << " -> "; // Separação entre vértices no caminho
    }

    std::cout << v->id; // Imprime o ID do vértice
}
