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

tuple<Ponto,Ponto,int> Biblioteca::IntersecaoRetaEsfera(Ponto p0, VectorXd vetor0, Ponto c0_centro, float raio, int tamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto p_t_int1, p_t_int2;
    double t_int1, t_int2;

    // A*t_int² + B*t_int + C = 0

    // C0P0 eh o P0 - C0
    VectorXd C0P0 = this->SubtracaoPontos(p0,c0_centro,tamanho);

    // A = u*u
    double produtoA = this->ProdutoEscalar(vetor0,vetor0,tamanho);

    // B = 2 * (P0 - C0) * u
    double produtoB = 2 * this->ProdutoEscalar(C0P0,vetor0,tamanho);

    // C = (P0 - C0) * (P0 - C0) - R²
    double produtoC = this->ProdutoEscalar(C0P0,C0P0,tamanho) - (raio*raio);

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    int intersec = 0;
    double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);

    if (Delta > 0){

        intersec = 2;
        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        t_int2 = (-produtoB - sqrt(Delta))/produtoA;
        p_t_int1 = this->EquacaoDaReta(p0,t_int1,vetor0);
        p_t_int2 = this->EquacaoDaReta(p0,t_int2,vetor0);
    }
    
    else if (Delta == 0){        
        
        intersec = 1;
        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        p_t_int1 = this->EquacaoDaReta(p0,t_int1,vetor0);
    }

    return make_tuple(p_t_int1, p_t_int2, intersec);

}

tuple<Ponto,Ponto,int> Biblioteca::IntersecaoRetaCilindro(Ponto p0, VectorXd vetor0, VectorXd vetor_n, Ponto c0_centro, float raio, float H, int tamanho){
    //p_t_int eh o ponto dado o t_int
    Ponto p_t_int1, p_t_int2;
    double t_int1, t_int2;

    // A*t_int² + 2B*t_int + C = 0

    // Normalizar o vetor_d
    vetor_n = this->NormalizaVetor(vetor0,tamanho);

    // C0P0 eh o P0 - C0
    VectorXd C0P0 = this->SubtracaoPontos(p0,c0_centro,tamanho);

    // V eh o ((C0P0) - ((C0P0)* vetor0)* vetor0)
    double C0P0_u = this->ProdutoEscalar(C0P0,vetor0,tamanho);
    VectorXd v = C0P0 - (C0P0_u * vetor0);

    // W eh o (vetor_n - (vetor_n * vetor0)*vetor0)
    double VetorN_u = this->ProdutoEscalar(vetor_n,vetor0,tamanho);
    VectorXd w = vetor_n - (VetorN_u * vetor0);
   
    //A = w*w
    double produtoA = this->ProdutoEscalar(w,w,tamanho);

    //B = (v*w)
    double produtoB = this->ProdutoEscalar(v,w,tamanho);
    
    //C = (v*v - R²)
    double produtoC = this->ProdutoEscalar(v,v,tamanho) - (raio*raio);
    
    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    int intersec = 0;
    bool tratamento = ((0 <= C0P0_u && C0P0_u <= H) ? true : false);
    double Delta = (produtoB*produtoB) - (produtoA)*(produtoC);

    if (Delta > 0 && tratamento){

        intersec = 2;
        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        t_int2 = (-produtoB - sqrt(Delta))/produtoA;
        p_t_int1 = this->EquacaoDaReta(p0,t_int1,vetor0);
        p_t_int2 = this->EquacaoDaReta(p0,t_int2,vetor0);
    }
    
    else if (Delta == 0 && tratamento){        
        
        intersec = 1;
        t_int1 = (-produtoB + sqrt(Delta))/produtoA;
        p_t_int1 = this->EquacaoDaReta(p0,t_int1,vetor0);
    }

    return make_tuple(p_t_int1, p_t_int2, intersec);
}


tuple<Ponto, Ponto> Biblioteca::PontosDadoDistancia(Ponto p_origem, const VectorXd vetor1, const VectorXd vetor2,
                                     double l_comprimento, int tamanho){

    double s, t;
    Ponto p1, p2;

    s = pow(l_comprimento, 2);
    s = s/((ProdutoEscalar(vetor2,vetor2,tamanho)) -
           (pow(ProdutoEscalar(vetor1,vetor2,tamanho),2)/ProdutoEscalar(vetor1,vetor1,tamanho)));
    s = sqrt(s);

    t = ProdutoEscalar(vetor1,vetor2,tamanho)/ProdutoEscalar(vetor1,vetor1,tamanho);
    t = t * s;

    p1 = this->EquacaoDaReta(p_origem, t, vetor1);
    p2 = this->EquacaoDaReta(p_origem, s, vetor2);

    return make_tuple(p1,p2);

}

