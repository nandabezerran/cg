
//
// Created by thais on 26/08/2019.
//

#include "Cubo.hpp"
#include "biblioteca.hpp"
#include "Plano.hpp"

Cubo::Cubo(double cAresta, Ponto* cCentro): aresta(cAresta), centro(cCentro), Objeto("Cubo", 128,128,128 , false){
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
    faces.push_back(CriarFace(vertices[0], vertices[4], vertices[5], "F11"));
    faces.push_back(CriarFace(vertices[5], vertices[1], vertices[0], "F12"));


    for (auto face: faces) {
        VectorXd p1p2 = biblioteca::SubtracaoPontos(face->p1->p, face->p2->p, 3);
        VectorXd p1p3 = biblioteca::SubtracaoPontos(face->p1->p, face->p3->p, 3);
        Plano *p = new Plano(face->p1->p, biblioteca::EncontrarNormal(p1p2, p1p3, 3));
        face->p = p;
    }

}

tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, VectorXd pVetor0, int pTamanho) {

    vector<Ponto*> intFace;

    for (auto face: faces) {
        Ponto *p = face->p->IntersecaoRetaPlano(pP0, pVetor0, pTamanho);

        if (p) {
            VectorXd p1p = biblioteca::SubtracaoPontos(face->p1->p, p, 3);
            VectorXd p2p = biblioteca::SubtracaoPontos(face->p2->p, p, 3);
            VectorXd p3p = biblioteca::SubtracaoPontos(face->p3->p, p, 3);
            VectorXd p2p3 = biblioteca::SubtracaoPontos(face->p2->p, face->p3->p, 3);
            VectorXd p3p1 = biblioteca::SubtracaoPontos(face->p3->p, face->p1->p, 3);
            VectorXd p1p2 = biblioteca::SubtracaoPontos(face->p1->p, face->p2->p, 3);
            VectorXd p1p3 = biblioteca::SubtracaoPontos(face->p1->p, face->p3->p, 3);

            if(ValidacaoPontoCubo(p1p2, p1p, p1p2, p1p3, 3) && ValidacaoPontoCubo(p2p3, p2p, p1p2, p1p3, 3) &&
               ValidacaoPontoCubo(p3p1, p3p, p1p2, p1p3, 3)){
                intFace.emplace_back(p);
            }
            else{
                delete p;
            }
        }
    }
    if(intFace.size() > 2){
        cout << "Mais que 3 intersecoes" << endl;
    }

    return make_tuple(intFace.size() > 0 ? intFace[0]: nullptr, intFace.size() > 1 ? intFace[1]: nullptr);

}

//tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, VectorXd pVetor0, int pTamanho) {
//
//    vector<Ponto*> intFace;
//
//    for (auto face: faces) {
//        Ponto *p = face->p->IntersecaoRetaPlano(pP0, pVetor0, pTamanho);
//
//        if (p) {
//            if(ValidacaoPontoCubo(face, p)){
//                intFace.emplace_back(p);
//            }
//            else{
//                delete p;
//            }
//        }
//    }
//    if(intFace.size() > 2){
//        cout << "Mais que 3 intersecoes" << endl;
//    }
//
//    return make_tuple(intFace.size() > 0 ? intFace[0]: nullptr, intFace.size() > 1 ? intFace[1]: nullptr);
//
//}

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

//bool Cubo::ValidacaoPontoCubo(Face *face, Ponto *p) {
//
//    VectorXd auxVec1 = biblioteca::SubtracaoPontos(face->p2->p, face->p1->p, 3);
//    VectorXd auxVec2 = biblioteca::SubtracaoPontos(face->p3->p, face->p1->p, 3);
//    VectorXd pv = biblioteca::ProdutoVetorial(auxVec1, auxVec2, 3);
//
//    double areaTotal = (sqrt(biblioteca::ProdutoEscalar(pv,pv,3)))/2;
//
//    VectorXd w1 = biblioteca::SubtracaoPontos(face->p1->p, p, 3);
//    VectorXd w2 = biblioteca::SubtracaoPontos(face->p2->p, p, 3);
//    VectorXd w3 = biblioteca::SubtracaoPontos(face->p3->p, p, 3);
//
//
//    pv =  biblioteca::ProdutoVetorial(w1, w2, 3);
//    double area1 = (sqrt(biblioteca::ProdutoEscalar(pv,pv,3)))/2;
//
//    pv =  biblioteca::ProdutoVetorial(w3, w1, 3);
//    double area2 = (sqrt(biblioteca::ProdutoEscalar(pv,pv,3)))/2;
//
//    pv =  biblioteca::ProdutoVetorial(w2, w3, 3);
//    double area3 =  (sqrt(biblioteca::ProdutoEscalar(pv,pv,3)))/2;
//
//    return abs(areaTotal - (area1 + area2 + area3)) < 0.000000005;
//
//}
bool Cubo::ValidacaoPontoCubo(VectorXd PxPy, VectorXd PxP, VectorXd P1P2, VectorXd P1P3, int tamanho) {

    VectorXd val1 = biblioteca::ProdutoVetorial(PxPy, PxP, tamanho);
    VectorXd val2 = biblioteca::ProdutoVetorial(P1P2, P1P3, tamanho);
    double validacao = biblioteca::ProdutoEscalar(val1,val2,tamanho);

    return validacao > 0;

}


void Cubo::mudaCoodCamera(Camera *camera) {
    camera->mudarMundoCamera(centro);
    for (auto vertice: vertices) {
        camera->mudarMundoCamera(vertice->p);
    }
    for (auto face: faces) {
        camera->mudarMundoCamera(face->p->normal);
    }
}

void Cubo::mudaCoodMundo(Camera *camera) {
    camera->mudarCameraMundo(centro);
    for (auto face: faces) {
        camera->mudarCameraMundo(face->p1->p);
        camera->mudarCameraMundo(face->p2->p);
        camera->mudarCameraMundo(face->p3->p);
        camera->mudarCameraMundo(face->p->normal);
        camera->mudarCameraMundo(face->p->p_pi);
    }
}