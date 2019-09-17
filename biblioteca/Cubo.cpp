
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

    faces.push_back(CriarFace(triangulos[0], triangulos[1]));
    faces.push_back(CriarFace(triangulos[2], triangulos[3]));
    faces.push_back(CriarFace(triangulos[4], triangulos[5]));
    faces.push_back(CriarFace(triangulos[6], triangulos[7]));
    faces.push_back(CriarFace(triangulos[8], triangulos[9]));
    faces.push_back(CriarFace(triangulos[10], triangulos[11]));


}

Vetor Cubo::calcularNormal(Ponto* p){
    return normal;
}

tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, const Vetor &pV0) {
    Ponto *p;
    for(auto face: faces){
        if(face->t1->p1 == vMaisProx || face->t1->p2 == vMaisProx ||
           face->t1->p3 == vMaisProx || face->t2->p1 == vMaisProx ||
           face->t2->p2 == vMaisProx || face->t2->p3 == vMaisProx ){
            p = face->t1->intersecaoReta(pP0, pV0);
            if (p) {
                normal = face->t1->p->normal;
                return make_pair(p, nullptr);
            }
            else{
                p = face->t2->intersecaoReta(pP0, pV0);
                if(p){
                    normal = face->t2->p->normal;
                    return make_pair(p, nullptr);

                }
                else{
                    delete p;
                }
            }
        }
    }

    return make_tuple(nullptr, nullptr);

}


Vertice* Cubo::CriarVertice(Ponto* ponto, const string& identificador){
    auto v = new Vertice();
    v->p = ponto;
    v->id = identificador;
    return v;
}

Aresta* Cubo::CriarAresta(Vertice *pi, Vertice *pf, const string& id) {
    auto newAresta = new Aresta;
    newAresta->id = id;
    newAresta->verticeFinal = pf;
    newAresta->verticeInicial = pi;
    return newAresta;
}

Triangulo* Cubo::CriarTriangulo(Vertice *v1, Vertice *v2, Vertice *v3, const string& id){
    Vetor p1p2 = biblioteca::SubtracaoPontos(*v1->p, *v2->p);
    Vetor p1p3 = biblioteca::SubtracaoPontos(*v1->p, *v3->p);
    return new Triangulo(id, v1, v2, v3, new Plano(v1->p, biblioteca::EncontrarNormal(p1p2, p1p3)));
}

void Cubo::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
    for (auto vertice: vertices) {
        camera->mudarMundoCamera(vertice->p);
    }
    for (auto triangulo: triangulos) {
        triangulo->mudaCoodCamera(camera);
    }

    vMaisProxObs();
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

void Cubo::vMaisProxObs() {
    double distancia;
    double aux;
    distancia = biblioteca::distanciaEntrePontos(Ponto{0,0,0}, *vertices[0]->p);
    vMaisProx = vertices[0];
    for(auto vertice : vertices){
        aux = biblioteca::distanciaEntrePontos(Ponto{0,0,0}, *vertice->p);
        if(aux < distancia){
            vMaisProx = vertice;
            distancia = aux;
        }
    }
}

Face *Cubo::CriarFace(Triangulo *pT1, Triangulo *pT2) {
    auto f = new Face();
    f->t1 = pT1;
    f->t2 = pT2;
    return f;

}
