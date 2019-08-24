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

class Biblioteca{
    public:
        double ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd NormalizaVetor(VectorXd vetor, int tamanho);
        VectorXd EncontrarNormal(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd SubtracaoPontos(Ponto p1, Ponto p2, int tamanho);
        Ponto EquacaoDaReta(Ponto p, double t, VectorXd vetor);
        double EquacaoDoPlano(Ponto p1, Ponto po, VectorXd vetor_n_plano, int tamanho);
        Ponto IntersecaoRetaPlano(Ponto p0, VectorXd vetor0, Ponto p_pi, VectorXd vetor_n_plano, int tamanho);
        tuple<Ponto,Ponto,int> IntersecaoRetaEsfera(Ponto p0, VectorXd vetor0, Ponto c0_centro, float raio, int tamanho);
        tuple<Ponto,Ponto,int> IntersecaoRetaCilindro(Ponto p0, VectorXd vetor0, VectorXd vetor_n,Ponto c0_centro, float raio, float H, int tamanho);
        tuple<Ponto,Ponto, int, int> IntersecaoRetaCone(Ponto p0, VectorXd vetor0, VectorXd vetor_n,Ponto c0_centro, float raio, float H, int tamanho);
        
        //TODO: Encontrar nome melhor pra essa função (solução da prova 1)
        tuple<Ponto, Ponto> PontosDadoDistancia(Ponto p_origem, VectorXd vetor1, VectorXd vetor2,
                             double l_comprimento, int tamanho);
    private:
        bool ValidacaoPontoCone(Ponto vertice, Ponto p_int, VectorXd vetor_n, float H, int tamanho);
};

#endif //BIBLIOTECA_H