#include "programaprincipal.hpp"
#include <iostream>
using namespace std;

//Como compilar: g++ programaprincipal.cpp ./biblioteca/biblioteca.cpp -o principal 
//Como executar: ./principal

int main(void){
    Biblioteca lib = Biblioteca();

    /*Inicialização dos dados necessários*/
    int tamanho = 3;

    VectorXd vetor1(tamanho);
    vetor1 << 1,1,1;
    VectorXd vetor2(tamanho);
    vetor2 << 2,3,4;

    Ponto ponto1;
    ponto1.x = 1, ponto1.y = -1, ponto1.z = -4;
    Ponto ponto2;
    ponto2.x = 3, ponto2.y = 4, ponto2.z = 3;

    /*Produto Escalar de dois vetores*/
    cout << lib.ProdutoEscalar(vetor1,vetor2,tamanho) << endl;

    /*Produto Vetorial de dois vetores*/
    cout << lib.ProdutoVetorial(vetor1,vetor2,tamanho) << endl;

    /*Normalização de um vetor*/
    cout << lib.NormalizaVetor(vetor2, tamanho) << endl;

    /*Encontra o vetor normalizado do vetor normal (produto vetorial) a 2 vetores */
    cout << lib.EncontrarNormal(vetor1,vetor2,tamanho) << endl;

    /*Dado 2 pontos mostra o vetor resultante*/
    cout << lib.SubtracaoPontos(ponto1,ponto2,tamanho);

    return 0;
}
