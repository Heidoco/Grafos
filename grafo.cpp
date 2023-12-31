#include "grafo.h"

Grafo::Grafo(){};

int Grafo::getOrdem(){return listaVertices.size();}

int Grafo::getTamanho(){return listaArestas.size();}

void Grafo::vertice() 
{
    for (Vertice vertice : listaVertices) 
    {
        std::cout << vertice.id << " ";
    }
}

void Grafo::aresta()
{
    for (Aresta aresta : listaArestas) 
    {
        std::cout << "["<< aresta.origem->id << "-" <<aresta.destino->id << "] ";
    }
}

void Grafo::insereV(Vertice vertice)
{
    listaVertices.push_back(vertice);
}

void Grafo::RemoveV(int id)
{
    // Quando for pra remover algo de um vector, utilizar um Iterador
    for (auto it = listaVertices.begin(); it != listaVertices.end(); it++) 
    {
        if (it->id == id) 
        {
            listaVertices.erase(it);
            break;
        }
    }
}

void Grafo::InsereA(Vertice* v1, Vertice* v2)
{
    Aresta a(v1,v2);
    listaArestas.push_back(a);
    v1->listaArestas.push_back(a);
    v2->listaArestas.push_back(a);
}

void Grafo::InsereA(Vertice* v1, Vertice* v2, int id)
{
    Aresta a(v1,v2,id);
    listaArestas.push_back(a);
    v1->listaArestas.push_back(a);
    v2->listaArestas.push_back(a);
}

void Grafo::InsereA(Vertice* v1, Vertice* v2, int id, int peso)
{
    Aresta a(v1,v2,id, peso);
    listaArestas.push_back(a);
    v1->listaArestas.push_back(a);
    v2->listaArestas.push_back(a);
}

void Grafo::RemoveA(Vertice* v1, Vertice* v2) 
{
    for (auto it = listaArestas.begin(); it != listaArestas.end(); ++it) 
    {
        if ((it->origem == v1 && it->destino == v2) || (it->origem == v2 && it->destino == v1)) 
        {
            listaArestas.erase(it);
            break;
        }
    }
    for (auto it = v1->listaArestas.begin(); it !=  v1->listaArestas.end(); ++it) 
    {
        if ((it->origem == v1 && it->destino == v2) || (it->origem == v2 && it->destino == v1)) 
        {
            v1->listaArestas.erase(it);
            break;
        }
    }
    for (auto it = v2->listaArestas.begin(); it !=  v2->listaArestas.end(); ++it) 
    {
        if ((it->origem == v1 && it->destino == v2) || (it->origem == v2 && it->destino == v1)) 
        {
            v2->listaArestas.erase(it);
            break;
        }
    }
}

void Grafo::RemoveA(int id)
{
    for (auto it = listaArestas.begin(); it != listaArestas.end();)
    {
        if (it->id == id)
        {
            it = listaArestas.erase(it);
        }
        else
        {
            it++;
        }
    }
}

std::vector<Vertice*> Grafo::adj(Vertice* v)
{
    std::vector<Vertice*> listaAdj;
    for (Aresta aresta : v->listaArestas ) 
    {
        if (aresta.destino->id != v->id)
        {
            listaAdj.push_back(aresta.destino);
        }
        else if (aresta.origem->id != v->id)
        {
            listaAdj.push_back(aresta.origem);
        }
        else
        {
            listaAdj.push_back(v);
        }
        
    }
    return listaAdj;
}

Aresta* Grafo::getA(Vertice* v1, Vertice* v2)
{
    for (Aresta& aresta : listaArestas)
    {
        if ((aresta.origem == v1 && aresta.destino == v2) || (aresta.origem == v2 && aresta.destino == v1))
        {
            return &aresta;
        }
    }

    return nullptr;
}

int Grafo::grauE(Vertice *v)
{
    int cont = 0;
    for (Aresta aresta : v->listaArestas)
    {
        if (aresta.destino == v)
        {
            cont++;
        }
    }
    return cont;
}

int Grafo::grauS(Vertice *v)
{
    int cont = 0;
    for (Aresta aresta : v->listaArestas)
    {
        if (aresta.origem == v)
        {
            cont++;
        }
    }
    return cont;
}

int Grafo::grau(Vertice *v)
{
    return v->listaArestas.size();
}

std::vector<Vertice*> Grafo::verticesA(int id) 
{
    std::vector<Vertice*> resultado;
    for (Aresta aresta : listaArestas) 
    {
        if (aresta.id == id) 
        {
            resultado.push_back(aresta.origem);
            resultado.push_back(aresta.destino);
        }
    }
    return resultado;
}

Vertice* Grafo::oposto(Vertice *v, Aresta* e)
{
    for (Aresta aresta : v->listaArestas)
    {
        if (aresta.id == e->id)
        {
            if (aresta.origem == v)
            {
                return aresta.destino;
            }
            else
            {
                return aresta.origem;
            }
        }
    }

    return nullptr;
}

std::vector<Aresta> Grafo::arestasE(Vertice *v)
{
    std::vector<Aresta> arestasE;
    for (Aresta aresta : v->listaArestas)
    {
        if (aresta.destino == v)
        {
            arestasE.push_back(aresta);
        }
    }
    return arestasE;
}

std::vector<Aresta> Grafo::arestasS(Vertice *v)
{
    std::vector<Aresta> arestasS;
    for (Aresta aresta : v->listaArestas)
    {
        if (aresta.origem == v)
        {
            arestasS.push_back(aresta);
        }
    }
    return arestasS;
}

void Grafo::descreve()
{
    std::cout << "\nVertices: \n";
    vertice();
    std::cout << "\nArestas: \n";
    aresta();
}

std::vector<Vertice*> Grafo::listarVertices()
{
    std::vector<Vertice*> vertices;

    for (Vertice& v : listaVertices)
    {
        vertices.push_back(&v);
    }
    
    return vertices;
}