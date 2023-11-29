#include "grafo.h"
#include "buscaLargura.h"
#include "buscaProfundidade.h"
#include "Hierholzer.h"
#include "dijkstra.h"
#include "coloracao.h"

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

    grafodaora.InsereA(&v1,&v2, 1 ,10);
    grafodaora.InsereA(&v2,&v3, 2, 20);
    grafodaora.InsereA(&v3,&v4, 3, 17);
    grafodaora.InsereA(&v4,&v5, 4, 55);
    grafodaora.InsereA(&v5,&v6, 5, 10000);
    //grafodaora.InsereA(&v6,&v4);
    grafodaora.InsereA(&v6,&v1, 6, 8);


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

    BuscaLargura BuscaL;

    BuscaL.BFS(&grafodaora,&v1);
    std::cout <<"Caminho de v1 ate v5: \n";
    BuscaL.imprimeCaminho(&v5);

    BuscaProfundidade BuscaP;
    BuscaP.DFS(&grafodaora,&v1);
    std::cout <<"\nCaminho de v1 ate v5 na busca em profundidade: \n";
    BuscaP.ImprimeCaminho(&grafodaora, &v1, &v5);

    Hierholzer Ciclo;
    std::vector<Vertice*> cicloe;
    cicloe = Ciclo.CicloEuleriano_Hierholzer(grafodaora, &v1);
    std::cout << "Ciclo Euleriano: \n";
    for (auto vertice : cicloe) 
    {
        std::cout << vertice->id << " ";
    }

    Dijkstra menorCaminho;


    //Dijkstra
    menorCaminho.dijkstra(grafodaora, &v1);

    // Caminhos mínimos
    for (auto destino : grafodaora.listarVertices()) {
        if (destino != &v1) {
            std::cout << "Caminho de Vi para " << destino->id << ":\n";
            menorCaminho.imprimeCaminho(grafodaora, &v1, destino);
        }
    }

    Coloracao Cor;

    Cor.colorirGrafo(&grafodaora,3);

    return 0;
}
 
