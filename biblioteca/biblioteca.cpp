#include "biblioteca.hpp"

double Biblioteca::ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho){
    double produto = 0;
    for(int i = 0; i<tamanho; i++){
        produto = produto + vetor1[i]*vetor2[i];
    }
    return produto;
}

VectorXd Biblioteca::ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho){
    VectorXd vetor_resultado(tamanho);

    vetor_resultado[0] = vetor1[1]*vetor2[2] - vetor1[2]*vetor2[1];
    vetor_resultado[1] = vetor1[2]*vetor2[0] - vetor1[0]*vetor2[2];
    vetor_resultado[2] = vetor1[0]*vetor2[1] - vetor1[1]*vetor2[0];

    return vetor_resultado;
}

VectorXd Biblioteca::NormalizaVetor(VectorXd vetor, int tamanho){
    VectorXd vetor_normalizado(tamanho);
    double norma = 0;

    norma = sqrt(this->ProdutoEscalar(vetor,vetor,tamanho));
    vetor_normalizado = vetor/norma;

    return vetor_normalizado;
}

VectorXd Biblioteca::EncontrarNormal(VectorXd vetor1, VectorXd vetor2, int tamanho){
    VectorXd vetor_normal(tamanho);
    vetor_normal = this->ProdutoEscalar(vetor1, vetor2, tamanho);
    vetor_normal = this->NormalizaVetor(vetor_normal, tamanho);
    return vetor_normal;
}

VectorXd Biblioteca::SubtracaoPontos(Ponto p1, Ponto p2, int tamanho){
    //Vetor de p1 -> p2
    VectorXd vetor_resultante(tamanho);
    vetor_resultante[0] = p2.x - p1.x;
    vetor_resultante[1] = p2.y - p1.y;
    vetor_resultante[2] = p2.z - p1.z;

    return vetor_resultante;
}
