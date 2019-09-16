
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

    triangulos.push_back(CriarTriangulo(vertices[0], vertices[3], vertices[2], "F1"));
    triangulos.push_back(CriarTriangulo(vertices[2], vertices[1], vertices[0], "F2"));
    triangulos.push_back(CriarTriangulo(vertices[6], vertices[5], vertices[2], "F3"));
    triangulos.push_back(CriarTriangulo(vertices[5], vertices[1], vertices[2], "F4"));
    triangulos.push_back(CriarTriangulo(vertices[7], vertices[6], vertices[3], "F5"));
    triangulos.push_back(CriarTriangulo(vertices[6], vertices[2], vertices[3], "F6"));
    triangulos.push_back(CriarTriangulo(vertices[4], vertices[7], vertices[3], "F7"));
    triangulos.push_back(CriarTriangulo(vertices[3], vertices[0], vertices[4], "F8"));
    triangulos.push_back(CriarTriangulo(vertices[6], vertices[7], vertices[4], "F9"));
    triangulos.push_back(CriarTriangulo(vertices[4], vertices[5], vertices[6], "F10"));
    triangulos.push_back(CriarTriangulo(vertices[0], vertices[5], vertices[4], "F11"));
    triangulos.push_back(CriarTriangulo(vertices[5], vertices[0], vertices[1], "F12"));

}

Vetor Cubo::calcularNormal(Ponto* p){
    return normal;
}

tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, const Vetor &pV0) {

    vector< pair<Ponto*, Triangulo*> > intTriangulo;
    for (int i = 0; i < triangulos.size()-1; i +=2) {
        Ponto *p = triangulos[i]->p->IntersecaoRetaPlano(*pP0, pV0);

        if (p) {
            Vetor p1p = biblioteca::SubtracaoPontos(*triangulos[i]->p1->p, *p);
            Vetor p2p = biblioteca::SubtracaoPontos(*triangulos[i]->p2->p, *p);
            Vetor p3p = biblioteca::SubtracaoPontos(*triangulos[i]->p3->p, *p);


            if (ValidacaoPontoCubo(triangulos[i]->p1p2, p1p, triangulos[i]->p1p2, triangulos[i]->p1p3) &&
                ValidacaoPontoCubo(triangulos[i]->p2p3, p2p, triangulos[i]->p1p2, triangulos[i]->p1p3) &&
                ValidacaoPontoCubo(triangulos[i]->p3p1, p3p, triangulos[i]->p1p2, triangulos[i]->p1p3)) {

                intTriangulo.emplace_back(make_pair(p, triangulos[i]));

                normal = triangulos[i]->p->normal;
            } else {
                p1p = biblioteca::SubtracaoPontos(*triangulos[i + 1]->p1->p, *p);
                p2p = biblioteca::SubtracaoPontos(*triangulos[i + 1]->p2->p, *p);
                p3p = biblioteca::SubtracaoPontos(*triangulos[i + 1]->p3->p, *p);

                if (ValidacaoPontoCubo(triangulos[i+1]->p1p2, p1p, triangulos[i+1]->p1p2, triangulos[i+1]->p1p3) &&
                    ValidacaoPontoCubo(triangulos[i+1]->p2p3, p2p, triangulos[i+1]->p1p2, triangulos[i+1]->p1p3) &&
                    ValidacaoPontoCubo(triangulos[i+1]->p3p1, p3p, triangulos[i+1]->p1p2, triangulos[i+1]->p1p3)) {

                    intTriangulo.emplace_back(make_pair(p, triangulos[i + 1]));

                    normal = triangulos[i + 1]->p->normal;
                } else {
                    delete p;
                }
            }
        }
        if(intTriangulo.size() == 2){
            break;
        }
    }


    if(!intTriangulo.empty()) {
        if (intTriangulo.size() >= 2) {
            if (biblioteca::distanciaEntrePontos(pP0, intTriangulo[0].first) <
                biblioteca::distanciaEntrePontos(pP0, intTriangulo[1].first)) {
                normal = intTriangulo[0].second->p->normal;
            }
        }
        else {
            normal = intTriangulo[0].second->p->normal;
        }
    }

    return make_tuple(!intTriangulo.empty() ? intTriangulo[0].first: nullptr, intTriangulo.size() > 1
    ? intTriangulo[1].first: nullptr);

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

Triangulo* Cubo::CriarTriangulo(Vertice *v1, Vertice *v2, Vertice *v3, string id){
    Vetor p1p2 = biblioteca::SubtracaoPontos(*v1->p, *v2->p);
    Vetor p1p3 = biblioteca::SubtracaoPontos(*v1->p, *v3->p);
    return new Triangulo(id, v1, v2, v3, new Plano(v1->p, biblioteca::EncontrarNormal(p1p2, p1p3)));
}

bool Cubo::ValidacaoPontoCubo(const Vetor &PxPy, const Vetor &PxP, const Vetor &P1P2, const Vetor &P1P3) {

    double validacao = biblioteca::ProdutoEscalar(biblioteca::ProdutoVetorial(PxPy, PxP),
        biblioteca::ProdutoVetorial(P1P2, P1P3));

    return validacao > 0;
}

void Cubo::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
    for (auto vertice: vertices) {
        camera->mudarMundoCamera(vertice->p);
    }
    for (auto triangulo: triangulos) {
        triangulo->mudaCoodCamera(camera);
    }
}

void Cubo::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(centro);
    for (auto vertice: vertices) {
        camera->mudarCameraMundo(vertice->p);
    }
    for (auto triangulo: triangulos) {
        triangulo->mudaCoodCamera(camera);
    }

}

Ponto *Cubo::PrimeiraIntersecao(const Ponto &pP0, const Vetor &pVetor0) {
    return nullptr;
}
