#include "Hierholzer.h"

Hierholzer::Hierholzer(){};

std::vector<Vertice*> Hierholzer::CicloEuleriano_Hierholzer(Grafo g, Vertice *v)
{
    std::vector<Vertice*> circuitoEuleriano;
    Vvisit.push_back(v);
    numVisitado = 1;
    contador = 1;

    while (contador <= numVisitado)
    {
        Vertice* u = Vvisit[contador - 1];

        while (!u->listaArestas.empty())
        {
            e0 = &u->listaArestas[0];
            Vertice* v = e0->destino;
            g.RemoveA(e0->origem,e0->destino);
            e1 = e0;
        
            while (v != u)
            {
                if (std::find(Vvisit.begin(), Vvisit.end(), v) == Vvisit.end())
                {
                    numVisitado++;
                    Vvisit.push_back(v);
                }

                e2 = &v->listaArestas[0];
                nextEdge[e1] = e2;
                prevEdge[e2] = e1;

                if (EulerEdge.find(v) == EulerEdge.end())
                {
                    EulerEdge[v] = e2;
                }

                e1 = e2;
                v = e2->destino;
                g.RemoveA(e1->origem, e1->destino);
            }

            prevEdge[e0] = e1;
            nextEdge[e1] = e0;

            if (EulerEdge.find(u) == EulerEdge.end())
            {
                EulerEdge[u] = e0;
            }
            else
            {
                e1 = EulerEdge[u];
                e2 = prevEdge[e1];
                e3 = prevEdge[e0];
                nextEdge[e2] = e0;
                nextEdge[e3] = e1;
            }

        }

    circuitoEuleriano.push_back(u);
    contador ++;

    }

    circuitoEuleriano.push_back(circuitoEuleriano[0]);

    return circuitoEuleriano;
}