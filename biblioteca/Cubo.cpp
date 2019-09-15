
//
// Created by thais on 26/08/2019.
//

#include "Cubo.hpp"
#include "biblioteca.hpp"
#include "Plano.hpp"

Cubo::Cubo(double cAresta, Ponto* cCentro, Material* material): aresta(cAresta), centro(cCentro),
Objeto("Cubo", false, material){
    Ponto* p1 = biblioteca::CriarPonto(centro->x - aresta/2, centro->y + aresta, centro->z + aresta/2);
    Ponto* p2 = biblioteca::CriarPonto(centro->x - aresta/2, centro->y + aresta, centro->z - aresta/2);
    Ponto* p3 = biblioteca::CriarPonto(centro->x + aresta/2, centro->y + aresta, centro->z - aresta/2);
    Ponto* p4 = biblioteca::CriarPonto(centro->x + aresta/2, centro->y + aresta, centro->z + aresta/2);
    Ponto* p5 = biblioteca::CriarPonto(centro->x - aresta/2, centro->y, centro->z + aresta/2);
    Ponto* p6 = biblioteca::CriarPonto(centro->x - aresta/2, centro->y, centro->z - aresta/2);
    Ponto* p7 = biblioteca::CriarPonto(centro->x + aresta/2, centro->y, centro->z - aresta/2);
    Ponto* p8 = biblioteca::CriarPonto(centro->x + aresta/2, centro->y, centro->z + aresta/2);

    vertices.push_back(CriarVertice(p1, "V1"));
    vertices.push_back(CriarVertice(p2, "V2"));
    vertices.push_back(CriarVertice(p3, "V3"));
    vertices.push_back(CriarVertice(p4, "V4"));
    vertices.push_back(CriarVertice(p5, "V5"));
    vertices.push_back(CriarVertice(p6, "V6"));
    vertices.push_back(CriarVertice(p7, "V7"));
    vertices.push_back(CriarVertice(p8, "V8"));

    faces.push_back(CriarFace(vertices[0], vertices[3], vertices[2], "F1"));
    faces.push_back(CriarFace(vertices[2], vertices[1], vertices[0], "F2"));
    faces.push_back(CriarFace(vertices[6], vertices[5], vertices[2], "F3"));
    faces.push_back(CriarFace(vertices[5], vertices[1], vertices[2], "F4"));
    faces.push_back(CriarFace(vertices[7], vertices[6], vertices[3], "F5"));
    faces.push_back(CriarFace(vertices[6], vertices[2], vertices[3], "F6"));
    faces.push_back(CriarFace(vertices[4], vertices[7], vertices[3], "F7"));
    faces.push_back(CriarFace(vertices[3], vertices[0], vertices[4], "F8"));
    faces.push_back(CriarFace(vertices[6], vertices[7], vertices[4], "F9"));
    faces.push_back(CriarFace(vertices[4], vertices[5], vertices[6], "F10"));
    faces.push_back(CriarFace(vertices[0], vertices[5], vertices[4], "F11"));
    faces.push_back(CriarFace(vertices[5], vertices[0], vertices[1], "F12"));


    for (auto face: faces) {
        Vetor p1p2 = biblioteca::SubtracaoPontos(*face->p1->p, *face->p2->p);
        Vetor p1p3 = biblioteca::SubtracaoPontos(*face->p1->p, *face->p3->p);
        face->p = new Plano(face->p1->p, biblioteca::EncontrarNormal(p1p2, p1p3));
    }

}

Vetor Cubo::calcularNormal(Ponto* p){
    return normal;
}

tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, const Vetor &pV0) {

    vector< pair<Ponto*, Face*> > intFace;
    for (int i = 0; i < faces.size()-1; i +=2) {
        Ponto *p = faces[i]->p->IntersecaoRetaPlano(*pP0, pV0);

        if (p) {
            Vetor p1p = biblioteca::SubtracaoPontos(*faces[i]->p1->p, *p);
            Vetor p2p = biblioteca::SubtracaoPontos(*faces[i]->p2->p, *p);
            Vetor p3p = biblioteca::SubtracaoPontos(*faces[i]->p3->p, *p);
            Vetor p2p3 = biblioteca::SubtracaoPontos(*faces[i]->p2->p, *faces[i]->p3->p);
            Vetor p3p1 = biblioteca::SubtracaoPontos(*faces[i]->p3->p, *faces[i]->p1->p);
            Vetor p1p2 = biblioteca::SubtracaoPontos(*faces[i]->p1->p, *faces[i]->p2->p);
            Vetor p1p3 = biblioteca::SubtracaoPontos(*faces[i]->p1->p, *faces[i]->p3->p);

            if (ValidacaoPontoCubo(p1p2, p1p, p1p2, p1p3) && ValidacaoPontoCubo(p2p3, p2p, p1p2, p1p3) &&
                ValidacaoPontoCubo(p3p1, p3p, p1p2, p1p3)) {

                intFace.emplace_back(make_pair(p, faces[i]));

                normal = faces[i]->p->normal;
            } else {
                p1p = biblioteca::SubtracaoPontos(*faces[i + 1]->p1->p, *p);
                p2p = biblioteca::SubtracaoPontos(*faces[i + 1]->p2->p, *p);
                p3p = biblioteca::SubtracaoPontos(*faces[i + 1]->p3->p, *p);
                p2p3 = biblioteca::SubtracaoPontos(*faces[i + 1]->p2->p, *faces[i + 1]->p3->p);
                p3p1 = biblioteca::SubtracaoPontos(*faces[i + 1]->p3->p, *faces[i + 1]->p1->p);
                p1p2 = biblioteca::SubtracaoPontos(*faces[i + 1]->p1->p, *faces[i + 1]->p2->p);
                p1p3 = biblioteca::SubtracaoPontos(*faces[i + 1]->p1->p, *faces[i + 1]->p3->p);

                if (ValidacaoPontoCubo(p1p2, p1p, p1p2, p1p3) && ValidacaoPontoCubo(p2p3, p2p, p1p2, p1p3) &&
                    ValidacaoPontoCubo(p3p1, p3p, p1p2, p1p3)) {

                    intFace.emplace_back(make_pair(p, faces[i + 1]));

                    normal = faces[i + 1]->p->normal;
                } else {
                    delete p;
                }
            }
        }
        if(intFace.size() == 2){
            break;
        }
    }


    if(!intFace.empty()) {
        if (intFace.size() >= 2) {
            if (biblioteca::distanciaEntrePontos(pP0, intFace[0].first) <
                biblioteca::distanciaEntrePontos(pP0, intFace[1].first)) {
                normal = intFace[0].second->p->normal;
            }
        }
        else {
            normal = intFace[0].second->p->normal;
        }
    }

    return make_tuple(intFace.size() > 0 ? intFace[0].first: nullptr, intFace.size() > 1 ? intFace[1].first: nullptr);

}

Vertice* Cubo::CriarVertice(Ponto* ponto, string identificador){
    auto v = new Vertice();
    v->p = ponto;
    v->id = identificador;
    return v;
}

Aresta* Cubo::CriarAresta(Vertice *pi, Vertice *pf, string id) {
    auto newAresta = new Aresta;
    newAresta->id = id;
    newAresta->verticeFinal = pf;
    newAresta->verticeInicial = pi;
    return newAresta;
}

Face* Cubo::CriarFace(Vertice* v1, Vertice* v2, Vertice* v3, string id){
    auto newFace = new Face;
    newFace->p1 = v1;
    newFace->p2 = v2;
    newFace->p3 = v3;
    newFace->id = id;
}

bool Cubo::ValidacaoPontoCubo(const Vetor &PxPy, const Vetor &PxP, const Vetor &P1P2, const Vetor &P1P3) {

    double validacao = biblioteca::ProdutoEscalar(biblioteca::ProdutoVetorial(PxPy, PxP),
        biblioteca::ProdutoVetorial(P1P2, P1P3));

    return validacao > 0;
}

void Cubo::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
    //camera->mudarMundoCamera(normal);
    for (auto vertice: vertices) {
        camera->mudarMundoCamera(vertice->p);
    }
    for (auto face: faces) {
        camera->mudarMundoCamera(face->p->normal);
    }
}

void Cubo::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(centro);
    //camera->mudarCameraMundo(normal);
    for (auto vertice: vertices) {
        camera->mudarMundoCamera(vertice->p);
    }
    for (auto face: faces) {
        camera->mudarMundoCamera(face->p->normal);
    }

}

Ponto *Cubo::PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) {
    return nullptr;
}
