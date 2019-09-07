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
#include <GL/glut.h>
#include <time.h>
#include <chrono>

float* test;
int matrixSize = 100;
Cenario *cenario;
void display(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(matrixSize,matrixSize,GL_RGB,GL_FLOAT,test);
    glutSwapBuffers();
}

void onMouseButton(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        cenario->checarUmPonto(matrixSize-y,x);
    }
}

void onKeyboard(unsigned char key, int x, int y){
    if(key == 'w'){
        cenario->camera->coordCamera->z -= 10;
        cenario->mudarCamera(cenario->camera);
        cenario->imprimirCenarioCompleto();
        cout << cenario->camera->coordCamera->z << endl;
    }
    if(key == 's'){
        cenario->camera->coordCamera->z += 10;
        cenario->mudarCamera(cenario->camera);
        cenario->imprimirCenarioCompleto();
        cout << cenario->camera->coordCamera->z << endl;
    }
    glutSwapBuffers();
}

int main(int argc, char** argv) {
//-------------------------------------------- Criação Objetos -------------------------------------------------------
    VectorXd normal(3);
    normal << 0, 1, 0;
    auto *objeto1 = new Cone(4, 3, biblioteca::CriarPonto(0, -1, -10), normal);
    auto *objeto2 = new Cilindro(5, 1, biblioteca::CriarPonto(0, -6, -10), normal);
    auto *objeto3 = new Cubo(5, biblioteca::CriarPonto(0, -5, -20));
    auto *objeto4 = new Cubo(5, biblioteca::CriarPonto(0, -1, -20));
    auto *objeto5 = new Cubo(5, biblioteca::CriarPonto(0, 4, -20));
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
    float tamGrade = 4;
    float zGrade = -4;

// ------------------------------------- Coordenadas Camera ----------------------------------------------------------
    Ponto* pCoordCamera = biblioteca::CriarPonto(20, 0, -10);
    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-20);
    Ponto* pViewUp = biblioteca::CriarPonto(20,1,-10);

    auto camera =  new Camera(pCoordCamera, pLookAt, pViewUp, tamGrade, zGrade, matrixSize);
    cenario = new Cenario(camera, objetos);

// ------------------------------------- Funções ---------------------------------------------------------------------
    //cenario->checarUmPonto(49,49);
    //cenario->objetosVisiveis();
    srand((unsigned)clock());
    auto start = std::chrono::high_resolution_clock::now(); // Starts the clock;
    cenario->imprimirCenarioCompleto();
    auto stop = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);
    std::cout << "Time taken by ImprimirCenarioCompleto algorithm: "
              << duration.count() << " microseconds\n" << std::endl;

// ------------------------------------- Janela ----------------------------------------------------------------------
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowSize(matrixSize, matrixSize);
    glutInitWindowPosition((1366/2)-matrixSize/2, (768/2)-(matrixSize+50)/2);
    glutCreateWindow("Trabalhim Top");
    test = cenario->getCenarioData();
    glutDisplayFunc(display);
    //glutMouseFunc(onMouseButton);
    glutKeyboardFunc(onKeyboard);
    glutMainLoop();
    return 0;
}