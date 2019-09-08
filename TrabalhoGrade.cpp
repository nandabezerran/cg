//
// Created by fbeze on 02/09/2019.
//


//Como compilar: g++ -c TrabalhoGrade.cpp ./biblioteca/*.cpp ./Bitmap/*.cpp && g++ -o principal *.o
//Como executar: ./principal

#include "biblioteca/Cenario.hpp"
#include "biblioteca/biblioteca.hpp"
#include "biblioteca/Objeto.hpp"
#include "biblioteca/Cilindro.hpp"
#include "biblioteca/biblioteca.hpp"
#include "biblioteca/Cone.hpp"
#include "biblioteca/Esfera.hpp"
#include "biblioteca/Cubo.hpp"
#include "biblioteca/PontoIntersecao.hpp"

int main() {
//-------------------------------------------- Criação Objetos -------------------------------------------------------
    VectorXd normal(3);
    normal << 0, 1, 0;
    auto *objeto1 = new Cone(40, 30, biblioteca::CriarPonto(0, -10, -100), normal);
    auto *objeto2 = new Cilindro(50, 10, biblioteca::CriarPonto(0, -60, -100), normal);
    auto *objeto3 = new Cubo(50, biblioteca::CriarPonto(0, -50, -200));
    auto *objeto4 = new Cubo(50, biblioteca::CriarPonto(0, -10, -200));
    auto *objeto5 = new Cubo(50, biblioteca::CriarPonto(0, 40, -200));
    //auto *objeto6 = new Cone(20, 8, biblioteca::CriarPonto(0,0,-10), normal);
    //auto *objeto7 = new Esfera(3, biblioteca::CriarPonto(0,0,-10));

    vector<Objeto *> objetos;

    objetos.push_back(objeto1);
    objetos.push_back(objeto2);
    objetos.push_back(objeto3);
    objetos.push_back(objeto4);
    objetos.push_back(objeto5);
    //objects.push_back(objeto6);
    //objects.push_back(objeto7);

// ------------------------------------- Infos da Grade --------------------------------------------------------------
    int matrixSize = 400;
    float tamGrade = 40;
    float zGrade = -40;

// ------------------------------------- Coordenadas Camera---------------------------------------------------------
    Ponto* pCoordCamera = biblioteca::CriarPonto(0, -100, -400);
    Ponto* pLookAt = biblioteca::CriarPonto(20,0,-100);
    Ponto* pViewUp = biblioteca::CriarPonto(0,-90,-250);

    auto camera =  new Camera(pCoordCamera, pLookAt, pViewUp, tamGrade, zGrade, matrixSize);
    auto cenario = new Cenario(camera, objetos);
// ------------------------------------- Funções ---------------------------------------------------------------------
    //cenario->checarUmPonto(49,49);
    //cenario->objetosVisiveis();
    cenario->imprimirCenarioCompleto();

}