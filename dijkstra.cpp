#include "dijkstra.h"

Dijkstra::Dijkstra(){};


void Dijkstra::imprimeCaminho(Grafo g, Vertice *s, Vertice *v)
{
    if (v == s)
    {
        std::cout << v->id << "\n";
    }
    else
    {
        if (predecessor[v] == nullptr)
        {
            std::cout << "não existe caminho\n";
        }
        else
        {
            imprimeCaminho(g, s, predecessor[v]);
            std::cout << v->id << " custo total: " << peso[v] << "\n";
        }
    }
}

Vertice *Dijkstra::removeMinimo()
{
    Vertice *vMenorCusto = filaPrioridade.front();
    int menor_custo = peso[vMenorCusto];

    for (auto v : filaPrioridade)
    {
        if (peso[v] < menor_custo)
        {
            vMenorCusto = v;
            menor_custo = peso[v];
        }
    }

    filaPrioridade.remove(vMenorCusto);

    return vMenorCusto;
}


bool Dijkstra::pertence(Vertice *v)
{
    for (auto u : filaPrioridade)
    {
        if (u == v)
        {
            return true;
        }
    }
    return false;
}

void Dijkstra::dijkstra(Grafo g, Vertice *s)
{

    for (auto v : g.listarVertices())
    {
        peso[v] = INT32_MAX;
        predecessor[v] = nullptr;
    }

    peso[s] = 0;
    std::unordered_set<Vertice *> S;

    for (auto v : g.listarVertices())
    {
        filaPrioridade.push_back(v);
    }
    

    while (!filaPrioridade.empty()) 
    {
    Vertice *u = removeMinimo();
    S.insert(u);
    std::cout << "Vértice atual: " << u->id << "\n";

    std::vector<Vertice *> verticesAdjacentes = g.adj(u);


    if (!verticesAdjacentes.empty()) {
        for (auto v : verticesAdjacentes) {
            std::cout << "Vértice adjacente: " << v->id << "\n";

            Aresta *aresta = g.getA(u, v);
            if (aresta) {
                int pesoAresta = aresta->peso;

                if (pertence(v) && (peso[v] > (peso[u] + pesoAresta))) {
                    peso[v] = (peso[u] + pesoAresta);
                    predecessor[v] = u;
                }
            }
        }
    } else {
        std::cout << "A lista de vértices adjacentes está vazia.\n";
    }
    }
}