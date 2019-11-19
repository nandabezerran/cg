
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
//    cout << " "<< p2->x <<" " << p2->y << " "<< p2->z;
//    cout << " "<< p6->x <<" " << p6->y << " "<< p6->z;
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

            if (triangulos[i]->ValidacaoPontoTriangulo(p1p,p2p,p3p)) {
                intTriangulo.emplace_back(make_pair(p, triangulos[i]));
                normal = triangulos[i]->p->normal;

            } else {
                p1p = biblioteca::SubtracaoPontos(*triangulos[i + 1]->p1->p, *p);
                p2p = biblioteca::SubtracaoPontos(*triangulos[i + 1]->p2->p, *p);
                p3p = biblioteca::SubtracaoPontos(*triangulos[i + 1]->p3->p, *p);

                if (triangulos[i+1]->ValidacaoPontoTriangulo(p1p,p2p,p3p)) {
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
            else {
                normal = intTriangulo[1].second->p->normal;
            }
        }
        else {
            normal = intTriangulo[0].second->p->normal;
        }
    }

    return make_tuple(!intTriangulo.empty() ? intTriangulo[0].first: nullptr, intTriangulo.size() > 1
    ? intTriangulo[1].first: nullptr);

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
        triangulo->mudaCoodMundo(camera);
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

Objeto* Cubo::aplicarEspelhamento(vector<Matriz> &pMatrizesTransf){
    Matriz centroAux = Matriz(4,1,0);
    centroAux(0,0) = centro->x;
    centroAux(1,0) = centro->y;
    centroAux(2,0) = centro->z;
    centroAux(3,0) = 1;
    for (auto &matriz : pMatrizesTransf) {
        centroAux = matriz * centroAux;
    }

    return new Cubo(aresta, new Ponto{centroAux(0,0), centroAux(1,0), centroAux(2,0)},
                        material);
}

Ponto *Cubo::getCentro() {
    return centro;
}

void Cubo::aplicarTransformacao(vector<Matriz> &pMatrizesTransf) {
    for(auto triangulo :triangulos){
        triangulo->aplicarTransformacao(pMatrizesTransf);
    }
    Matriz aux = Matriz(4,1,0);
    for (auto vertice: vertices) {
        aux(0,0) = vertice->p->x;
        aux(1,0) = vertice->p->y;
        aux(2,0) = vertice->p->z;
        aux(3,0) = 1;
        for (auto matriz: pMatrizesTransf) {
            aux = matriz * aux;
        }
        vertice->p->x = aux(0,0);
        vertice->p->y = aux(1,0);
        vertice->p->z = aux(2,0);

    }
    aux(0,0) = normal.x;
    aux(1,0) = normal.y;
    aux(2,0) = normal.z;
    aux(3,0) = 0;
    for (auto matriz: pMatrizesTransf) {
        aux = matriz * aux;
    }
    normal.x = aux(0,0);
    normal.y = aux(1,0);
    normal.z = aux(2,0);
}
