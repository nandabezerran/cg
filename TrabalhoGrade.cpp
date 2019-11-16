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
#include <cmath>

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
vector<Luz *> luzes;

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

void onMouseButton(int button, int state, int x, int y){
    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP){
        for(auto &luz : luzes){
            luz->estado = !luz->estado;
        }
        cenario->imprimirCenarioCompleto();
    }
}
//void onMouseButton(int button, int state, int x, int y) {
//    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
//        pontos[0] = cenario->checarUmPonto(matrixSize - y, x);
//        if (pontos[0]) {
//            subMenu = glutCreateMenu(funcaoMenu);
//            glutAddMenuEntry("Gerar espelho", 1);
//            if (pontos[1] && pontos[2]) {
//                glutAddMenuEntry("Rotacionar", 2);
//            }
//            menuPrincipal = glutCreateMenu(funcaoMenu);
//            glutAddSubMenu(pontos[0]->objeto->nome.c_str(), subMenu);
//            glutAttachMenu(GLUT_MIDDLE_BUTTON);
//            linha = matrixSize-y;
//            coluna = x;
//        }
//        cenario->imprimirCenarioCompleto();
//    }
//    if (button == GLUT_RIGHT_BUTTON) {
//        if (state == GLUT_DOWN) {
//            if (cenario->checarUmPonto(matrixSize - y, x)) {
//                pontos[1] = cenario->checarUmPonto(matrixSize - y, x);
//            }
//        } else if (state == GLUT_UP) {
//            if (cenario->checarUmPonto(matrixSize - y, x)) {
//                pontos[2] = cenario->checarUmPonto(matrixSize - y, x);
//            }
//        }
//    }
//}

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
    double m0 = 76.8;
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
    //Silver
    float ka5[3] ={ 0.19225, 0.19225, 0.19225};
    float kd5[3] ={0.50754, 0.50754, 0.50754};
    float ks5[3] ={0.508273, 0.508273, 0.508273};
    double m5 = 51.2;
    auto *material5 = new Material(ka5,kd5, ks5, m5);
    //Obsidian
    float ka6[3] ={0.05375, 0.05, 0.06625};
    float kd6[3] ={0.18275, 0.17, 0.22525};
    float ks6[3] ={0.332741, 0.328634, 0.346435};
    double m6 = 38.4;
    auto *material6 = new Material(ka6,kd6, ks6, m6);
    // Bronze
    float ka7[3] ={ 0.2125, 0.1275, 0.054 };
    float kd7[3] ={ 0.714, 0.4284, 0.18144 };
    float ks7[3] ={ 0.393548, 0.271906, 0.166721 };
    float m7 = 25.6;
    auto *material7 = new Material(ka7,kd7, ks7, m7);
    //Ruby
    float ka8[3] ={ 0.1745, 0.01175, 0.01175};
    float kd8[3] ={0.61424, 0.04136, 0.04136 };
    float ks8[3] ={0.727811, 0.626959, 0.626959 };
    float m8 =76.8 ;
    auto *material8 = new Material(ka8,kd8, ks8, m8);
    //Gold
    float ka9[3] ={ 0.24725, 0.1995, 0.0745};
    float kd9[3] ={0.75164, 0.60648, 0.22648 };
    float ks9[3] ={0.628281, 0.555802, 0.366065 };
    float m9 =51.2 ;
    auto *material9 = new Material(ka9,kd9, ks9, m9);
    // Bronze
    float ka10[3] ={ 0.2125f, 0.1275f, 0.054f };
    float kd10[3] ={ 0.714f, 0.4284f, 0.18144f };
    float ks10[3] ={ 0.393548f, 0.271906f, 0.166721f };
    float m10 = 25.6f;
    auto *material10 = new Material(ka10,kd10, ks10, m10);
//-------------------------------------------- Luzes -----------------------------------------------------------------
    auto *luzAmbiente = new LuzAmbiente(0.3,0.3,0.3);
    auto *luzPontual = new LuzPontual(0.7,0.7,0.7,-3.75, 10, -5);
    Vetor dir(0, 1, 0);
    auto *luzSpot = new LuzSpot(1.0,1.0,1.0,3.75, 3, -13, dir, 10);
    luzes.emplace_back(luzSpot);
    luzes.emplace_back(luzPontual);
