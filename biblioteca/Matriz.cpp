//
// Created by fbeze on 20/09/2019.
//

#include "Matriz.hpp"

Matriz::Matriz(unsigned pLinhas, unsigned pColunas, double initial){
    linhas = pLinhas;
    colunas = pColunas;
    matriz.resize(pLinhas);
    for (auto & i : matriz){
        i.resize(pColunas, initial);
    }
    if(linhas > 1 && colunas > 1) {
        for (unsigned l = 0; l < linhas; ++l) {
            for (unsigned m = 0; m < colunas; ++m) {
                if (l == m) {
                    matriz[l][m] = 1.0;
                } else {
                    matriz[l][m] = 0.0;
                }
            }
        }
    }
}

Matriz Matriz::operator+(Matriz &aux) {
    Matriz sum(colunas, linhas, 0.0);
    unsigned i,j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            sum(i,j) = this->matriz[i][j] + aux(i,j);
        }
    }
    return sum;
}

Matriz Matriz::operator-(Matriz & aux){
    Matriz dif(linhas, colunas, 0.0);
    unsigned i,j;
    for (i = 0; i < linhas; i++){
        for (j = 0; j < colunas; j++){
            dif(i,j) = this->matriz[i][j] - aux(i,j);
        }
    }
    return dif;
}

Matriz Matriz::operator*(Matriz & B){
    Matriz multip(linhas,B.getCols(),0.0);
    if(colunas == B.getRows()){
        unsigned i,j,k;
        double temp = 0.0;
        for (i = 0; i < linhas; i++){
            for (j = 0; j < B.getCols(); j++){
                temp = 0.0;
                for (k = 0; k < colunas; k++){
                    temp += matriz[i][k] * B(k,j);
                }
                multip(i,j) = temp;
            }
        }
        return multip;
    }
    else{
        return multip;
    }
}

double& Matriz::operator()(const unsigned &rowNo, const unsigned & colNo){
    return this->matriz[rowNo][colNo];
}

unsigned Matriz::getRows() const
{
    return this->linhas;
}

// returns col #
unsigned Matriz::getCols() const
{
    return this->colunas;
}

// Take any given matrices transpose and returns another matrix
Matriz Matriz::transpor(){
    Matriz transpose(colunas,linhas,0.0);
    for (unsigned i = 0; i < colunas; i++){
        for (unsigned j = 0; j < linhas; j++) {
            transpose(i,j) = this->matriz[j][i];
        }
    }
    return transpose;
}

void Matriz::imprimir() const{
    cout << "Matrix: " << endl;
    for (unsigned i = 0; i < linhas; i++) {
        for (unsigned j = 0; j < colunas; j++) {
            cout << "[" << matriz[i][j] << "] ";
        }
        cout << endl;
    }
}

Matriz Matriz::operator/(Matriz &aux) {
    return (aux.transpor() * *this);
}