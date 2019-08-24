#include "programaprincipal.hpp"
#include <iostream>
using namespace std;

//Como compilar: g++ programaprincipal.cpp ./biblioteca/biblioteca.cpp -o principal 
//Como executar: ./principal

int tamanho = 3;
Biblioteca lib = Biblioteca();
IOFormat CommaInitFmt(StreamPrecision, DontAlignCols, ", ", ", ", "", "", "[", "]");

int main(void){

	//----------------------------------FUNCOES BASICAS----------------------------------

    /*
      PE = ProdutoEscalar
      PV = ProdutoVetorial
      NV = NormalizaVetor
      EN = EncontraNormal
      SP = SubtracaoPontos
    */

    /*Inicialização dos dados necessários para PE, PV, NV, EN*/
    VectorXd vetor1(tamanho);
    vetor1 << 1,1,1;
    VectorXd vetor2(tamanho);
    vetor2 << 2,3,4;

    /*Inicialização dos dados necessários para SP*/
    Ponto ponto1;
    ponto1.x = 1, ponto1.y = -1, ponto1.z = -4;
    Ponto ponto2;
    ponto2.x = 3, ponto2.y = 4, ponto2.z = 3;


    /*Produto Escalar de dois vetores*/
    cout << "Produto Escalar: " << lib.ProdutoEscalar(vetor1,vetor2,tamanho) << endl;

    /*Produto Vetorial de dois vetores*/
    cout << "\nProduto Vetorial:" << lib.ProdutoVetorial(vetor1,vetor2,tamanho).format(CommaInitFmt) << endl;

    /*Normalização de um vetor*/
    cout << "\nNormaliza Vetor:\n" << lib.NormalizaVetor(vetor2, tamanho).format(CommaInitFmt) << endl;

    /*Encontra o vetor normalizado do vetor normal (produto vetorial) a 2 vetores */
    cout << "\nNormal:\n" << lib.EncontrarNormal(vetor1,vetor2,tamanho).format(CommaInitFmt) << endl;

    /*Dado 2 pontos mostra o vetor resultante*/
    cout << "\nSubtracao de Pontos:\n" << lib.SubtracaoPontos(ponto1,ponto2,tamanho).format(CommaInitFmt) << endl;


    //---------------------------------- OUTRAS FUNCOES ----------------------------------


    /*Dado os vetores (vetor1, vetor2), o comprimento (L) retornar os dois pontos(p_int1, p_int2)*/
//    VectorXd v1_(tamanho), v2_(tamanho);
//    v1_ << 1 ,0 ,0;
//    v2_ << sqrt(2)/2, -sqrt(2)/2, 0;
//    double l_comprimento = 100;
//    Ponto p_int1, p_int2, po;
//    po.x = 0;
//    po.y = 0;
//    po.z = 0;
//    tie(p_int1,p_int2) = lib.PontosDadoDistancia(po,v1_,v2_,l_comprimento, tamanho);
//    cout << "Ponto1 = " << " ";
//    cout << "x: " << p_int1.x << " ";
//    cout << "y: " << p_int1.y << " ";
//    cout << "z: " << p_int1.z << endl;
//
//    cout << "Ponto2 = " << " ";
//    cout << "x: " << p_int2.x << " ";
//    cout << "y: " << p_int2.y << " ";
//    cout << "z: " << p_int2.z << endl;



    //-------------------------------------------------------------------------

    cout << "\n--------------TESTE DAS INTERSECOES--------------" << endl;

	
	// Declarações para Intersecoes

    int intersec;
    double raio, H;
    Ponto p0, p_pi, p_centro, p_int1, p_int2;
    VectorXd vetor0(tamanho), vetor_n(tamanho);


    // Intersecao Reta/Plano

    vetor0 << 1,1,1;
    vetor_n << 7,3,-5;
    p0.x = 0, p0.y = 0, p0.z = 0;
    p_pi.x = 2, p_pi.y = 2, p_pi.z = 2;

    cout << "\nReta/Plano: " << endl;
    p_int1 = lib.IntersecaoRetaPlano(p0,vetor0,p_pi,vetor_n,tamanho);
    printIntersecoes(p_int1,p_int1,1);


    /* Teste Equação do Plano (P_int - P_pi) * vetor_n = 0 */
    double teste = lib.EquacaoDoPlano(p_pi,p_int1,vetor_n,tamanho);
    cout << "\nEquacao do Plano: " << teste << endl;
    

    // Intersecao Reta/Esfera

    raio = 2;
    vetor0 << 0,1,0;
    p0.x = 0, p0.y = 0, p0.z = 0;
    p_centro.x = 0, p_centro.y = 0, p_centro.z = 0;

    cout << "\nReta/Esfera: " << endl;
    tie(p_int1,p_int2,intersec) = lib.IntersecaoRetaEsfera(p0,vetor0,p_centro,raio,tamanho);
    printIntersecoes(p_int1,p_int2,intersec);


    // Intersecao Reta/Cilindro 

    H = 2;
    raio = 2;
    vetor0 << 1,1,1;
    vetor_n << 1,1,1;
    p0.x = 0, p0.y = 0, p0.z = 0;
    p_centro.x = 0, p_centro.y = 0, p_centro.z = 0;

    cout << "\nReta/Cilindro: " << endl;
    tie(p_int1,p_int2,intersec) = lib.IntersecaoRetaCilindro(p0,vetor0,vetor_n,p_centro,raio,H,tamanho);
    printIntersecoes(p_int1,p_int2,intersec);


    // Intersecao Reta/Cone






    return 0;
}


void printIntersecoes(Ponto p_int1, Ponto p_int2, int intersec){

    if (intersec == 2){
    	cout << "Ponto 1 = " << "[" << p_int1.x << ", " << p_int1.y << ", " << p_int1.z << "]" << endl;
    	cout << "Ponto 2 = " << "[" << p_int2.x << ", " << p_int2.y << ", " << p_int2.z << "]" << endl;
    }

    else if(intersec == 1)
    	cout << "Ponto 1 = " << "[" << p_int1.x << ", " << p_int1.y << ", " << p_int1.z << "]" << endl;

    else
    	cout << "Nao ha IntersecaoRetaEsfera" << endl;

} 