//-------------------------------------------- Criação Objetos -------------------------------------------------------
    Vetor normal(0, 1, 0);
    vector<Objeto *> objetos;
    auto *parede1 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> parede1Transf;
    Matriz aux = Matriz(4,4,0);
    aux(0,0) = 1.0/2.0;
    aux(1,1) = 7;
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
    aux12(1,1) = 7;
    aux12(2,2) = 1.0/2.0;
    Matriz aux22 = Matriz(4,4,0);
    aux22(2,3) = -14;
    parede2Transf.push_back(aux12);
    parede2Transf.push_back(aux22);
    parede2->aplicarTransformacao(parede2Transf);

    auto *parede3 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material5);
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
    auto *cabecaAb = new Cilindro(0.57, 0.7, *biblioteca::CriarPonto(3.75, 3, -13), normal,
            material4);
    auto *troncoAb = new Cilindro(4, 0.1, *biblioteca::CriarPonto(3.75, -1, -13), normal,
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
// ------------------------------------- Sofa ---------------------------------------------------------------------
    auto *braco1 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> braco1Transf;
    Matriz auxb1 = Matriz(4,4,0);
    //aux(0,0) = 1.0/2.0;
    auxb1(1,1) = 1.5;
    auxb1(2,2) = 0.5;
    Matriz auxb2 = Matriz(4,4,0);
    auxb2(2,3) = -5.5;
    auxb2(0,3) = 3;
    braco1Transf.push_back(auxb1);
    braco1Transf.push_back(auxb2);
    braco1->aplicarTransformacao(braco1Transf);
    auto *bracoCin = new Cilindro(1, 0.25, *biblioteca::CriarPonto(3.5, 1.5, -5.75),
            Vetor (-1, 0, 0),material3);

    auto *braco2 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> braco2Transf;
    Matriz auxb21 = Matriz(4,4,0);
    //aux(0,0) = 1.0/2.0;
    auxb21(1,1) = 1.5;
    auxb21(2,2) = 0.5;
    Matriz auxb22 = Matriz(4,4,0);
    auxb22(2,3) = -9;
    auxb22(0,3) = 3;
    braco2Transf.push_back(auxb21);
    braco2Transf.push_back(auxb22);
    braco2->aplicarTransformacao(braco2Transf);
    auto *bracoCin2 = new Cilindro(1, 0.25, *biblioteca::CriarPonto(3.5, 1.5, -9.25),
                                  Vetor (-1, 0, 0),material3);

    auto *fundo = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> fundoTransf;
    Matriz fundoaux = Matriz(4,4,0);
    fundoaux(0,0) = 0.8;
    fundoaux(1,1) = 1;
    fundoaux(2,2) = 3;
    Matriz fundoaux2 = Matriz(4,4,0);
    fundoaux2(2,3) = -6;
    fundoaux2(0,3) = 3.1;
    fundoTransf.push_back(fundoaux);
    fundoTransf.push_back(fundoaux2);
    fundo->aplicarTransformacao(fundoTransf);

    auto *encosto = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material3);
    vector<Matriz> encostoTransf;
    Matriz encostoaux = Matriz(4,4,0);
    encostoaux(0,0) = 0.2;
    encostoaux(1,1) = 0.8;
    encostoaux(2,2) = 3;
    Matriz encostoaux2 = Matriz(4,4,0);
    encostoaux2(2,3) = -5.999;
    encostoaux2(1,3) = 1;
    encostoaux2(0,3) = 3.4;
    encostoTransf.push_back(encostoaux);
    encostoTransf.push_back(encostoaux2);
    encosto->aplicarTransformacao(encostoTransf);

    auto *encostoCin = new Cilindro(3, 0.1, *biblioteca::CriarPonto(3.4, 1.8, -6),
                                   Vetor (0, 0, -1),material3);
