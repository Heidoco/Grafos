#include "grafo.h"

int main()
{
    Grafo grafodaora;

    Vertice v1 = Vertice(1);
    Vertice v2 = Vertice(2);
    Vertice v3 = Vertice(3);
    Vertice v4 = Vertice(4);
    Vertice v5 = Vertice(5);
    Vertice v6 = Vertice(6);

    grafodaora.insereV(v1);
    grafodaora.insereV(v2);
    grafodaora.insereV(v3);
    grafodaora.insereV(v4);
    grafodaora.insereV(v5);
    grafodaora.insereV(v6);

    grafodaora.InsereA(&v1,&v2);
    grafodaora.InsereA(&v2,&v3);
    grafodaora.InsereA(&v3,&v4);
    grafodaora.InsereA(&v4,&v5);
    grafodaora.InsereA(&v5,&v6);
    grafodaora.InsereA(&v6,&v4);
    // grafodaora.InsereA(&v1,&v6);


    grafodaora.vertice();
    grafodaora.aresta();

    std::vector<Vertice*> listaadjv1 = grafodaora.adj(&v1);

    for (auto vertice : listaadjv1) 
    {
        std::cout << vertice->id << " ";
    }

    //grafodaora.RemoveA(&v1,&v2);
    std::cout << "\n";
    grafodaora.aresta();

    grafodaora.descreve();
    std::cout << "Busca:\n";
    grafodaora.BFS(&grafodaora,&v1);



    return 0;
}