//
// Created by fbeze on 24/08/2019.
//

#include <c++/cfloat>
#include <c++/cmath>
#include "Cilindro.hpp"
#include "Plano.hpp"
#include "Cluster.h"


Cilindro::Cilindro(float pAltura, float pRaio, Ponto pCentro, Vetor pNormal, Material *m) : altura(pAltura),
    raio(pRaio), centro(pCentro), normal(pNormal), baseInf(&centro, pNormal),
    baseSup(), Objeto("Cilindro", false, m) {

    Vetor H_n = normal*altura;
    centroSup = Ponto{centro.x + H_n.x, centro.y + H_n.y, centro.z + H_n.z};
    baseSup = Plano(&centroSup, normal);
}

tuple<Ponto*,Objeto*> Cilindro::IntersecaoReta(Ponto* pP0, const Vetor &pV0){
    Ponto* p_int1 = PrimeiraIntersecao(*pP0, pV0);
    return make_tuple(p_int1, this);
}

bool Cilindro::ValidacaoPontoLateral(const Ponto &p_int) const {
    Vetor PB = biblioteca::SubtracaoPontos(centro, p_int);
    double PB_u = biblioteca::ProdutoEscalar(PB, normal);

    return 0 <= PB_u && PB_u <= altura;
}

Vetor Cilindro::calcularNormal(Ponto* pi){
    Vetor PImenosCB = biblioteca::SubtracaoPontos(centro, *pi);
    double aux = biblioteca::ProdutoEscalar(PImenosCB, normal);
    Vetor aux2 = normal * aux;

    Ponto pe{centro.x + aux2.x, centro.y + aux2.y, centro.z + aux2.z};
    Vetor PImenosPE = biblioteca::SubtracaoPontos(pe, *pi);

    Vetor normalAoPonto = PImenosPE / raio;
    return normalAoPonto;
};

void Cilindro::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(&centro);
    camera->mudarMundoCamera(normal);
    camera->mudarMundoCamera(&centroSup);
    camera->mudarMundoCamera(baseInf.normal);
    camera->mudarMundoCamera(baseSup.normal);
}

void Cilindro::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(&centro);
    camera->mudarCameraMundo(normal);
    camera->mudarCameraMundo(&centroSup);
    camera->mudarCameraMundo(baseInf.normal);
    camera->mudarCameraMundo(baseSup.normal);
}

Ponto *Cilindro::PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) {
    // A*t_int² + 2B*t_int + C = 0

    // Normalizar o vetor_d
    auto vetorNorm = biblioteca::NormalizaVetor(pVetor0);

    // C0P0 eh o P0 - C0
    Vetor C0P0 = biblioteca::SubtracaoPontos(centro, pP0);

    // V eh o ((C0P0) - ((C0P0)* vetor_n)* vetor_n)
    Vetor v = C0P0 - (normal * biblioteca::ProdutoEscalar(C0P0, normal));

    // W eh o (pVetor0 - (pVetor0 * vetor_n)*vetor_n)
    Vetor w = vetorNorm - (normal * biblioteca::ProdutoEscalar(vetorNorm,normal));

    //A = w*w
    double a = biblioteca::ProdutoEscalar(w,w);

    //B = (v*w)
    double b = biblioteca::ProdutoEscalar(v,w);

    //C = (v*v - R²)
    double c = biblioteca::ProdutoEscalar(v,v) - (raio*raio);

    //delta
    double delta = b*b - a*c;
    /*  Δ > 0 tem 2 intersecoes
         Δ = 0 tem 1 intersecao
         Δ < 0 tem 0 intersecoes */

    double t_int1,t_int2;
    auto menorDistancia = DBL_MAX;

    // Intersecao com a base
    Ponto* p_int1 = baseInf.IntersecaoRetaPlano(pP0,pVetor0);
    if(p_int1) {
        if(biblioteca::distanciaEntrePontos(*p_int1, centro) > raio){
            p_int1 = nullptr;
        } else {
            menorDistancia = biblioteca::distanciaEntrePontos(pP0, *p_int1);
        }
    }

    // Intersecao com o topo
    Ponto* p_int2 = baseSup.IntersecaoRetaPlano(pP0,pVetor0);
    if(p_int2 && biblioteca::distanciaEntrePontos(*p_int2, centroSup) <= raio) {
        double dist2 = biblioteca::distanciaEntrePontos(*p_int2, pP0);
        if(!p_int1 || dist2 < menorDistancia) {
            p_int1 = p_int2;
            menorDistancia = dist2;
        }
    }

    // Intersecao com a lateral
    t_int1 = (-b + sqrt(delta))/a;
    t_int2 = (-b - sqrt(delta))/a;

    Ponto* p_teste1 = biblioteca::EquacaoDaReta(pP0, t_int1, vetorNorm);
    Ponto* p_teste2 = biblioteca::EquacaoDaReta(pP0, t_int2, vetorNorm);


    if (ValidacaoPontoLateral(*p_teste1)){
        double dist1 = biblioteca::distanciaEntrePontos(*p_teste1, pP0);
        if(dist1 < menorDistancia) {
            p_int1 = p_teste1;
            menorDistancia = dist1;
        }
    }
    if (ValidacaoPontoLateral(*p_teste2)) {
        double dist2 = biblioteca::distanciaEntrePontos(*p_teste2, pP0);
        if(dist2 < menorDistancia) {
            p_int1 = p_teste2;
        }
    }

    return p_int1;
}

