//
// Created by fbeze on 02/09/2019.
//
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

    Vector3d normal;
    normal << 0, 1, 0;
    auto *objeto1 = new Cone(4, 3, biblioteca::CriarPonto(0, -1, -10), normal);
    auto *objeto2 = new Cilindro(5, 1, biblioteca::CriarPonto(0, -6, -10), normal);
    auto *objeto3 = new Cubo(5, biblioteca::CriarPonto(0, -5, -20));
    auto *objeto4 = new Cubo(5, biblioteca::CriarPonto(0, 0, -20));
    auto *objeto5 = new Cubo(5, biblioteca::CriarPonto(0, 5, -20));
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

// ------------------------------------- Infos da Grade ----------------------------------------------------------
    int matrixSize = 100;
    float tamGrade = 4;
    float zGrade = -4;
// ------------------------------------- Coordenadas Camera ------------------------------------------------------
    Ponto* pCoordCamera = biblioteca::CriarPonto(10,2,0);
    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-10);
    Ponto* pViewUp = biblioteca::CriarPonto(10,3,0);

    auto camera =  new Camera(pCoordCamera, pLookAt, pViewUp, tamGrade, zGrade, matrixSize);
    auto cenario = new Cenario(camera, objetos);
    VectorXd aux(3);
    vector<PontoIntersecao*> pInts;
    // colocar dentro do cenario imprimir completo
    for (int i = 0; i < matrixSize ; ++i) {
        for (int j = 0; j < matrixSize; ++j) {
            pInts = cenario->rayCasting(pCoordCamera, camera->gradeCamera[j][i]);
            if(!pInts.empty()){
                pInts[0]->objeto->visibilidade = true;

            }
        }
    }
    cenario->pintarObjeto(camera->gradeCamera);
    cenario->salvarCenario();

}