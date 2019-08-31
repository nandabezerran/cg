
//
// Created by thais on 26/08/2019.
//

#include "Cubo.hpp"
#include "biblioteca.hpp"
#include "Plano.hpp"

Cubo::Cubo(double cAresta, Ponto* cCentro): aresta(cAresta), centro(cCentro), Objeto("Cubo"){
    Ponto* p1 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y + aresta, this->centro->z + aresta/2);
    Ponto* p2 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y + aresta, this->centro->z - aresta/2);
    Ponto* p3 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y + aresta, this->centro->z - aresta/2);
    Ponto* p4 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y + aresta, this->centro->z + aresta/2);
    Ponto* p5 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z + aresta/2);
    Ponto* p6 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z - aresta/2);
    Ponto* p7 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z - aresta/2);
    Ponto* p8 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z + aresta/2);
    int cont = 1;
    vector<Vertice*> vertices;
    for(int i = 0; i<8; i++){
        Vertice* v = this->CriarVertice(p1, "V" + cont);
        vertices.push_back(v);
        cont++;
    }
    this->vertices = vertices;

    Face* f1 = this->CriarFace(vertices[0], vertices[3], vertices[1], "F1");
    Face* f2 = this->CriarFace(vertices[3], vertices[2], vertices[1], "F2");
    Face* f3 = this->CriarFace(vertices[6], vertices[5], vertices[3], "F3");
    Face* f4 = this->CriarFace(vertices[5], vertices[2], vertices[3], "F4");
    Face* f5 = this->CriarFace(vertices[7], vertices[6], vertices[0], "F5");
    Face* f6 = this->CriarFace(vertices[6], vertices[3], vertices[0], "F6");
    Face* f7 = this->CriarFace(vertices[7], vertices[0], vertices[4], "F7");
    Face* f8 = this->CriarFace(vertices[0], vertices[1], vertices[4], "F8");
    Face* f9 = this->CriarFace(vertices[6], vertices[7], vertices[4], "F9");
    Face* f10 = this->CriarFace(vertices[5], vertices[6], vertices[4], "F10");
    Face* f11 = this->CriarFace(vertices[4], vertices[2], vertices[5], "F11");
    Face* f12 = this->CriarFace(vertices[4], vertices[1], vertices[2], "F12");

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
    for(int i=0; i<12; i++){
        VectorXd p1p2 = biblioteca::SubtracaoPontos(this->faces[i]->p2->p, this->faces[i]->p1->p, 3);
        VectorXd p1p3 = biblioteca::SubtracaoPontos(this->faces[i]->p3->p, this->faces[i]->p1->p, 3);
        Plano* p = new Plano(this->faces[i]->p1->p, biblioteca::EncontrarNormal(p1p2, p1p3, 3));
        faces[i]->p = p;
    }

    vector<Ponto*> v;


    for(int i=0; i<12; i++){
        Ponto* p = faces[i]->p->IntersecaoRetaPlano(pP0, pVetor0, pTamanho);
        if(p){
            v.push_back(p);
        }
    }

    if (v.size() == 0) {
        return make_tuple(nullptr, nullptr);
    }

    if(v.size() == 1) {
        for(int i=0; i<12; i++) {

            VectorXd p1p = biblioteca::SubtracaoPontos(this->faces[i]->p1->p, v[0], 3);
            VectorXd p2p = biblioteca::SubtracaoPontos(this->faces[i]->p2->p, v[0], 3);
            VectorXd p3p = biblioteca::SubtracaoPontos(this->faces[i]->p3->p, v[0], 3);
            VectorXd p2p3 = biblioteca::SubtracaoPontos(this->faces[i]->p2->p, this->faces[i]->p3->p, 3);
            VectorXd p3p1 = biblioteca::SubtracaoPontos(this->faces[i]->p3->p, this->faces[i]->p1->p, 3);
            VectorXd p1p2 = biblioteca::SubtracaoPontos(this->faces[i]->p1->p, this->faces[i]->p2->p, 3);
            VectorXd p1p3 = biblioteca::SubtracaoPontos(this->faces[i]->p1->p, this->faces[i]->p3->p, 3);


            bool validacao1 = ValidacaoPontoCubo(p1p2, p1p, p1p2, p1p3, 3);
            bool validacao2 = ValidacaoPontoCubo(p2p3, p2p, p1p2, p1p3, 3);
            bool validacao3 = ValidacaoPontoCubo(p3p1, p3p, p1p2, p1p3, 3);

            if(validacao1 == true && validacao2 == true && validacao3 == true) {
                return make_tuple(v[0], nullptr);
            }
        } 

        return make_tuple(nullptr, nullptr);     
    }

    else {

    
    }

}

Vertice* Cubo::CriarVertice(Ponto* ponto, string identificador){
    Vertice* v = new Vertice;
    v->p->x = ponto->x;
    v->p->y = ponto->y;
    v->p->z = ponto->z;
    v->id = identificador;
    return v;
}

Aresta* Cubo::CriarAresta(Vertice *pi, Vertice *pf, string id) {
    Aresta* newAresta = new Aresta;
    newAresta->id = id;
    newAresta->verticeFinal = pf;
    newAresta->verticeInicial = pi;
    return newAresta;
}
Face* Cubo::CriarFace(Vertice* v1, Vertice* v2, Vertice* v3, string id){
    Face* newFace = new Face;
    newFace->p1 = v1;
    newFace->p2 = v2;
    newFace->p3 = v3;
    newFace->id = id;
}

bool Cubo::ValidacaoPontoCubo(VectorXd PxPy, VectorXd PxP, VectorXd P1P2, VectorXd P1P3, int tamanho) {

     VectorXd val1 = biblioteca::ProdutoVetorial(PxPy, PxP, tamanho);
     VectorXd val2 = biblioteca::ProdutoVetorial(P1P2, P1P3, tamanho);
     double validacao = biblioteca::ProdutoEscalar(val1,val2,tamanho);

     if(validacao > 0) {
        return true;
     }

     else {
        return false;
     }
}

