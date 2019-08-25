//
// Created by fbeze on 23/08/2019.
//
#include <iostream>
#include <stdlib.h>
#include "biblioteca/Cilindro.hpp"
#include "biblioteca/biblioteca.hpp"


Ponto** MatrixAllocation(int size){
    auto **matrix = new Ponto*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new Ponto[size];;
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

//void intersections(double pDistanceObserver, Ponto point){
//};
int main(){
    Ponto** matrix = createGrid(10, 2, 4);
    PrintMatrix(matrix,4);
    //intersections(4, matrix[1][2]);

}