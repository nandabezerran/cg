#include "biblioteca.hpp"

double biblioteca::ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho){
    double produto = 0;
    for(int i = 0; i<tamanho; i++){
        produto = produto + vetor1[i]*vetor2[i];
    }
    return produto;
}

VectorXd biblioteca::ProdutoVetorial(VectorXd vetor1, VectorXd vetor2, int tamanho){
    VectorXd vetor_resultado(tamanho);

    vetor_resultado[0] = vetor1[1]*vetor2[2] - vetor1[2]*vetor2[1];
    vetor_resultado[1] = vetor1[2]*vetor2[0] - vetor1[0]*vetor2[2];
    vetor_resultado[2] = vetor1[0]*vetor2[1] - vetor1[1]*vetor2[0];

    return vetor_resultado;
}

VectorXd biblioteca::NormalizaVetor(VectorXd vetor, int tamanho){
    VectorXd vetor_normalizado(tamanho);
    double norma = 0;

    norma = sqrt(ProdutoEscalar(vetor,vetor,tamanho));
    vetor_normalizado = vetor/norma;

    return vetor_normalizado;
}

VectorXd biblioteca::EncontrarNormal(VectorXd vetor1, VectorXd vetor2, int tamanho){
    VectorXd vetor_normal(tamanho);
    vetor_normal = ProdutoVetorial(vetor1, vetor2, tamanho);
    vetor_normal = NormalizaVetor(vetor_normal, tamanho);
    return vetor_normal;
}

VectorXd biblioteca::SubtracaoPontos(Ponto p1, Ponto p2, int tamanho){
    //Vetor de p1 -> p2
    VectorXd vetor_resultante(tamanho);
    
    vetor_resultante[0] = p2.x - p1.x;
    vetor_resultante[1] = p2.y - p1.y;
    vetor_resultante[2] = p2.z - p1.z;

    return vetor_resultante;
}


Ponto biblioteca::EquacaoDaReta(Ponto p, double t, VectorXd vetor){
    Ponto resultante;
    resultante.x = p.x + t*vetor[0];
    resultante.y = p.y + t*vetor[1];
    resultante.z = p.z + t*vetor[2];
    return resultante;
}

double biblioteca::EquacaoDoPlano(Ponto p1, Ponto p0, const VectorXd vetor_n_plano, int tamanho) {
    VectorXd vetor_aux = SubtracaoPontos(p1,p0,tamanho);
    double resultado = ProdutoEscalar(vetor_aux,vetor_n_plano,tamanho);
    return resultado;
}

Ponto biblioteca::CriarPonto(double x, double y, double z) {
    Ponto p;
    p.x = x;
    p.y = y;
    p.z = z;
    return p;
}

tuple<Ponto, Ponto> biblioteca::PontosDadoDistancia(Ponto p_origem, const VectorXd vetor1, const VectorXd vetor2,
                                                    double l_comprimento, int tamanho){

    double s, t;
    Ponto p1, p2;

    s = pow(l_comprimento, 2);
    s = s/((ProdutoEscalar(vetor2,vetor2,tamanho)) -
           (pow(ProdutoEscalar(vetor1,vetor2,tamanho),2)/ProdutoEscalar(vetor1,vetor1,tamanho)));
    s = sqrt(s);

    t = ProdutoEscalar(vetor1,vetor2,tamanho)/ProdutoEscalar(vetor1,vetor1,tamanho);
    t = t * s;

    p1 = EquacaoDaReta(p_origem, t, vetor1);
    p2 = EquacaoDaReta(p_origem, s, vetor2);

    return make_tuple(p1,p2);

}









