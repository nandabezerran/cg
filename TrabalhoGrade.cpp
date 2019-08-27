//
// Created by fbeze on 23/08/2019.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "biblioteca/Cilindro.hpp"
#include "biblioteca/biblioteca.hpp"
#include "biblioteca/Cone.hpp"
#include "biblioteca/Cubo.hpp"

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
    float pointDistance = pLength/(pMatrixSize - 1);
    float posX;
    float posY;
    float z = pYDistance;

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

void intersections(vector<Objeto*> Objects, double pDistanceObserver, Ponto pointGrid){
    int tamanho = 3;

    auto *p = new Ponto;
    *p = pointGrid;

    //Ponto localizado o olho do observador
    Ponto* observerPos = biblioteca::CriarPonto(0, 0,  pDistanceObserver + pointGrid.z);

    //Reta observador -> Ponto na grade; Ponto na grade - Observador, transformaremos em vetor unitário dentro da
    //função de interseção
    VectorXd lineObGrid = biblioteca::SubtracaoPontos(observerPos, p, tamanho);

    Ponto* p_int1;
    Ponto* p_int2;

    for (auto &Object : Objects) {
        std::tie(p_int1,p_int2) = Object->IntersecaoReta(observerPos, lineObGrid, tamanho);
        if(p_int1 && p_int2){
            cout << "Duas intersecao no objeto : " << Object->nome<< "\n";
            cout << "Primeira intersecao : " << p_int1->x << "," << p_int1->y  << "," << p_int1->z<< "\n";
            cout << "Segunda intersecao : " << p_int2->x << "," << p_int2->y  << "," << p_int2->z;
        }
        else{
            if(p_int1){
                cout << "Uma intersecao no objeto : " << Object->nome << "\n";
                cout << "Ponto de intersecao : " << p_int1->x << "," << p_int1->y  << "," << p_int1->z;
            }
            else if(p_int2){
                cout << "Uma intersecao no objeto : " << Object->nome << "\n";
                cout << "Ponto de intersecao : " << p_int2->x << "," << p_int2->y  << "," << p_int2->z;
            }
            else{
                cout << "Nenhuma intersecao no objeto : " << Object->nome;
            }
        }
        cout << "\n";
    }
    cout << "\n\n";
}

int main(){

    vector<Objeto*> objects;
    VectorXd normal(3);
    normal << 0,1,0;
    //ALTURA, RAIO, CENTRO, NORMAL
    Cilindro *objeto2 = new Cilindro(10, 4, biblioteca::CriarPonto(0,0,-4), normal);
    Cone *objeto1 = new Cone(20, 8, biblioteca::CriarPonto(0,10,-4), normal);
    //Cubo* objeto3 = new Cubo(normal, 4, biblioteca::CriarPonto(0,0,-5));
    //Cubo* objeto4 = new Cubo();
    //Cubo* objeto5 = new Cubo();


    objects.push_back(objeto1);
    objects.push_back(objeto2);
    //objects.push_back(objeto3);
    //objects.push_back(objeto4);
    //objects.push_back(objeto5);

    float pDistanceObserverGrid = 4;
    int matrixSize = 10;
    float pLength = 2;
    float pYDistance = 2;
    Ponto** matrix = createGrid(pLength, pYDistance, matrixSize);
    //PrintMatrix(matrix,10);

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize ; ++j) {
            cout << "Ponto da grade: " << matrix[i][j].x << "," << matrix[i][j].y << "," << matrix[i][j].z << "\n";
            intersections(objects,  pDistanceObserverGrid, matrix[i][j]);
        }
    }


}