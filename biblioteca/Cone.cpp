//
// Created by fbeze on 24/08/2019.
//

#include <c++/cmath>
#include "Cone.hpp"
#include "Plano.hpp"



Cone::Cone(float pAltura, float pRaio, Ponto* pCentro, Vetor pNormal, Material *material) : altura(pAltura), raio(pRaio),
                                                                          centro(pCentro), normal(pNormal),
                                                                           Objeto("Cone", false, material) {}

tuple<Ponto*, Ponto*> Cone::IntersecaoReta(Ponto* pP0, const Vetor &pV0) {
    //Vertice do cone
    //V = C + H*n

    //Vetor auxiliar para calcular o vertice do cone (H*n)
    Vetor vetor_aux = normal * altura;

    Ponto* vertice = biblioteca::CriarPonto(this->centro->x + vetor_aux.x, this->centro->y + vetor_aux.y,
            this->centro->z + vetor_aux.z);

    //vetor d normalizado
    Vetor d = biblioteca::NormalizaVetor(pV0);

    //cos alfa
    double cos_alfa = this->altura / (sqrt(pow(this->altura,2) + pow(raio,2)));

    //vetor v
    Vetor v(vertice->x - pP0->x, vertice->y - pP0->y, vertice->z - pP0->z);

    //a
    double a = pow(biblioteca::ProdutoEscalar(d,this->normal),2) - (biblioteca::ProdutoEscalar(d,d)*pow(cos_alfa,2));

    //b
    double b = (biblioteca::ProdutoEscalar(v,d) * pow(cos_alfa,2))
            - (biblioteca::ProdutoEscalar(v,this->normal))
            * (biblioteca::ProdutoEscalar(d,this->normal));

    //c
    double c = pow(biblioteca::ProdutoEscalar(v,this->normal),2)
            - (biblioteca::ProdutoEscalar(v,v)*pow(cos_alfa,2));

    //delta
    double delta = b*b - a*c;

    if (delta < 0.00000000001 && delta >-0.00000000001 )
        delta = 0;
    if (a < 0.00000000001 && a>-0.00000000001)
        a = 0;
    if (b < 0.00000000001 && b>-0.00000000001)
        b = 0;
    if (c < 0.00000000001 && c>-0.00000000001)
        c = 0;

    /*  Δ > 0 tem 2 intersecoes
        Δ = 0 tem 1 intersecao
        Δ < 0 tem 0 intersecoes */

    double t_int1,t_int2;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;
    bool tratamento_int1 = false, tratamento_int2 = false;

    if (delta > 0){
        if(a!=0){
            t_int1 = (-b + sqrt(delta))/a;
            t_int2 = (-b - sqrt(delta))/a;
        }else{
            t_int1 = -c / 2*b;
            t_int2 = -c / 2*b;
        }

        Ponto* p_teste1 = biblioteca::EquacaoDaReta(*pP0,t_int1,d);
        Ponto* p_teste2 = biblioteca::EquacaoDaReta(*pP0,t_int2,d);
        tratamento_int1 = this->ValidacaoPontoCone(vertice,p_teste1);
        tratamento_int2 = this->ValidacaoPontoCone(vertice,p_teste2);

        if (tratamento_int1)
            p_int1 = p_teste1;
        else if(Cone::ValidacaoPontoBase(pP0, d))
            p_int1 = Cone::IntersecaoRetaBase(this->centro, pP0, d);

        if (tratamento_int2) 
            p_int2 = p_teste2;
        else if(Cone::ValidacaoPontoBase(pP0, d))
            p_int2 = Cone::IntersecaoRetaBase(this->centro, pP0, d);
        
    }
    else if (delta == 0 && (b!=0 && a!=0)){
        t_int1 = (-b + sqrt(delta))/a;
        Ponto* p_teste1 = biblioteca::EquacaoDaReta(*pP0,t_int1,d);
        tratamento_int1 = this->ValidacaoPontoCone(vertice,p_teste1);

        if (tratamento_int1)
            p_int1 = p_teste1;
        if(Cone::ValidacaoPontoBase(pP0, d))
            p_int2 = Cone::IntersecaoRetaBase(this->centro, pP0, d);

    }

    return make_tuple(p_int1, p_int2);
    
}

bool Cone::ValidacaoPontoCone(Ponto* vertice, Ponto* p_int){

    //escalar_tratamento e vetor_aux_tratamento
    Vetor vetor_aux_tratamento(vertice->x - p_int->x, vertice->y - p_int->y, vertice->z - p_int->z);

    double escalar_tratamento = biblioteca::ProdutoEscalar(vetor_aux_tratamento,this->normal);
    
    bool tratamento_int = false;
    if(escalar_tratamento < 0.00000000001 && escalar_tratamento > 0.00000000001)
        escalar_tratamento = 0;
    if(escalar_tratamento >= 0 && escalar_tratamento <= this->altura){
        tratamento_int = true;
    }

    return tratamento_int;
}

Ponto* Cone::IntersecaoRetaBase(Ponto* centro, Ponto* pP0, const Vetor &pVetor0){
    Plano* base = new Plano(centro, this->normal);
    Ponto* p_int = base->IntersecaoRetaPlano(*pP0, pVetor0);
    return p_int;
}

bool Cone::ValidacaoPontoBase(Ponto* pP0, const Vetor &pVetor0){
    /*
        Interseção com nenhuma Base = 0
        Interseção com uma Base = 1
    */

    Ponto* p = IntersecaoRetaBase(centro, pP0, pVetor0);

    return p && biblioteca::distanciaEntrePontos(p,centro) <= raio;

}

void Cone::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
    camera->mudarMundoCamera(normal);
}

void Cone::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(centro);
    camera->mudarCameraMundo(normal);
}

Vetor Cone::calcularNormal(Ponto* pi) {

    Vetor vetor_aux = normal*altura;

    Ponto* Vertice = new Ponto{centro->x + vetor_aux.x, centro->y + vetor_aux.y,
                                           centro->z + vetor_aux.z};

    Vetor PImenosCB = biblioteca::SubtracaoPontos(*centro, *pi);

    double aux = biblioteca::ProdutoEscalar(PImenosCB, normal);
    Ponto* pe = biblioteca::EquacaoDaReta(*centro, aux, normal);


    Vetor PImenosPE = biblioteca::SubtracaoPontos(*pe, *pi);
    Vetor PiV = biblioteca::SubtracaoPontos(*pi, *Vertice);

    Vetor T = biblioteca::ProdutoVetorial(PiV, PImenosPE);
    Vetor N = biblioteca::ProdutoVetorial(T, PiV);

    delete pe;
    delete Vertice;
    return biblioteca::NormalizaVetor(N);
}

Ponto *Cone::PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) {
    return nullptr;
}

