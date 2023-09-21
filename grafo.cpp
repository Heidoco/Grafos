#include <vector>
#include <stdio.h>
#include <iostream>
#include <queue>

class Vertice;

class Aresta
{
public:
    
    int id;
    Vertice* origem;
    Vertice* destino;

    Aresta(Vertice* origem, Vertice* destino) : origem(origem), destino(destino) {}
    Aresta(Vertice* origem, Vertice* destino, int id) : origem(origem), destino(destino),id(id) {}

};

class Vertice
{
public:
    int id;
    std::vector<Aresta> listaArestas;

    int estado = 0;
    int d = 0;
    Vertice *p = nullptr;



    Vertice(int id) : id(id){}
};



class Grafo
{
public:
    std::vector<Vertice> listaVertices;
    std::vector<Aresta> listaArestas;
    Grafo(){};

    int getOrdem(){return listaVertices.size();}

    int getTamanho(){return listaArestas.size();}

    void vertice() 
    {
        for (Vertice vertice : listaVertices) 
        {
            std::cout << vertice.id << " ";
        }
    }
    
    void aresta()
    {
        for (Aresta aresta : listaArestas) 
        {
            std::cout << "["<< aresta.origem->id << "-" <<aresta.destino->id << "] ";
        }
    }

    void insereV(Vertice vertice)
    {
        listaVertices.push_back(vertice);
    }

    void RemoveV(int id)
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

    void InsereA(Vertice* v1, Vertice* v2)
    {
        Aresta a(v1,v2);
        listaArestas.push_back(a);
        v1->listaArestas.push_back(a);
        v2->listaArestas.push_back(a);

    }

    void RemoveA(Vertice* v1, Vertice* v2) 
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


    std::vector<Vertice*> adj(Vertice* v)
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

    int getA(Vertice *v1, Vertice *v2)
    {
        for (Aresta aresta : listaArestas )
        {
            if ((aresta.origem == v1 && aresta.destino == v2) || (aresta.origem == v2 && aresta.destino  == v1)) 
            {
               return aresta.id;
            }
            else
            {
                return -1;
            }
        } 
    }

    int grauE(Vertice *v)
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

    int grauS(Vertice *v)
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

    int grau(Vertice *v)
    {
        return v->listaArestas.size();
    }

    std::vector<Vertice*> verticesA(int id) 
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

    Vertice* oposto(Vertice *v, Aresta* e)
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
    }

    std::vector<Aresta> arestasE(Vertice *v)
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

    std::vector<Aresta> arestasS(Vertice *v)
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

    void descreve()
    {
        std::cout << "\nVertices: \n";
        vertice();

        std::cout << "\nArestas: \n";
        aresta();
    }

    void BFS(Grafo *g, Vertice *vInicial)
    {
        for (auto& v : g->listaVertices)
        {
            v.d = 0;
            v.p = nullptr;
            v.estado = 0;
        }

        vInicial->estado = 1;
        vInicial->d = 0;
        std::queue<Vertice *> q;
        q.push(vInicial);
        
        while (!q.empty())
        {
            Vertice *u = q.front();
            q.pop();
            if (u->d == 0)
            {
                std::cout << "P("<< u->id <<") = NULL\n";
            }
            else
            {
                std::cout << "P("<< u->id <<") = " << u->p->id << "\n";
            }
            
            for (auto &v : g->adj(u))
            {
                if (v->estado == 0)
                {
                    q.push(v);
                    v->estado = 1;
                    v->p = u;
                    v->d = u->d + 1;
                }
            }

            u->estado = -1;
        } 
    }




};


int main(int argc, char const *argv[])
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
