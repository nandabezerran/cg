//
// Created by thais on 26/08/2019.
//



#include "Cubo.hpp"
#include "biblioteca.hpp"
#include "Plano.hpp"

Cubo::Cubo(double cAresta, Ponto* cCentro, VectorXd cNormal): normal(cNormal), aresta(cAresta), centro(cCentro), Objeto("Cubo"){
    Ponto* p1 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z + aresta/2);
    Ponto* p2 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z - aresta/2);
    Ponto* p3 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y + aresta, this->centro->z - aresta/2);
    Ponto* p4 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y + aresta, this->centro->z + aresta/2);
    Ponto* p5 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z + aresta/2);
    Ponto* p6 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z - aresta/2);
    Ponto* p7 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y + aresta, this->centro->z - aresta/2);
    Ponto* p8 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y + aresta, this->centro->z + aresta/2);



}

// tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, VectorXd pVetor0, int pTamanho) {
    // vector<Ponto*> v_aux;
    // for(int i = 0; i<6; i++){
    //     Ponto* p = this->planos[i]->IntersecaoRetaPlano(pP0, pVetor0, pTamanho);
    //     if (p) {
    //         v_aux.push_back(p);
    //     }
    // }

    // if(v_aux.size() == 2){
    //     return make_tuple(v_aux[0], v_aux[1]);
    // }

    // if(v_aux.size() == 1){
    //     return make_tuple(v_aux[0], nullptr);
    // }

    // if(v_aux.size() == 0){
    //     return make_tuple(nullptr, nullptr);
    // }
//}


