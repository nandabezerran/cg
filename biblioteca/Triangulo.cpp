//
// Created by fbeze on 15/09/2019.
//

#include "Triangulo.hpp"

Triangulo::Triangulo(const string &pId, Vertice *pP1, Vertice *pP2, Vertice *pP3, Plano *pP) : id(pId), p1(pP1),
                p2(pP2),p3(pP3),p(pP){

    p2p3 = biblioteca::SubtracaoPontos(*p2->p, *p3->p);
    p3p1 = biblioteca::SubtracaoPontos(*p3->p, *p1->p);
    p1p2 = biblioteca::SubtracaoPontos(*p1->p, *p2->p);
    p1p3 = biblioteca::SubtracaoPontos(*p1->p, *p3->p);
}

void Triangulo::mudaCoodMundo(Camera *camera) {
    camera->mudarMundoCamera(p->normal);
    camera->mudarMundoCamera(p2p3);
    camera->mudarMundoCamera(p3p1);
    camera->mudarMundoCamera(p1p2);
    camera->mudarMundoCamera(p1p3);
}

void Triangulo::mudaCoodCamera(Camera *camera) {
    camera->mudarCameraMundo(p->normal);
    camera->mudarCameraMundo(p2p3);
    camera->mudarCameraMundo(p3p1);
    camera->mudarCameraMundo(p1p2);
    camera->mudarCameraMundo(p1p3);
}

bool Triangulo::ValidacaoPontoTriangulo(const Vetor &P1P, const Vetor &P2P, const Vetor &P3P) {
    double validacao = biblioteca::ProdutoEscalar(biblioteca::ProdutoVetorial(p1p2, P1P),
                                                  biblioteca::ProdutoVetorial(p1p2, p1p3));
    if(validacao < 0){
        return false;
    }

    validacao = biblioteca::ProdutoEscalar(biblioteca::ProdutoVetorial(p2p3, P2P),
                                                  biblioteca::ProdutoVetorial(p1p2, p1p3));
    if(validacao < 0){
        return false;
    }

    validacao = biblioteca::ProdutoEscalar(biblioteca::ProdutoVetorial(p3p1, P3P),
                                           biblioteca::ProdutoVetorial(p1p2, p1p3));

    return validacao > 0;
}

Ponto *Triangulo::intersecaoReta(Ponto *pP0, const Vetor &pV0) {
    Ponto *ponto = p->IntersecaoRetaPlano(*pP0, pV0);
    if (ponto) {
        Vetor p1p = biblioteca::SubtracaoPontos(*p1->p, *ponto);
        Vetor p2p = biblioteca::SubtracaoPontos(*p2->p, *ponto);
        Vetor p3p = biblioteca::SubtracaoPontos(*p3->p, *ponto);

        if (ValidacaoPontoTriangulo(p1p,p2p,p3p)) {
            return ponto;
        }
    }
    return nullptr;
}

void Triangulo::aplicarTransformacao(vector<Matriz> &pMatrizesTransf) {
    Matriz normalAux = Matriz(4,1,0);
    normalAux(0,0) = p->normal.x; normalAux(1,0) = p->normal.y; normalAux(2,0) = p->normal.z; normalAux(3,0) = 0;
    Matriz p2p3aux = Matriz(4,1,0);
    p2p3aux(0,0) = p2p3.x; p2p3aux(1,0) = p2p3.y; p2p3aux(2,0) = p2p3.z; p2p3aux(3,0) = 0;
    Matriz p3p1aux = Matriz(4,1,0);
    p3p1aux(0,0) = p3p1.x; p3p1aux(1,0) = p3p1.y; p3p1aux(2,0) = p3p1.z; p3p1aux(3,0) = 0;
    Matriz p1p2aux = Matriz(4,1,0);
    p1p2aux(0,0) = p1p2.x; p1p2aux(1,0) = p1p2.y; p1p2aux(2,0) = p1p2.z; p1p2aux(3,0) = 0;
    Matriz p1p3aux = Matriz(4,1,0);
    p1p3aux(0,0) = p1p3.x; p1p3aux(1,0) = p1p3.y; p1p3aux(2,0) = p1p3.z; p1p3aux(3,0) = 0;

    for (auto matriz : pMatrizesTransf) {
        normalAux = matriz * normalAux;
        p2p3aux = matriz * p2p3aux;
        p3p1aux = matriz * p3p1aux;
        p1p2aux = matriz * p1p2aux;
        p1p3aux = matriz * p1p3aux;

    }

    p->normal.x = normalAux(0,0);
    p->normal.y = normalAux(1,0);
    p->normal.z = normalAux(2,0);

    p2p3.x = p2p3aux(0,0);
    p2p3.y = p2p3aux(1,0);
    p2p3.z = p2p3aux(2,0);

    p3p1.x =  p3p1aux(0,0);
    p3p1.y =  p3p1aux(1,0);
    p3p1.z =  p3p1aux(2,0);

    p1p2.x = p1p2aux(0,0);
    p1p2.y = p1p2aux(1,0);
    p1p2.z = p1p2aux(2,0);

    p1p3.x = p1p3aux(0,0);
    p1p3.y = p1p3aux(1,0);
    p1p3.z = p1p3aux(2,0);
}

