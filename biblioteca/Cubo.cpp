
//
// Created by thais on 26/08/2019.
//

#include "Cubo.hpp"
#include "biblioteca.hpp"
#include "Plano.hpp"

Cubo::Cubo(double cAresta, Ponto* cCentro): aresta(cAresta), centro(cCentro), Objeto("Cubo", PINK, false){
    Ponto* p1 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y + aresta, this->centro->z + aresta/2);
    Ponto* p2 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y + aresta, this->centro->z - aresta/2);
    Ponto* p3 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y + aresta, this->centro->z - aresta/2);
    Ponto* p4 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y + aresta, this->centro->z + aresta/2);
    Ponto* p5 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z + aresta/2);
    Ponto* p6 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z - aresta/2);
    Ponto* p7 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z - aresta/2);
    Ponto* p8 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z + aresta/2);

    vector<Vertice*> vertices;
    Vertice* v1 = this->CriarVertice(p1, "V1");
    Vertice* v2 = this->CriarVertice(p2, "V2");
    Vertice* v3 = this->CriarVertice(p3, "V3");
    Vertice* v4 = this->CriarVertice(p4, "V4");
    Vertice* v5 = this->CriarVertice(p5, "V5");
    Vertice* v6 = this->CriarVertice(p6, "V6");
    Vertice* v7 = this->CriarVertice(p7, "V7");
    Vertice* v8 = this->CriarVertice(p8, "V8");

    vertices.push_back(v1);
    vertices.push_back(v2);
    vertices.push_back(v3);
    vertices.push_back(v4);
    vertices.push_back(v5);
    vertices.push_back(v6);
    vertices.push_back(v7);
    vertices.push_back(v8);

    this->vertices = vertices;

    Face* f1 = this->CriarFace(vertices[0], vertices[3], vertices[2], "F1");
    Face* f2 = this->CriarFace(vertices[2], vertices[1], vertices[0], "F2");
    Face* f3 = this->CriarFace(vertices[6], vertices[5], vertices[2], "F3");
    Face* f4 = this->CriarFace(vertices[5], vertices[1], vertices[2], "F4");
    Face* f5 = this->CriarFace(vertices[7], vertices[6], vertices[3], "F5");
    Face* f6 = this->CriarFace(vertices[6], vertices[2], vertices[3], "F6");
    Face* f7 = this->CriarFace(vertices[4], vertices[7], vertices[3], "F7");
    Face* f8 = this->CriarFace(vertices[3], vertices[0], vertices[4], "F8");
    Face* f9 = this->CriarFace(vertices[6], vertices[7], vertices[4], "F9");
    Face* f10 = this->CriarFace(vertices[4], vertices[5], vertices[6], "F10");
    Face* f11 = this->CriarFace(vertices[0], vertices[4], vertices[5], "F11");
    Face* f12 = this->CriarFace(vertices[5], vertices[1], vertices[0], "F12");

    vector<Face*> faces;
    faces.push_back(f1);
    faces.push_back(f2);
    faces.push_back(f3);
    faces.push_back(f4);
    faces.push_back(f5);
    faces.push_back(f6);
    faces.push_back(f7);
    faces.push_back(f8);
    faces.push_back(f9);
    faces.push_back(f10);
    faces.push_back(f11);
    faces.push_back(f12);

    this->faces = faces;
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

bool Cubo::ValidacaoPontoCubo(VectorXd PxPy, VectorXd PxP, VectorXd P1P2, VectorXd P1P3, int tamanho) {

     VectorXd val1 = biblioteca::ProdutoVetorial(PxPy, PxP, tamanho);
     VectorXd val2 = biblioteca::ProdutoVetorial(P1P2, P1P3, tamanho);
     double validacao = biblioteca::ProdutoEscalar(val1,val2,tamanho);

     return validacao > 0;

}

