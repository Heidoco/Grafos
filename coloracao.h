#include "grafo.h"
#include <algorithm>

class Coloracao
{
public:
    Coloracao();
    static bool compararPorGrauDecrescente(Vertice* v1, Vertice* v2);
    void colorirGrafo(Grafo *g, int quantidadeCores);

};