tuple<Ponto, Ponto, int, int> Biblioteca::IntersecaoRetaCone(Ponto p0, VectorXd vetor0, VectorXd vetor_n, Ponto c0_centro, float raio, float H, int tamanho){
    
    //Vertice do cone
    //V = C + H*n

    //Vetor auxiliar para calcular o vertice do cone (H*n)
    VectorXd vetor_aux = H*vetor_n;

    Ponto vertice;
    vertice.x = c0_centro.x + vetor_aux[0];
    vertice.y = c0_centro.y + vetor_aux[1];
    vertice.z = c0_centro.z + vetor_aux[2];
    //cout << vertice.x << vertice.y << vertice.z << endl;
    
    //vetor d normalizado
    VectorXd d = this->NormalizaVetor(vetor0,tamanho);

    //cos alfa
    double cos_alfa = H / (sqrt(pow(H,2) + pow(raio,2)));
    
    //vetor v
    VectorXd v(tamanho);
    v[0] = vertice.x - p0.x;
    v[1] = vertice.y - p0.y;
    v[2] = vertice.z - p0.z;
    //cout << v << endl;

    //a
    double a = pow(this->ProdutoEscalar(d,vetor_n,tamanho),2) - pow(cos_alfa,2);
    //cout << a << endl;

    //b
    double b = (this->ProdutoEscalar(v,d,tamanho) * pow(cos_alfa,2)) - (this->ProdutoEscalar(v,vetor_n,tamanho)) * (this->ProdutoEscalar(d,vetor_n,tamanho));
    //cout << b << endl;

    //c
    double c = pow(this->ProdutoEscalar(v,vetor_n,tamanho),2) - (this->ProdutoEscalar(v,v,tamanho)*pow(cos_alfa,2));
    //cout << c << endl;

    //delta
    double delta = b*b - a*c;
    //cout<<"delta:"<<delta<<endl;

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    int intersec = 0;
    double t_int1,t_int2;
    Ponto p_int1,p_int2;
    bool tratamento_int1 = false, tratamento_int2 = false;

    if (delta > 0){
        intersec = 2;

        if(a!=0){
            t_int1 = (-b + sqrt(delta))/a;
            t_int2 = (-b - sqrt(delta))/a;
        }else{
            t_int1 = -c / 2*b;
            t_int2 = -c / 2*b;
        }

        p_int1 = this->EquacaoDaReta(p0,t_int1,vetor0);
        p_int2 = this->EquacaoDaReta(p0,t_int2,vetor0);
        tratamento_int1 = this->ValidacaoPontoCone(vertice,p_int1,vetor_n,H,tamanho);
        tratamento_int2 = this->ValidacaoPontoCone(vertice,p_int2,vetor_n,H,tamanho);
        
    }
    else if (delta == 0 && (b!=0 && a!=0)){        
        intersec = 1;
        t_int1 = (-b + sqrt(delta))/a;
        p_int1 = this->EquacaoDaReta(p0,t_int1,vetor0);
        tratamento_int1 = this->ValidacaoPontoCone(vertice,p_int1,vetor_n,H,tamanho);
    }

    /* Pontos validos
        0 = nenhum ponto valido
        1 = primeiro ponto valido apenas
        2 = segundo ponto valido apenas
        3 = os dois pontos sao validos
    */

    int validacao = 0;

    if(tratamento_int1 && tratamento_int2){
        validacao = 3;
    }else if(tratamento_int1 && !tratamento_int2){
        validacao = 1;
    }else if(!tratamento_int1 && tratamento_int2){
        validacao = 2;
    }

    return make_tuple(p_int1, p_int2, validacao, intersec);
}

bool Biblioteca::ValidacaoPontoCone(Ponto vertice, Ponto p_int, VectorXd vetor_n, float H, int tamanho){
    
    //escalar_tratamento e vetor_aux_tratamento
    VectorXd vetor_aux_tratamento(tamanho);
    vetor_aux_tratamento[0] = vertice.x - p_int.x;
    vetor_aux_tratamento[1] = vertice.y - p_int.y;
    vetor_aux_tratamento[2] = vertice.z - p_int.z;
    
    double escalar_tratamento = this->ProdutoEscalar(vetor_aux_tratamento,vetor_n,tamanho);

    bool tratamento_int = ((0 <= escalar_tratamento && escalar_tratamento <= H) ? true : false);

    return tratamento_int;
}