// ------------------------------------- Sofa2 -----------------------------------------------------------------------
    auto *braco12 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material6);
    vector<Matriz> braco12Transf;
    Matriz auxbr1 = Matriz(4,4,0);
    //aux(0,0) = 1.0/2.0;
    auxbr1(1,1) = 1.5;
    auxbr1(0,0) = 0.5;
    Matriz auxbr2 = Matriz(4,4,0);
    auxbr2(2,3) = -10;
    auxbr2(0,3) = 1;
    braco12Transf.push_back(auxbr1);
    braco12Transf.push_back(auxbr2);
    braco12->aplicarTransformacao(braco12Transf);
    auto *bracoCinb2 = new Cilindro(1, 0.25, *biblioteca::CriarPonto(1, 1.5, -10),
                                  Vetor (0, 0, -1),material6);

    auto *fundob2 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material6);
    vector<Matriz> fundob2Transf;
    Matriz fundob2aux = Matriz(4,4,0);
    fundob2aux(2,2) = 0.8;
    fundob2aux(1,1) = 1;
    fundob2aux(0,0) = 1.5;
    Matriz fundob2aux2 = Matriz(4,4,0);
    fundob2aux2(2,3) = -10.2;
    fundob2aux2(0,3) = 0.0;
    fundob2Transf.push_back(fundob2aux);
    fundob2Transf.push_back(fundob2aux2);
    fundob2->aplicarTransformacao(fundob2Transf);

    auto *braco22 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material6);
    vector<Matriz> braco22Transf;
    Matriz auxbr21 = Matriz(4,4,0);
    //aux(0,0) = 1.0/2.0;
    auxbr21(1,1) = 1.5;
    auxbr21(0,0) = 0.5;
    Matriz auxbr22 = Matriz(4,4,0);
    auxbr22(2,3) = -10;
    auxbr22(0,3) = -1;
    braco22Transf.push_back(auxbr21);
    braco22Transf.push_back(auxbr22);
    braco22->aplicarTransformacao(braco22Transf);
    auto *bracoCinb22 = new Cilindro(1, 0.25, *biblioteca::CriarPonto(-1, 1.5, -10),
                                    Vetor (0, 0, -1),material6);

    auto *encosto2 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material6);
    vector<Matriz> encosto2Transf;
    Matriz encosto2aux = Matriz(4,4,0);
    encosto2aux(2,2) = 0.2;
    encosto2aux(1,1) = 0.8;
    encosto2aux(0,0) = 1.5;
    Matriz encosto2aux2 = Matriz(4,4,0);
    encosto2aux2(2,3) = -10.9;
    encosto2aux2(1,3) = 1;
    encosto2aux2(0,3) = 0;
    encosto2Transf.push_back(encosto2aux);
    encosto2Transf.push_back(encosto2aux2);
    encosto2->aplicarTransformacao(encosto2Transf);

    auto *encostoCin2 = new Cilindro(1.5, 0.1, *biblioteca::CriarPonto(0.75, 1.8, -11),
                                    Vetor (-1, 0, 0),material6);
// ------------------------------------- Arvore redonda --------------------------------------------------------------
//    auto *vaso = new Cilindro(0.749, 0.375, *biblioteca::CriarPonto(-3.75, 0.5, -5),
//                                     Vetor (0, 1, 0),material1);
//    auto *vaso2 = new Cone(0.75, 0.75, biblioteca::CriarPonto(-3.75, 1.25, -5),
//                              Vetor (0, -1, 0),material1);
//    auto *tronco = new Cilindro(1.5, 0.10, *biblioteca::CriarPonto(-3.75, 1.25, -5),
//                           Vetor (0, 1, 0),material7);
//    auto *arvore = new Esfera(0.55,biblioteca::CriarPonto(-3.76, 3.25, -5), material0);
//    auto *galho = new Cilindro(0.7, 0.05, *biblioteca::CriarPonto(-3.85, 1.9, -5),
//            biblioteca::NormalizaVetor(Vetor (-0.6,0.2,0)),material7);
//    auto *ramo = new  Esfera(0.2,biblioteca::CriarPonto(-4.6, 2.1, -5), material0);

