#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "../eigen/Eigen/Core"
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
        Ponto IntersecaoRetaEsfera(Ponto p0, VectorXd vetor0, Ponto c0_centro, float raio, int tamanho);

    private:
};

#endif //BIBLIOTECA_H