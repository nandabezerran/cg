#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include "../eigen/Eigen/Core"
using namespace Eigen;

class Biblioteca{
    public:
        double ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho);
        VectorXd NormalizaVetor(VectorXd vetor, int tamanho);
    private:
};

#endif //BIBLIOTECA_H