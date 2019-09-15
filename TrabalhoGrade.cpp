//
// Created by fbeze on 02/09/2019.
//


//Como compilar: g++ -c TrabalhoGrade.cpp ./biblioteca/*.cpp ./Bitmap/*.cpp && g++ -o principal *.o
//Como executar: ./principal

#include "biblioteca/Cenario.hpp"
#include "biblioteca/biblioteca.hpp"
#include "biblioteca/Objeto.hpp"
#include "biblioteca/Cilindro.hpp"
#include "biblioteca/Cone.hpp"
#include "biblioteca/Esfera.hpp"
#include "biblioteca/Cubo.hpp"
#include "biblioteca/Material.hpp"
#include "biblioteca/Luz.hpp"
#include "biblioteca/LuzAmbiente.hpp"
#include "biblioteca/LuzPontual.hpp"
#include "biblioteca/LuzSpot.hpp"
#include <GL/glut.h>
#include <time.h>
#include <chrono>

float* test;
int matrixSize = 200;
Cenario *cenario;

void display(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(matrixSize,matrixSize,GL_RGB,GL_FLOAT,test);
    glutSwapBuffers();
    glutPostRedisplay();
}

void onMouseButton(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        cenario->checarUmPonto(matrixSize-y,x);
    }
}

void onKeyboard(unsigned char key, int x, int y){
    if(key == 27){
        glutDestroyWindow(0);
        exit(0);
    }
    else if(key == 'w'){
        cenario->camera->andarFrente();
        cenario->atualizarCamera();
    }
    else if(key == 's'){
        cenario->camera->andarTras();
        cenario->atualizarCamera();
    }
}

int main(int argc, char** argv) {
//-------------------------------------------- Materiais -------------------------------------------------------------
    //Verde
    float ka0[3] ={0.0215, 0.1745, 0.0215};
    float kd0[3] ={0.07568, 0.61424, 0.07568};
    float ks0[3] ={0.633, 0.727811, 0.633};
    double m0 =  12.8;
    auto *material0 = new Material(ka0,kd0,ks0, m0);
    //Polished copper
    float ka1[3] ={0.19125, 0.0735, 0.0225};
    float kd1[3] ={0.7038, 0.27048, 0.0828};
    float ks1[3] ={0.256777, 0.137622, 0.086014};
    double m1 =  12.8;

    auto *material1 = new Material(ka1,kd1, ks1, m1);
    //Chrome
    float ka2[3] ={0.25, 0.25, 0.25};
    float kd2[3] ={0.4, 0.4, 0.4};
    float ks2[3] ={0.774597, 0.774597, 0.774597};
    double m2 = 12.8;
    auto *material2 = new Material(ka2,kd2, ks2, m2);
//-------------------------------------------- Luzes -----------------------------------------------------------------
    auto *luzAmbiente = new LuzAmbiente(0.3,0.3,0.3);
    auto *luzPontual = new LuzPontual(0.7,0.7,0.7,5, 5, 0);
    Vetor dir(1, 0.003, 0);
    auto *luzSpot = new LuzSpot(1.0,1.0,1.0,5, -1, -20, dir, 10);
    vector<Luz *> luzes;
    luzes.emplace_back(luzSpot);
    luzes.emplace_back(luzPontual);
//-------------------------------------------- Criação Objetos -------------------------------------------------------
    Vetor normal(0, 1, 0);
    auto *objeto1 = new Cone(4, 3, biblioteca::CriarPonto(0, -1, -10), normal, material0);
    auto *objeto2 = new Cilindro(5, 1, Ponto{0, -6, -10}, normal, material1);
    auto *objeto3 = new Cubo(5, biblioteca::CriarPonto(0, -5, -20), material2);
    auto *objeto4 = new Cubo(5, biblioteca::CriarPonto(0, -1, -20), material2);
    auto *objeto5 = new Cubo(5, biblioteca::CriarPonto(0, 4, -20), material2);
    //auto *objeto6 = new Cone(20, 8, biblioteca::CriarPonto(0,0,-10), normal);
    //auto *objeto7 = new Esfera(10, biblioteca::CriarPonto(0,-1,-30), material0);

    vector<Objeto *> objetos;

    objetos.push_back(objeto1);
    objetos.push_back(objeto2);
    objetos.push_back(objeto3);
    objetos.push_back(objeto4);
    objetos.push_back(objeto5);
    //objects.push_back(objeto6);
//    objetos.push_back(objeto7);

// ------------------------------------- Infos da Grade --------------------------------------------------------------
    float tamGrade = 4;
    float zGrade = -4;

// ------------------------------------- Coordenadas Camera ----------------------------------------------------------
//Cima
//    Ponto* pCoordCamera = biblioteca::CriarPonto(0, 20, -15);
//    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-15);
//    Ponto* pViewUp = biblioteca::CriarPonto(0,20,-17);
//Lado
//    Ponto* pCoordCamera = biblioteca::CriarPonto(20, 0, -5);
//    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-15);
//    Ponto* pViewUp = biblioteca::CriarPonto(20,1,-5);
//Frente Inclinado
    Ponto* pCoordCamera = biblioteca::CriarPonto(0, 0, 10);
    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-10);
    Ponto* pViewUp = biblioteca::CriarPonto(0,1,0);

    auto camera =  new Camera(pCoordCamera, pLookAt, pViewUp, tamGrade, zGrade, matrixSize);
    cenario = new Cenario(camera, objetos, luzAmbiente, luzes);

// ------------------------------------- Funções ---------------------------------------------------------------------
    srand((unsigned)clock());
    auto start = std::chrono::high_resolution_clock::now(); // Starts the clock;
    cenario->imprimirCenarioCompleto();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by ImprimirCenarioCompleto algorithm: "
              << duration.count() / 1000000.0 << " seconds\n" << std::endl;

// ------------------------------------- Janela ----------------------------------------------------------------------
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(matrixSize, matrixSize);
    glutInitWindowPosition((1366/2)-matrixSize/2, (768/2)-(matrixSize+50)/2);
    glutCreateWindow("Trabalhim Top");

    test = cenario->getCenarioData();
    glutDisplayFunc(display);
    glutMouseFunc(onMouseButton);
    glutKeyboardFunc(onKeyboard);

    glutMainLoop();
    return 0;
}