#include "programaprincipal.hpp"
#include <iostream>
using namespace std;

//Como compilar: g++ programaprincipal.cpp biblioteca.cpp -o principal 
//Como executar: ./principal

int main(void){
    Biblioteca lib = Biblioteca();

    int tamanho = 3;

    VectorXd vetor1(tamanho);
    vetor1 << 1,1,1;
    VectorXd vetor2(tamanho);
    vetor2 << 2,3,4;

    /*Produto Escalar de dois vetores*/
    cout << lib.ProdutoEscalar(vetor1,vetor2,tamanho) << endl;

    /*Produto Vetorial de dois vetores*/
    cout << lib.ProdutoVetorial(vetor1,vetor2,tamanho) << endl;

    /*Normalização de um vetor*/
    cout << lib.NormalizaVetor(vetor2, tamanho) << endl;

    return 0;
}
