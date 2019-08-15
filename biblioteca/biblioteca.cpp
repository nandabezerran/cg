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
    vetor_normal = this->ProdutoVetorial(vetor1, vetor2, tamanho);
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
Ponto Biblioteca::EquacaoDaReta(Ponto p, double t, VectorXd vetor){
    Ponto resultante;
    resultante.x = p.x + t*vetor[0];
    resultante.y = p.y + t*vetor[1];
    resultante.z = p.z + t*vetor[2];
    return resultante;
}

double Biblioteca::EquacaoDoPlano(Ponto p1, Ponto p0, const VectorXd vetor_n_plano, int tamanho) {
    VectorXd vetor_aux = this->SubtracaoPontos(p1,p0,tamanho);
    double resultado = this->ProdutoEscalar(vetor_aux,vetor_n_plano,tamanho);
    return resultado;
}

Ponto Biblioteca::IntersecaoRetaPlano(Ponto p0, VectorXd vetor0, Ponto p_pi, VectorXd vetor_n_plano, int tamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto p_t_int;

    //t_int = ( (Ppi - P0) * n ) / (u*n)

    //vetor eh o Ppi - p0
    VectorXd vetor = this->SubtracaoPontos(p0,p_pi,tamanho);
    //produto0 eh o resultado do vetor * n
    double produto0 = this->ProdutoEscalar(vetor,vetor_n_plano,tamanho);
    //produto1 eh o u*n
    double produto1 = this->ProdutoEscalar(vetor0,vetor_n_plano,tamanho);

    //t_int eh o resultado de cima / resultado de baixo
    double t_int = produto0/produto1;

    //Dado um ponto p0 e um vetor vetor0 retornar a equacao da reta (P(t) = Po + t * V)
    p_t_int = this->EquacaoDaReta(p0,t_int,vetor0);

    return p_t_int;
}
