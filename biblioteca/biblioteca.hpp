#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
#include <tuple>
#include "../eigen/Eigen/Core"
//#include "Plano.hpp"

using namespace std;
using namespace Eigen;

struct Ponto{
    double x;
    double y;
    double z;
};

class biblioteca{
    public:
        static double ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho);
        static double ProdutoEscalar(Ponto* p1, VectorXd vetor2);
        static double ProdutoEscalar(double ponto, VectorXd vetor2);
        static VectorXd ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho);
        static VectorXd NormalizaVetor(VectorXd vetor, int tamanho);
        static VectorXd EncontrarNormal(VectorXd vetor1, VectorXd vetor2, int tamanho);
        static VectorXd SubtracaoPontos(Ponto* p1, Ponto* p2, int tamanho);
        static Ponto* EquacaoDaReta(Ponto* p, double t, VectorXd vetor);
        static double EquacaoDoPlano(Ponto* p1, Ponto* po, VectorXd vetor_n_plano, int tamanho);
        static Ponto* CriarPonto(double x, double y, double z);
        static double distanciaEntrePontos(Ponto* p1, Ponto* p2);
        static VectorXd DivisaoVetor(VectorXd v, double x);
        static VectorXd MultVetorEscalar(VectorXd v, double x);
        static void SubtracaoPontos(Ponto* p1, Ponto* p2, VectorXd &vector);
        static void somaVetorPonto(VectorXd v, Ponto* p);
        static void subVetorPonto(VectorXd v, Ponto* p);
        static Ponto*** MatrixAllocation(int size);



    //TODO: Encontrar nome melhor pra essa função (solução da prova 1)
    static tuple<Ponto*, Ponto*> PontosDadoDistancia(Ponto* p_origem, VectorXd vetor1, VectorXd vetor2,
                                                     double l_comprimento, int tamanho);

};

#endif //BIBLIOTECA_H