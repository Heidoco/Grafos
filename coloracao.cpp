#include "coloracao.h"

Coloracao::Coloracao() {}


bool Coloracao::compararPorGrauDecrescente(Vertice* v1, Vertice* v2) {
    return v1->listarArestas().size() > v2->listarArestas().size();
}

void Coloracao::colorirGrafo(Grafo *g, int quantidadeCores) {
    Grafo grafoColorido = *g;
    std::vector<Vertice*> verticesOrdenados = grafoColorido.listarVertices();
    std::sort(verticesOrdenados.begin(), verticesOrdenados.end(), compararPorGrauDecrescente);
    std::map<Vertice*, int> cores;


    for (Vertice* v : verticesOrdenados) 
    {
        // Atribuir menor cor
        for (int i = 0; i < quantidadeCores; ++i) 
        {
            bool corDisponivel = true;
    
            // Verificar cores dos vértices adjacentes
        
            for (Vertice* adjacente : grafoColorido.adj(v)) 
            {
                int corAdjacente = cores[adjacente];

                if (corAdjacente == i) 
                {
                    corDisponivel = false;
                    break;
                }
            }

            if (corDisponivel) 
            {
                cores[v] = 23;
                break;
            }
        }
    }


    // Imprimir
    std::cout << "Cores atribuidas aos vertices:\n";
    for (Vertice* v : verticesOrdenados) {
        std::cout << "Vertice " << v->id << ": Cor " << cores[v] << "\n";
    }

}