Objeto* Cilindro::aplicarEspelhamento(vector<Matriz> &pMatrizesTransf){
    Matriz centroAux = Matriz(4,1,0);
    centroAux(0,0) = centro.x;
    centroAux(1,0) = centro.y;
    centroAux(2,0) = centro.z;
    centroAux(3,0) = 1;
    for (auto &matriz : pMatrizesTransf) {
        centroAux = matriz * centroAux;
    }

    return new Cilindro(altura, raio, Ponto{centroAux(0,0), centroAux(1,0), centroAux(2,0)},
                    normal, material);
}

Ponto *Cilindro::getCentro() {
    return &centro;
}

void Cilindro::aplicarTransformacao(vector<Matriz> &pMatrizesTransf) {
    Matriz centroAux = Matriz(4,1,0);
    centroAux(0,0) = centro.x;
    centroAux(1,0) = centro.y;
    centroAux(2,0) = centro.z;
    centroAux(3,0) = 1;
    Matriz centroSupAux = Matriz(4,1,0);
    centroSupAux(0,0) = centroSup.x;
    centroSupAux(1,0) = centroSup.y;
    centroSupAux(2,0) = centroSup.z;
    centroSupAux(3,0) = 1;
    Matriz normalBiSAux = Matriz(4,1,0);
    normalBiSAux(0,0) = baseSup.normal.x;
    normalBiSAux(1,0) = baseSup.normal.y;
    normalBiSAux(2,0) = baseSup.normal.z;
    normalBiSAux(3,0) = 0;
    Matriz normalAux = Matriz(4,1,0);
    normalAux(0,0) = normal.x;
    normalAux(1,0) = normal.y;
    normalAux(2,0) = normal.z;
    normalAux(3,0) = 0;
    for (auto &matriz : pMatrizesTransf) {
        centroAux = matriz * centroAux;
        centroSupAux = matriz * centroSupAux;
        normalBiSAux = matriz * normalBiSAux;
        normalAux = matriz * normalAux;
    }
    centro.x = centroAux(0,0);
    centro.y = centroAux(1,0);
    centro.z = centroAux(2,0);

    centroSup.x = centroSupAux(0,0);
    centroSup.y = centroSupAux(1,0);
    centroSup.z = centroSupAux(2,0);

    normal.x = normalAux(0,0);
    normal.y = normalAux(1,0);
    normal.z = normalAux(2,0);
    baseInf.normal = normal;

    baseSup.normal.x = normalBiSAux(0,0);
    baseSup.normal.y = normalBiSAux(1,0);
    baseSup.normal.z = normalBiSAux(2,0);
}

tuple<Ponto, Ponto> Cilindro::Limites()
{
    Ponto max = centro + (normal * altura);
    Ponto min = centro + (normal * altura);
    Vetor prod(1, 0, 0);
    if(normal.y != 1) {
        prod = biblioteca::ProdutoVetorial(normal, Vetor(0, 1, 0));
    }
    Vetor prod2 = biblioteca::ProdutoVetorial(prod, normal);
    for(int i = 0; i < 4; i ++) {
        Ponto pBase = centro + (prod * raio) + (prod2 * raio);
        if(pBase.x > max.x){
            max.x = pBase.x;
        }
        if(pBase.y > max.y){
            max.y = pBase.y;
        }
        if(pBase.z > max.z){
            max.z = pBase.z;
        }
        if(pBase.x < min.x){
            min.x = pBase.x;
        }
        if(pBase.y < min.y){
            min.y = pBase.y;
        }
        if(pBase.z < min.z){
            min.z = pBase.z;
        }
        Ponto pTopo = pBase + (normal * altura);
        if(pTopo.x > max.x){
            max.x = pBase.x;
        }
        if(pTopo.y > max.y){
            max.y = pBase.y;
        }
        if(pTopo.z > max.z){
            max.z = pBase.z;
        }
        if(pTopo.x < min.x){
            min.x = pBase.x;
        }
        if(pTopo.y < min.y){
            min.y = pBase.y;
        }
        if(pTopo.z < min.z){
            min.z = pBase.z;
        }
        prod = prod2;
        prod2 = biblioteca::ProdutoVetorial(prod, normal);
    }
    return make_tuple(max, min);
}
