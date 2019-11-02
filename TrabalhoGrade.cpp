//
// Created by fbeze on 02/09/2019.
//


//Como compilar: g++ -c TrabalhoGrade.cpp ./biblioteca/*.cpp ./Bitmap/*.cpp && g++ -o principal *.o
//Como executar: ./principal
#include "biblioteca/Matriz.hpp"
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

# define M_PI 3.14159265358979323846
float* test;
Camera* camera1;
int matrixSize = 500;
Cenario *cenario;
Objeto* obj;
PontoIntersecao* pontos[3];
int menuPrincipal;
int subMenu;
int linha;
int coluna;

void display(){
    glClearColor(0.0,0.0,0.0,1.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glDrawPixels(matrixSize,matrixSize,GL_RGB,GL_FLOAT,test);
    glutSwapBuffers();
    glutPostRedisplay();
}
void funcaoMenu(int item){
    switch(item){
        case 1:
            cenario->gerarEspelho(linha,coluna);
            break;
        case 2:
            cenario->rotacaoPlanoArbitrario(pontos[0]->objeto,M_PI/3,pontos[1]->p, pontos[2]->p);
    }
    cenario->imprimirCenarioCompleto();

}
void onMouseButton(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        pontos[0] = cenario->checarUmPonto(matrixSize - y, x);
        if (pontos[0]) {
            subMenu = glutCreateMenu(funcaoMenu);
            glutAddMenuEntry("Gerar espelho", 1);
            if (pontos[1] && pontos[2]) {
                glutAddMenuEntry("Rotacionar", 2);
            }
            menuPrincipal = glutCreateMenu(funcaoMenu);
            glutAddSubMenu(pontos[0]->objeto->nome.c_str(), subMenu);
            glutAttachMenu(GLUT_MIDDLE_BUTTON);
            linha = matrixSize-y;
            coluna = x;
        }
        cenario->imprimirCenarioCompleto();
    }
    if (button == GLUT_RIGHT_BUTTON) {
        if (state == GLUT_DOWN) {
            if (cenario->checarUmPonto(matrixSize - y, x)) {
                pontos[1] = cenario->checarUmPonto(matrixSize - y, x);
            }
        } else if (state == GLUT_UP) {
            if (cenario->checarUmPonto(matrixSize - y, x)) {
                pontos[2] = cenario->checarUmPonto(matrixSize - y, x);
            }
        }
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
    //Pearl
    float ka3[3] ={ 1,1,1};
    float kd3[3] ={1.0, 0.829, 0.829};
    float ks3[3] ={0.296648, 0.296648, 0.296648};
    double m3 = 11.264;
    auto *material3 = new Material(ka3,kd3, ks3, m3);
    //Orange 255,140,0
    float ka4[3] ={1, 0.2735, 0.9};
    float kd4[3] ={1, 0.257048, 0.9};
    float ks4[3] ={1, 0.2537622, 0.9};
    double m4 = 11.264;
    auto *material4 = new Material(ka4,kd4, ks4, m4);

//-------------------------------------------- Luzes -----------------------------------------------------------------
    auto *luzAmbiente = new LuzAmbiente(0.3,0.3,0.3);
    auto *luzPontual = new LuzPontual(0.7,0.7,0.7,0, 7, -9);
    Vetor dir(1, 0.003, 0);
    //auto *luzSpot = new LuzSpot(1.0,1.0,1.0,5, -1, -20, dir, 10);
    vector<Luz *> luzes;
    //luzes.emplace_back(luzSpot);
    luzes.emplace_back(luzPontual);
//-------------------------------------------- Criação Objetos -------------------------------------------------------
    Vetor normal(0, 1, 0);
    vector<Objeto *> objetos;
    auto *parede1 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> parede1Transf;
    Matriz aux = Matriz(4,4,0);
    aux(0,0) = 1.0/2.0;
    aux(1,1) = 10;
    aux(2,2) = 10;
    Matriz aux2 = Matriz(4,4,0);
    aux2(2,3) = -4;
    aux2(0,3) = 5;
    parede1Transf.push_back(aux);
    parede1Transf.push_back(aux2);
    parede1->aplicarTransformacao(parede1Transf);

    auto *parede2 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> parede2Transf;
    Matriz aux12 = Matriz(4,4,0);
    aux12(0,0) = 10;
    aux12(1,1) = 10;
    aux12(2,2) = 1.0/2.0;
    Matriz aux22 = Matriz(4,4,0);
    aux22(2,3) = -14;
    parede2Transf.push_back(aux12);
    parede2Transf.push_back(aux22);
    parede2->aplicarTransformacao(parede2Transf);

    auto *parede3 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material2);
    vector<Matriz> parede3Transf;
    Matriz aux13 = Matriz(4,4,0);
    aux13(0,0) = 10;
    aux13(1,1) = 1.0/2.0;
    aux13(2,2) = 10;
    Matriz aux23 = Matriz(4,4,0);
    aux23(2,3) = -4;
    parede3Transf.push_back(aux13);
    parede3Transf.push_back(aux23);
    parede3->aplicarTransformacao(parede3Transf);
// ------------------------------------- Abajour ---------------------------------------------------------------------
    auto *cabecaAb = new Cilindro(1.1, 1, *biblioteca::CriarPonto(3.75, 4, -13), normal,
            material4);
    auto *troncoAb = new Cilindro(5, 0.1, *biblioteca::CriarPonto(3.75, -1, -13), normal,
                                  material2);
    auto *peAb = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> peAbTransf;
    Matriz auxP = Matriz(4,4,0);
    auxP(0,0) = 1;
    auxP(1,1) = 0.1;
    auxP(2,2) = 1;
    Matriz auxP1 = Matriz(4,4,0);
    auxP1(0,3) = 3.75;
    auxP1(1,3) = 0.5;
    auxP1(2,3) = -12.5;
    peAbTransf.push_back(auxP);
    peAbTransf.push_back(auxP1);
    peAb->aplicarTransformacao(peAbTransf);


// ------------------------------------- Add objeto ao vetor ---------------------------------------------------------
    objetos.push_back(parede1);
    objetos.push_back(parede2);
    objetos.push_back(parede3);
    objetos.push_back(cabecaAb);
    objetos.push_back(troncoAb);
    objetos.push_back(peAb);

// ------------------------------------- Infos da Grade --------------------------------------------------------------
    float tamGrade = 4;
    float zGrade = -4;

// ------------------------------------- Coordenadas Camera ----------------------------------------------------------
//Cima
    Ponto* pCoordCamera1 = biblioteca::CriarPonto(0, 40, -9);
    Ponto* pLookAt1 = biblioteca::CriarPonto(0,0,-9);
    Ponto* pViewUp1 = biblioteca::CriarPonto(0,40,-10);
//Lado
//    Ponto* pCoordCamera = biblioteca::CriarPonto(20, 0, -5);
//    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-15);
//    Ponto* pViewUp = biblioteca::CriarPonto(20,1,-5);
//Frente
    Ponto* pCoordCamera = biblioteca::CriarPonto(-10, 10, 5);
    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-4);
    Ponto* pViewUp = biblioteca::CriarPonto(-10,11,5);

    auto camera =  new Camera(pCoordCamera, pLookAt, pViewUp, tamGrade, zGrade, matrixSize);
    camera1 =  new Camera(pCoordCamera1, pLookAt1, pViewUp1, tamGrade, zGrade, matrixSize);
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