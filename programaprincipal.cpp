#include "programaprincipal.hpp"
#include <iostream>
using namespace std;

//Como compilar: g++ programaprincipal.cpp ./biblioteca/biblioteca.cpp -o principal 
//Como executar: ./principal

int main(void){
    Biblioteca lib = Biblioteca();

    int tamanho = 3;

    /*PE = ProdutoEscalar
      PV = ProdutoVetorial
      NV = NormalizaVetor
      EN = EncontraNormal
      SP = SubtracaoPontos
      IRP = IntersecaoRetaPlano 
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

    /*Inicialização dos dados necessários para IRP*/
    Ponto p0;
    p0.x = 0, p0.y = 0, p0.z = 0;

    VectorXd vetor0(tamanho);
    vetor0 << 1,1,1;

    Ponto p_pi;
    p_pi.x = 2, p_pi.y = 2, p_pi.z = 2;

    VectorXd vetor_n_plano(tamanho);
    vetor_n_plano << 7,3,-5;

    /*Produto Escalar de dois vetores*/
    cout << lib.ProdutoEscalar(vetor1,vetor2,tamanho) << endl;

    /*Produto Vetorial de dois vetores*/
    cout << lib.ProdutoVetorial(vetor1,vetor2,tamanho) << endl;

    /*Normalização de um vetor*/
    cout << lib.NormalizaVetor(vetor2, tamanho) << endl;

    /*Encontra o vetor normalizado do vetor normal (produto vetorial) a 2 vetores */
    cout << lib.EncontrarNormal(vetor1,vetor2,tamanho) << endl;

    /*Dado 2 pontos mostra o vetor resultante*/
    cout << lib.SubtracaoPontos(ponto1,ponto2,tamanho) << endl;

    /*Dado os vetores (vetor1, vetor2), o comprimento (L) retornar os dois pontos(p1, p2)*/
//    VectorXd v1_(tamanho), v2_(tamanho);
//    v1_ << 1 ,0 ,0;
//    v2_ << sqrt(2)/2, -sqrt(2)/2, 0;
//    double l_comprimento = 100;
//    Ponto p1, p2, po;
//    po.x = 0;
//    po.y = 0;
//    po.z = 0;
//    tie(p1,p2) = lib.PontosDadoDistancia(po,v1_,v2_,l_comprimento, tamanho);
//    cout << "Ponto1 = " << " ";
//    cout << "x: " << p1.x << " ";
//    cout << "y: " << p1.y << " ";
//    cout << "z: " << p1.z << endl;
//
//    cout << "Ponto2 = " << " ";
//    cout << "x: " << p2.x << " ";
//    cout << "y: " << p2.y << " ";
//    cout << "z: " << p2.z << endl;

    /*Dado o ponto (p0), o vetor (vetor0) da reta o ponto (p_pi), o vetor normal (vetor_n_plano) do plano
    retornar o ponto de interseção da reta com o plano*/
    Ponto p_int = lib.IntersecaoRetaPlano(p0,vetor0,p_pi,vetor_n_plano,tamanho);
    cout << "Ponto = " << " ";
    cout << "x: " << p_int.x << " ";
    cout << "y: " << p_int.y << " ";
    cout << "z: " << p_int.z << endl;

    /*Dado o ponto (p0), o vetor (vetor0) da reta o ponto (c0_centro), o raio da esfera
    retornar o ponto de interseção da reta com o plano*/
    int intersec;
    double raio = 1;
    Ponto c0_centro, p1, p2;
    c0_centro.x = 0, c0_centro.y = 0, c0_centro.z = 0;

    tie(p1,p2,intersec) = lib.IntersecaoRetaEsfera(p0,vetor0,c0_centro,raio,tamanho);

    if (intersec == 2){
    	cout << "Ponto 1 = " << "[" << p1.x << ", " << p1.y << ", " << p1.z << "]" << endl;
    	cout << "Ponto 2 = " << "[" << p2.x << ", " << p2.y << ", " << p2.z << "]" << endl;
    }

    else if(intersec == 1)
    	cout << "Ponto 1 = " << "[" << p1.x << ", " << p1.y << ", " << p1.z << "]" << endl;

    else
    	cout << "Nao ha IntersecaoRetaEsfera" << endl;


    /* Teste equação do plano (P_int - P_pi) * vetor_n_plano = 0 */
    double teste = lib.EquacaoDoPlano(p_pi,p_int,vetor_n_plano,tamanho);
    cout << "Deve ser 0: " << teste << endl;

    return 0;
}
