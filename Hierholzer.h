#include "grafo.h"
#include <algorithm>

class Hierholzer
{
public:
    Hierholzer();
    
    std::map<int, std::vector<int>> adjacencia;
    std::map<Vertice *, Aresta *> EulerEdge;
    std::map<Aresta *, Aresta * > nextEdge;
    std::map<Aresta * , Aresta * > prevEdge;
    std::vector<Vertice *> Vvisit;

    
    Aresta *e0,*e1,*e2,*e3;
    

    int numVisitado;
    int contador;

    std::vector<Vertice*> CicloEuleriano_Hierholzer(Grafo g, Vertice *v);

};