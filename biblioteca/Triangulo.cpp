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

