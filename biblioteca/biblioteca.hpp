#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "../eigen/Eigen/Core"
using namespace Eigen;

struct Ponto{
    int x;
    int y;
    int z;
};

class Biblioteca{
    public:
        double ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd NormalizaVetor(VectorXd vetor, int tamanho);
        VectorXd EncontrarNormal(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd SubtracaoPontos(Ponto p1, Ponto p2, int tamanho);
    private:
};

#endif //BIBLIOTECA_H