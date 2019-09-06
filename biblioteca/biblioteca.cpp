#include "biblioteca.hpp"

double biblioteca::ProdutoEscalar(VectorXd vetor1, VectorXd vetor2, int tamanho){
    double produto = 0;
    for(int i = 0; i<tamanho; i++){
        produto = produto + vetor1[i]*vetor2[i];
    }
    return produto;
}
double biblioteca::ProdutoEscalar(Ponto* ponto, VectorXd vetor2){
    double produto = 0;
    produto = produto + ponto->x*vetor2[0];
    produto = produto + ponto->y*vetor2[1];
    produto = produto + ponto->z*vetor2[2];
    return produto;
}

Ponto*** biblioteca::MatrixAllocation(int size){
    auto ***matrix = new Ponto**[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new Ponto*[size];
    }
    return matrix;
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

double biblioteca::distanciaEntrePontos(Ponto *p1, Ponto *p2) {
    return sqrt(pow((p2->x - p1->x),2) + pow((p2->y - p1->y),2) + pow((p2->z - p1->z),2));
}

VectorXd biblioteca::SubtracaoPontos(Ponto* p1, Ponto* p2, int tamanho){
    //Vetor de p1 -> p2
    VectorXd vetor_resultante(tamanho);
    
    vetor_resultante[0] = p2->x - p1->x;
    vetor_resultante[1] = p2->y - p1->y;
    vetor_resultante[2] = p2->z - p1->z;
    return vetor_resultante;
}


Ponto* biblioteca::EquacaoDaReta(Ponto* p, double t, VectorXd vetor){
    Ponto* resultante = biblioteca::CriarPonto(p->x + t*vetor[0],p->y + t*vetor[1],p->z + t*vetor[2]);
    return resultante;
}

double biblioteca::EquacaoDoPlano(Ponto* p1, Ponto* p0, const VectorXd vetor_n_plano, int tamanho) {
    VectorXd vetor_aux = SubtracaoPontos(p1,p0,tamanho);
    double resultado = ProdutoEscalar(vetor_aux,vetor_n_plano,tamanho);
    return resultado;
}

Ponto* biblioteca::CriarPonto(double x, double y, double z) {
    Ponto* p = new Ponto;
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

tuple<Ponto*, Ponto*> biblioteca::PontosDadoDistancia(Ponto* p_origem, const VectorXd vetor1, const VectorXd vetor2,
                                                    double l_comprimento, int tamanho){

    double s, t;
    Ponto* p1;
    Ponto* p2;

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

Ponto* biblioteca::PontoCoordenada(Ponto* P0, Ponto* L_at, Ponto* V_up, Ponto* Pc, int tamanho, bool cord){

    VectorXd ic(tamanho); VectorXd jc(tamanho); VectorXd kc(tamanho);
    tie(ic,jc,kc) = biblioteca::DadosFotografo(P0, L_at, V_up, tamanho);

    //Transforma os Pontos P0 e Pc em VectorXd e Adiciona 1 
    VectorXd P0_vector(tamanho+1); VectorXd Pc_vector(tamanho+1);
    P0_vector << P0->x, P0->y, P0->z, 1; 
    Pc_vector << Pc->x, Pc->y, Pc->z, 1;

    //Monta a Matriz
    MatrixXd matriz(tamanho+1,tamanho+1);
    matriz = biblioteca::MontarMatrizCoodenadas(ic,jc,kc,P0_vector,tamanho,cord);

    VectorXd Pw_vector(tamanho+1);
    Pw_vector = matriz*Pc_vector;

    Ponto* Pw = biblioteca::CriarPonto(Pw_vector[0],Pw_vector[1],Pw_vector[2]);

    return Pw;

}

VectorXd biblioteca::VetorCoordenada(Ponto* P0, Ponto* L_at, Ponto* V_up, VectorXd Pc, int tamanho, bool cord){

    VectorXd ic(tamanho); VectorXd jc(tamanho); VectorXd kc(tamanho);
    tie(ic,jc,kc) = biblioteca::DadosFotografo(P0, L_at, V_up, tamanho);

    //Adiciona 0 aos VectorXd 
    VectorXd P0_vector(tamanho+1); VectorXd Pc_vector(tamanho+1);
    P0_vector << P0->x, P0->y, P0->z, 0; 
    Pc_vector << Pc[0], Pc[1], Pc[2], 0;

    //Monta a Matriz
    MatrixXd matriz(tamanho+1,tamanho+1);
    matriz = biblioteca::MontarMatrizCoodenadas(ic,jc,kc,P0_vector,tamanho,cord);

    VectorXd Pw_vector(tamanho+1);
    Pw_vector = matriz*Pc_vector;

    VectorXd Pw(tamanho);
    Pw << Pw_vector[0], Pw_vector[1], Pw_vector[2];
    
    return Pw;

}

tuple<VectorXd, VectorXd, VectorXd> biblioteca::DadosFotografo(Ponto* P0, Ponto* L_at, Ponto* V_up, int tamanho){

    VectorXd Ic(tamanho); VectorXd Kc(tamanho); VectorXd V(tamanho);
    VectorXd ic(tamanho); VectorXd kc(tamanho); VectorXd jc(tamanho);

    Kc = SubtracaoPontos(L_at, P0,tamanho);
    kc = NormalizaVetor(Kc,tamanho);

    V = SubtracaoPontos(P0,V_up,tamanho);
    Ic = ProdutoVetorial(V,kc,tamanho);
    ic = NormalizaVetor(Ic, tamanho);

    jc = ProdutoVetorial(kc,ic,tamanho);

    return make_tuple(ic,jc,kc);

}

MatrixXd biblioteca::MontarMatrizCoodenadas(VectorXd ic, VectorXd jc, VectorXd kc, VectorXd P0, int tamanho, bool cord){

    MatrixXd matriz(tamanho+1, tamanho+1);

    if (!cord){
        P0 << 
            -(ProdutoEscalar(P0,ic,tamanho)),
            -(ProdutoEscalar(P0,jc,tamanho)),
            -(ProdutoEscalar(P0,kc,tamanho)),
            P0[tamanho];
    }


    for (int i = 0; i < tamanho+1; i++){
        for (int j = 0; j < tamanho; j++){

            if (cord){
                
                if(i == 0)          matriz(j,i) = ic[j];
                else if(i == 1)     matriz(j,i) = jc[j];
                else if(i == 2)     matriz(j,i) = kc[j];        
                else if(i == 3){    
                                    matriz(i,j) = 0;
                                    matriz(j,i) = P0[j]; 
                                    matriz(i,i) = P0[i];
                }
            }

            else{

                if(i == 0)          matriz(i,j) = ic[j];
                else if(i == 1)     matriz(i,j) = jc[j];
                else if(i == 2)     matriz(i,j) = kc[j];        
                else if(i == 3){    
                                    matriz(i,j) = 0;
                                    matriz(j,i) = P0[j]; 
                                    matriz(i,i) = P0[i]; 
                }
            }

        }
    }

    return matriz;
}

