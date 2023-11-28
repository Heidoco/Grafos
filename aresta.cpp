#include "aresta.h"

Aresta::Aresta(){};

Aresta::Aresta(Vertice* origem, Vertice* destino) : origem(origem), destino(destino) {}

Aresta::Aresta(Vertice* origem, Vertice* destino, int id) : origem(origem), destino(destino), id(id) {}

Aresta::Aresta(Vertice* origem, Vertice* destino, int id, int peso) : origem(origem), destino(destino), id(id), peso(peso) {}