// ------------------------------------- Arvore de natal -------------------------------------------------------------
    auto *tronco = new Cilindro(0.6, 0.10, *biblioteca::CriarPonto(-3.75, 0.5, -5),
                                Vetor (0, 1, 0),material7);
    auto *arvore = new Cone(1, 0.75, biblioteca::CriarPonto(-3.75, 1.2, -5),
            Vetor (0, 1, 0),material0);
    auto *arvore2 = new Cone(1.2, 0.6, biblioteca::CriarPonto(-3.75, 1.7, -5),
                            Vetor (0, 1, 0),material0);
    auto *b1 = new  Esfera(0.1,biblioteca::CriarPonto(-4.3, 1.9, -5), material8);
    auto *b2 = new  Esfera(0.1,biblioteca::CriarPonto(-3.25, 2.1, -5), material9);
    auto *b3 = new  Esfera(0.1,biblioteca::CriarPonto(-3.75, 2.1, -5.5), material8);
    auto *b4 = new  Esfera(0.1,biblioteca::CriarPonto(-3.75, 2.4, -4.7), material9);

    auto *b5 = new  Esfera(0.1,biblioteca::CriarPonto(-4.4, 1.4, -5), material9);
    auto *b6 = new  Esfera(0.1,biblioteca::CriarPonto(-3.1, 1.4, -5), material8);
    auto *b7 = new  Esfera(0.1,biblioteca::CriarPonto(-3.8, 1.5, -5.7), material9);
    auto *b8 = new  Esfera(0.1,biblioteca::CriarPonto(-3.8, 1.5, -4.4), material8);

    auto *presente1 = new Cubo(0.3, biblioteca::CriarPonto(-4, 0.5, -5), material8);
    auto *presente2 = new Cubo(0.4, biblioteca::CriarPonto(-3.5, 0.5, -4.5), material9);
    auto *presente3 = new Cubo(0.5, biblioteca::CriarPonto(-3.75, 0.5, -5.5), material0);

// ------------------------------------- Estante ---------------------------------------------------------------------
    auto *estante1 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material6);
    vector<Matriz> estante1Transf;
    Matriz estante1aux = Matriz(4,4,0);
    estante1aux(2,2) = 0.5;
    estante1aux(1,1) = 0.1;
    estante1aux(0,0) = 2;
    Matriz estante1aux2 = Matriz(4,4,0);
    estante1aux2(2,3) = -13.5;
    estante1aux2(1,3) = 4;
    estante1aux2(0,3) = 1;
    estante1Transf.push_back(estante1aux);
    estante1Transf.push_back(estante1aux2);
    estante1->aplicarTransformacao(estante1Transf);

    auto *estante2 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material6);
    vector<Matriz> estante2Transf;
    Matriz estante2aux = Matriz(4,4,0);
    estante2aux(2,2) = 0.5;
    estante2aux(1,1) = 0.1;
    estante2aux(0,0) = 2;
    Matriz estante2aux2 = Matriz(4,4,0);
    estante2aux2(2,3) = -13.5;
    estante2aux2(1,3) = 3.5;
    estante2aux2(0,3) = 0;
    estante2Transf.push_back(estante2aux);
    estante2Transf.push_back(estante2aux2);
    estante2->aplicarTransformacao(estante2Transf);
// -------------------------------------------- Mesa -----------------------------------------------------------------
    auto *mesa = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material10);
    vector<Matriz> mesaTransf;
    Matriz auxm1 = Matriz(4,4,0);
    auxm1(0,0) = 3;
    auxm1(1,1) = 1.3;
    auxm1(2,2) = 0.5;
    Matriz auxm2 = Matriz(4,4,0);
    auxm2(2,3) = -13.5;
    auxm2(0,3) = -1;
    auxm2(1,3) = 0.5;
    mesaTransf.push_back(auxm1);
    mesaTransf.push_back(auxm2);
    mesa->aplicarTransformacao(mesaTransf);

    auto *armario = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material10);
    vector<Matriz> armTransf;
    Matriz auxarm1 = Matriz(4,4,0);
    auxarm1(0,0) = 1.0;
    auxarm1(1,1) = 0.9;
    auxarm1(2,2) = 0.1;
    Matriz auxarm2 = Matriz(4,4,0);
    auxarm2(2,3) = -13.4;
    auxarm2(0,3) = -0.2;
    auxarm2(1,3) = 0.7;
    armTransf.push_back(auxarm1);
    armTransf.push_back(auxarm2);
    armario->aplicarTransformacao(armTransf);
    auto *puxador = new Cilindro(0.5, 0.05, *biblioteca::CriarPonto(-0.4, 0.9, -13.4),
                                 Vetor (0, 1, 0),material5);

    auto *gaveta1 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material10);
    vector<Matriz> gaveta1Transf;
    Matriz auxgaveta11 = Matriz(4,4,0);
    auxgaveta11(0,0) = 1.3;
    auxgaveta11(1,1) = 0.3;
    auxgaveta11(2,2) = 0.1;
    Matriz auxgaveta12 = Matriz(4,4,0);
    auxgaveta12(2,3) = -13.4;
    auxgaveta12(0,3) = -1.6;
    auxgaveta12(1,3) = 1.3;
    gaveta1Transf.push_back(auxgaveta11);
    gaveta1Transf.push_back(auxgaveta12);
    gaveta1->aplicarTransformacao(gaveta1Transf);
    auto *puxador1 = new Cilindro(0.5, 0.05, *biblioteca::CriarPonto(-1.3, 1.45, -13.4),
                                 Vetor (-1, 0, 0),material5);

    auto *gaveta2 = new Cubo(1, biblioteca::CriarPonto(0, 0, -0.5), material10);
    vector<Matriz> gaveta2Transf;
    Matriz auxgaveta21 = Matriz(4,4,0);
    auxgaveta21(0,0) = 1.3;
    auxgaveta21(1,1) = 0.3;
    auxgaveta21(2,2) = 0.1;
    Matriz auxgaveta22 = Matriz(4,4,0);
    auxgaveta22(2,3) = -13.4;
    auxgaveta22(0,3) = -1.6;
    auxgaveta22(1,3) = 0.7;
    gaveta2Transf.push_back(auxgaveta21);
    gaveta2Transf.push_back(auxgaveta22);
    gaveta2->aplicarTransformacao(gaveta2Transf);
    auto *puxador2 = new Cilindro(0.5, 0.05, *biblioteca::CriarPonto(-1.3, 0.85, -13.4),
                                  Vetor (-1, 0, 0),material5);


