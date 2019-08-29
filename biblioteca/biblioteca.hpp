#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include "../eigen/Eigen/Core"

using namespace std;
using namespace Eigen;

struct Ponto{
    double x;
    double y;
    double z;
};

struct Vertice {
    string id;
    Ponto* p;
};

struct Aresta{
    string id;
    VectorXd aresta;
    Vertice* verticeInicial;
    Vertice* verticeFinal;
};

struct Face{
    string id;
    Vertice* p1;
    Vertice* p2;
    Vertice* p3;
    vector<Aresta> arestas;
};


class biblioteca{
    public:
        static double ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho);
        static VectorXd ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho);
        static VectorXd NormalizaVetor(VectorXd vetor, int tamanho);
        static VectorXd EncontrarNormal(VectorXd vetor1, VectorXd vetor2, int tamanho);
        static VectorXd SubtracaoPontos(Ponto* p1, Ponto* p2, int tamanho);
        static VectorXd SubtracaoVertices(Vertice* v1, Vertice* v2, int tamanho);
        static Ponto* EquacaoDaReta(Ponto* p, double t, VectorXd vetor);
        static double EquacaoDoPlano(Ponto* p1, Ponto* po, VectorXd vetor_n_plano, int tamanho);
        static Ponto* CriarPonto(double x, double y, double z);
        static Vertice* CriarVertice(Ponto* p1, string id);
        static Aresta* CriarAresta(Vertice* pi, Vertice* pf, string id);

        //TODO: Encontrar nome melhor pra essa função (solução da prova 1)
        static tuple<Ponto*, Ponto*> PontosDadoDistancia(Ponto* p_origem, VectorXd vetor1, VectorXd vetor2,
                             double l_comprimento, int tamanho);

};

#endif //BIBLIOTECA_H