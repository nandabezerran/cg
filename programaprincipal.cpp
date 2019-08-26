#include "programaprincipal.hpp"
#include "biblioteca/Cubo.hpp"
#include <iostream>
#include <stdlib.h>



using namespace std;

//Como compilar: g++ -c programaprincipal.cpp ./biblioteca/*.cpp && g++ -o principal *.o
//Como executar: ./principal


int tamanho = 3;
IOFormat CommaInitFmt(StreamPrecision, DontAlignCols, ", ", ", ", "", "", "[", "]");

int main(void){
    cout << fixed;
    cout.precision(3);
	//----------------------------------FUNCOES BASICAS----------------------------------

    /*
      PE = ProdutoEscalar
      PV = ProdutoVetorial
      NV = NormalizaVetor
      EN = EncontraNormal
      SP = SubtracaoPontos
    */

    //Inicialização dos dados necessários para PE, PV, NV, EN
    VectorXd vetor1(tamanho);
    vetor1 << 1,1,1;
    VectorXd vetor2(tamanho);
    vetor2 << 2,3,4;

    //Inicialização dos dados necessários para SP
    Ponto* ponto1 = biblioteca::CriarPonto(1,-1,-4);
    Ponto* ponto2 = biblioteca::CriarPonto(3,4,3);



    //Produto Escalar de dois vetores
    cout << "Produto Escalar: " << biblioteca::ProdutoEscalar(vetor1,vetor2,tamanho) << endl;

    //Produto Vetorial de dois vetores
    cout << "\nProduto Vetorial:" << biblioteca::ProdutoVetorial(vetor1,vetor2,tamanho).format(CommaInitFmt) << endl;

    //Normalização de um vetor
    cout << "\nNormaliza Vetor:\n" << biblioteca::NormalizaVetor(vetor2, tamanho).format(CommaInitFmt) << endl;

    //Encontra o vetor normalizado do vetor normal (produto vetorial) a 2 vetores
    cout << "\nNormal:\n" << biblioteca::EncontrarNormal(vetor1,vetor2,tamanho).format(CommaInitFmt) << endl;

    //Dado 2 pontos mostra o vetor resultante
    cout << "\nSubtracao de Pontos:\n" << biblioteca::SubtracaoPontos(ponto1,ponto2,tamanho).format(CommaInitFmt) << endl;


    //---------------------------------- OUTRAS FUNCOES ----------------------------------


    //Dado os vetores (vetor1, vetor2), o comprimento (L) retornar os dois pontos(p_int1, p_int2)
 
 /*

    VectorXd v1_(tamanho), v2_(tamanho);
    v1_ << 1 ,0 ,0;
    v2_ << sqrt(2)/2, -sqrt(2)/2, 0;
    double l_comprimento = 100;
    Ponto p_int1, p_int2, po;
    po.x = 0;
    po.y = 0;
    po.z = 0;
    tie(p_int1,p_int2) = biblioteca::PontosDadoDistancia(po,v1_,v2_,l_comprimento, tamanho);
    cout << "Ponto1 = " << " ";
    cout << "x: " << p_int1.x << " ";
    cout << "y: " << p_int1.y << " ";
    cout << "z: " << p_int1.z << endl;

    cout << "Ponto2 = " << " ";
   	cout << "x: " << p_int2.x << " ";
    cout << "y: " << p_int2.y << " ";
    cout << "z: " << p_int2.z << endl;

*/

    //-------------------------------------------------------------------------

    cout << "\n--------------TESTE DAS INTERSECOES--------------" << endl;


	// Declarações para Intersecoes

    int intersec,validacao;
    double raio, H;
    Ponto* p0;
    Ponto* p_pi;
    Ponto* p_centro;
    Ponto* p_int1;
    Ponto* p_int2;
    VectorXd vetor0(tamanho), vetor_n(tamanho);


    // Intersecao Reta/Plano

    vetor0 << 1,1,1;
    vetor_n << 7,3,-5;
    p0 = biblioteca::CriarPonto(0,0,0);
    p_pi = biblioteca::CriarPonto(2,2,2);
    
    cout << "\nReta/Plano: " << endl;
    Plano* plano = new Plano(p_pi, vetor_n);
    p_int1 = plano->IntersecaoRetaPlano(p0, vetor0, tamanho);
    printIntersecoes(p_int1);


    // Teste Equação do Plano (P_int - P_pi) * vetor_n = 0 
    double teste = biblioteca::EquacaoDoPlano(p_pi,p_int1,vetor_n,tamanho);
    cout << "\nEquacao do Plano: " << teste << endl;


    // Intersecao Reta/Esfera

    raio = 1;
    vetor0 << 0,1,0;
    p0 = biblioteca::CriarPonto(0,0,0);
    p_centro = biblioteca::CriarPonto(0,0,0);

    cout << "\nReta/Esfera: " << endl;
    Esfera* esfera = new Esfera(raio, p_centro);
    tie(p_int1,p_int2) = esfera->IntersecaoReta(p0, vetor0, tamanho);

    printIntersecoes(p_int1,p_int2);


    // Intersecao Reta/Cilindro

    H = 4;
    raio = 4;
    vetor0 << 0,1,0;
    vetor_n << 0,1,0;
    p0 = biblioteca::CriarPonto(0,0,0);
    p_centro = biblioteca::CriarPonto(0,0,0);

    
    cout << "\nReta/Cilindro: " << endl;
    Cilindro* cilindro = new Cilindro(H, raio, p_centro, vetor_n);
    std::tie(p_int1,p_int2) = cilindro->IntersecaoReta(p0, vetor0, tamanho);

    printIntersecoes(p_int1, p_int2);

    // Intersecao Reta/Cone

    H = 4;
    raio = 4;
    vetor0 << 0,1,0;
    vetor_n << 0,1,0;
    p0 = biblioteca::CriarPonto(0,0,0);
    p_centro = biblioteca::CriarPonto(0,0,0);


    cout << "\nReta/Cone: " << endl;
    Cone* cone = new Cone(H, raio, p_centro, vetor_n);
    tie(p_int1,p_int2) = cone->IntersecaoReta(p0, vetor0, tamanho);

    printIntersecoes(p_int1, p_int2);

    return 0;
}

void printIntersecoes(Ponto* p_int1, Ponto* p_int2){

    if (!p_int1 && !p_int2){
        cout << "Nao ha IntersecaoRetaObjeto" << endl;
    }
    if(p_int1){
        cout << "Ponto 1 = " << "[" << p_int1->x << ", " << p_int1->y << ", " << p_int1->z << "]" << endl;
    }
    if(p_int2){
        cout << "Ponto 2 = " << "[" << p_int2->x << ", " << p_int2->y << ", " << p_int2->z << "]" << endl;
    }
}

void printIntersecoes(Ponto* p_int1){

    if (!p_int1){
        cout << "Nao ha IntersecaoRetaObjeto" << endl;
    }
    if(p_int1){
        cout << "Ponto 1 = " << "[" << p_int1->x << ", " << p_int1->y << ", " << p_int1->z << "]" << endl;
    }
}