// ------------------------------------- Add objeto ao vetor ---------------------------------------------------------

    objetos.push_back(parede1);
    objetos.push_back(parede2);
    objetos.push_back(parede3);

    objetos.push_back(cabecaAb);
    objetos.push_back(troncoAb);
    objetos.push_back(peAb);

    objetos.push_back(braco1);
    objetos.push_back(bracoCin);
    objetos.push_back(braco2);
    objetos.push_back(bracoCin2);
    objetos.push_back(fundo);
    objetos.push_back(encosto);
    objetos.push_back(encostoCin);

    objetos.push_back(braco12);
    objetos.push_back(bracoCinb2);
    objetos.push_back(fundob2);
    objetos.push_back(braco22);
    objetos.push_back(bracoCinb22);
    objetos.push_back(encosto2);
    objetos.push_back(encostoCin2);

    objetos.push_back(tronco);
    objetos.push_back(arvore);
    objetos.push_back(arvore2);
    objetos.push_back(b1);
    objetos.push_back(b2);
    objetos.push_back(b3);
    objetos.push_back(b4);

    objetos.push_back(b5);
    objetos.push_back(b6);
    objetos.push_back(b7);
    objetos.push_back(b8);

    objetos.push_back(presente1);
    objetos.push_back(presente2);
    objetos.push_back(presente3);

    objetos.push_back(estante1);
    objetos.push_back(estante2);


    objetos.push_back(mesa);
    objetos.push_back(armario);
    objetos.push_back(puxador);
    objetos.push_back(gaveta1);
    objetos.push_back(puxador1);
    objetos.push_back(gaveta2);
    objetos.push_back(puxador2);
//    objetos.push_back(vaso);
//    objetos.push_back(vaso2);

//    objetos.push_back(galho);
//    objetos.push_back(ramo);

// ------------------------------------- Infos da Grade --------------------------------------------------------------
    float tamGrade = 4;
    float zGrade = -4;

// ------------------------------------- Coordenadas Camera ----------------------------------------------------------
//Cima
    Ponto* pCoordCamera1 = biblioteca::CriarPonto(0, 40, -9);
    Ponto* pLookAt1 = biblioteca::CriarPonto(0,0,-9);
    Ponto* pViewUp1 = biblioteca::CriarPonto(0,40,-10);
//Lado
//    Ponto* pCoordCamera = biblioteca::CriarPonto(0, 8, 10);
//    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-4);
//    Ponto* pViewUp = biblioteca::CriarPonto(0,9,10);
//Frente
    Ponto* pCoordCamera = biblioteca::CriarPonto(-20, 6, -9);
    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-9);
    Ponto* pViewUp = biblioteca::CriarPonto(-20,7,-9);
//Lado
//    Ponto* pCoordCamera = biblioteca::CriarPonto(-5, 10, 10);
//    Ponto* pLookAt = biblioteca::CriarPonto(0,0,-4);
//    Ponto* pViewUp = biblioteca::CriarPonto(-5,11,10);

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