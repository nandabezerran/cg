//
// Created by thais on 26/08/2019.
//

#include "Cubo.hpp"
#include "biblioteca.hpp"
#include "Plano.hpp"

Cubo::Cubo(VectorXd cNormal, double cAresta, Ponto* cCentro): normal(cNormal), aresta(cAresta), centro(cCentro), Objeto("Cubo"){
    Ponto* p1 = biblioteca::CriarPonto(this->centro->x + aresta/2, this->centro->y, this->centro->z);
    Ponto* p2 = biblioteca::CriarPonto(this->centro->x - aresta/2, this->centro->y, this->centro->z);
    Ponto* p3 = biblioteca::CriarPonto(this->centro->x, this->centro->y + aresta/2, this->centro->z);
    Ponto* p4 = biblioteca::CriarPonto(this->centro->x, this->centro->y - aresta/2, this->centro->z);
    Ponto* p5 = biblioteca::CriarPonto(this->centro->x, this->centro->y, this->centro->z + aresta/2);
    Ponto* p6 = biblioteca::CriarPonto(this->centro->x, this->centro->y, this->centro->z - aresta/2);

    Plano* plano1 = new Plano(p1, this->normal);
    Plano* plano2 = new Plano(p2, this->normal);
    Plano* plano3 = new Plano(p3, this->normal);
    Plano* plano4 = new Plano(p4, this->normal);
    Plano* plano5 = new Plano(p5, this->normal);
    Plano* plano6 = new Plano(p6, this->normal);

    this->planos.push_back(plano1);
    this->planos.push_back(plano2);
    this->planos.push_back(plano3);
    this->planos.push_back(plano4);
    this->planos.push_back(plano5);
    this->planos.push_back(plano6);
}

tuple<Ponto*,Ponto*> Cubo::IntersecaoReta(Ponto *pP0, VectorXd pVetor0, int pTamanho) {
    vector<Ponto*> v_aux;
    for(int i = 0; i<6; i++){
        Ponto* p = this->planos[i]->IntersecaoRetaPlano(pP0, pVetor0, pTamanho);
        if (p) {
            v_aux.push_back(p);
        }
    }

    if(v_aux.size() == 2){
        return make_tuple(v_aux[0], v_aux[1]);
    }

    if(v_aux.size() == 1){
        return make_tuple(v_aux[0], nullptr);
    }

    if(v_aux.size() == 0){
        return make_tuple(nullptr, nullptr);
    }
}


