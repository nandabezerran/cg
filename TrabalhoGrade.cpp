//
// Created by fbeze on 23/08/2019.
//
#include <iostream>
#include <stdlib.h>
#include "biblioteca/Cilindro.hpp"
#include "biblioteca/biblioteca.hpp"
#include "biblioteca/Cone.hpp"

Ponto** MatrixAllocation(int size){
    auto **matrix = new Ponto*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new Ponto[size];
    }
    return matrix;
}

void PrintMatrix(Ponto **matrix, int size){
    for (int l = 0; l < size; ++l) {
        for (int m = 0; m < size; ++m) {
            cout << matrix[l][m].x << " ," << matrix[l][m].y << " ,"<< matrix[l][m].z;
            cout << " | ";
        }
        cout << "\n";
    }
    cout << "\n";
}

/// Function to create the grid
/// \param pLenght
/// \param pYDistance distance from the axis Y
/// \param pMatrixSize
/// \param pPointDistance
/// \return Matrix filled with the points
Ponto** createGrid(float pLength, float pYDistance, int pMatrixSize){
    float pointDistance = pLength/(pMatrixSize -1);
    float posX;
    float posY;
    float z = -pYDistance;

    Ponto **finalMatrix = MatrixAllocation(pMatrixSize);

    for(int row = 0; row < pMatrixSize; ++row ){
        posX = -pLength/2 + row*pointDistance;
        for (int column = 0; column < pMatrixSize; ++column){
            posY = pLength/2 - column*pointDistance;
            Ponto p;
            p.x = posX;
            p.y = posY;
            p.z = z;

            finalMatrix[row][column] = p;
        }

    }
    return finalMatrix;
}

void intersections(double pDistanceObserver, Ponto* pointGrid){
    int tamanho = 3;
    VectorXd normal(3);
    normal << 0,1,0;

    Cilindro* objeto2 = new Cilindro(10, 2, biblioteca::CriarPonto(0,0,4), normal);
    Cone* objeto1 = new Cone(20, 4, biblioteca::CriarPonto(0,10,4), normal);
    Ponto* observerPos = biblioteca::CriarPonto(0, 0, pDistanceObserver);

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(observerPos, pointGrid, tamanho);
    cout << lineObGrid[0] << "-" << lineObGrid[1] << "-" << lineObGrid[2];

    Ponto* p_int1;
    Ponto* p_int2;
    int intersec;
    int validacao;
    std::tie(p_int1,p_int2) = objeto2->IntersecaoRetaCilindro(observerPos, lineObGrid, tamanho);

    cout << p_int1->x << "," << p_int1->y  << "," << p_int1->z << "||" << p_int2->x << "," << p_int2->y  << "," << p_int2->z
    << "||" << intersec << endl;


};
int main(){
    Ponto** matrix = createGrid(20, 2, 10);
    //PrintMatrix(matrix,10);
    intersections(6, matrix[1][1]);

}