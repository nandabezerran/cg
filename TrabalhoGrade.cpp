//
// Created by fbeze on 23/08/2019.
//
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "biblioteca/Cilindro.hpp"
#include "biblioteca/biblioteca.hpp"
#include "biblioteca/Cone.hpp"
#include "biblioteca/Esfera.hpp"


//Como compilar: g++ -c TrabalhoGrade.cpp -I eigen -std=c++11 ./biblioteca/*.cpp && g++ -o principal *.o
//Como executar: ./principal



Ponto** MatrixAllocation(int size){
    auto **matrix = new Ponto*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new Ponto[size];
    }
    return matrix;
}

int** MatrixAllocationInt(int size){
    auto **matrix = new int*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new int[size];
    }
    return matrix;
}

void PrintMatrix(Ponto **matrix, int size){
    for (int l = 0; l < size; ++l) {
        for (int m = 0; m < size; ++m) {
            cout << matrix[l][m].x << " ," << matrix[l][m].y << " ,"<< matrix[l][m].z;
            cout << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void PrintMatrixInt(int **matrix, int size){
    char c = 32;
    for (int l = size-1; l >=0; --l) {
        for (int m = 0; m < size; ++m) {
            
            if (matrix[m][l] == 1)
                cout << "█";
            else
                cout << c; 

            cout << " ";
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
    float z = pYDistance;

    Ponto **finalMatrix = MatrixAllocation(pMatrixSize);

    for(int column = 0; column < pMatrixSize; ++column ){
        posY = -pLength/2 + column*pointDistance;
        for (int row = 0; row < pMatrixSize; ++row){
            posX = -pLength/2 + row*pointDistance;

            Ponto p;
            p.x = posX;
            p.y = posY;
            p.z = z;

            finalMatrix[row][column] = p;
        }

    }
    return finalMatrix;
}

int intersections(vector<Objeto*> Objects, double pZObserver, double pYObserver, Ponto pointGrid){
    int tamanho = 3;

    auto *p = new Ponto;
    *p = pointGrid;

    Ponto* observerPos = biblioteca::CriarPonto(0, pYObserver, pZObserver);

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(observerPos, p, tamanho);

    //cout << lineObGrid << endl;
    cout << endl;
    Ponto* p_int1;
    Ponto* p_int2;
    for (auto &Object : Objects) {
        tie(p_int1,p_int2) = Object->IntersecaoReta(observerPos, lineObGrid, tamanho);
        
        if(p_int1 != nullptr && p_int2 != nullptr){
            cout << "Duas intersecao no objeto : " << Object->nome<< "\n";
            cout << "Primeira intersecao : " << p_int1->x << "," << p_int1->y  << "," << p_int1->z<< "\n";
            cout << "Segunda intersecao : " << p_int2->x << "," << p_int2->y  << "," << p_int2->z << endl;
            return 1;

        }
        else{
            if(p_int1 != nullptr){
                cout << "Uma intersecao no objeto : " << Object->nome << "\n";
                cout << "Ponto de intersecao : " << p_int1->x << "," << p_int1->y  << "," << p_int1->z<< "\n";
                return 1;
            }
            else if(p_int2 != nullptr){
                cout << "Uma intersecao no objeto : " << Object->nome << "\n";
                cout << "Ponto de intersecao : " << p_int2->x << "," << p_int2->y  << "," << p_int2->z<< "\n";
                return 1;
            }
            else{
                cout << "Nenhuma intersecao no objeto : " << Object->nome<< "\n";
                return 0;
            }
        }

    }
    cout << "\n\n";
    cout << "\n";
    delete(p);
}

int main(){

    vector<Objeto*> objects;
    VectorXd normal(3);
    normal << 0,1,0;
    //ALTURA, RAIO, CENTRO, NORMAL
    //auto *objeto3 = new Esfera(3, biblioteca::CriarPonto(0,0,-10));
    auto *objeto2 = new Cilindro(5, 1, biblioteca::CriarPonto(0,-5,-10), normal);
    //auto *objeto3 = new Cone(20, 8, biblioteca::CriarPonto(0,0,-10), normal);
    auto *objeto3 = new Cone(4, 3, biblioteca::CriarPonto(0,0,-10), normal);
    //Cubo* objeto3 = new Cubo(normal, 4, biblioteca::CriarPonto(0,0,-5));
    //Cubo* objeto4 = new Cubo();
    //Cubo* objeto5 = new Cubo();


    //objects.push_back(objeto1);
    objects.push_back(objeto2);
    objects.push_back(objeto3);
    //objects.push_back(objeto4);
    //objects.push_back(objeto5);
    
    float pZObserver = 0;
    float pYObserver = 0;
    int matrixSize = 50;
    float pLength = 4;
    float pZGrid = -4;
    Ponto** matrix = createGrid(pLength, pZGrid, matrixSize);
    int** pintura = MatrixAllocationInt(matrixSize);
    //PrintMatrix(matrix,10);

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize ; ++j) {
            cout << "Ponto da grade: " << matrix[i][j].x << "," << matrix[i][j].y << "," << matrix[i][j].z << "\n";
            pintura[i][j] = intersections(objects, pZObserver, pYObserver, matrix[i][j]);;

        }
    }
    PrintMatrixInt(pintura, matrixSize);
    

   /*Matriz teste jarelio

   int tamanho_matriz = 20;
   MatrixXd testem(tamanho_matriz+1,tamanho_matriz+1);
   for(int i = 0; i<=tamanho_matriz; i++){
       for(int j = 0; j<=tamanho_matriz; j++){
           testem(i,j) = 0;
       }
   }
            
   VectorXd teste(3);
   teste << 0,0,0;
   Ponto* p1;
   Ponto* p2;
   
   for(Objeto* o : objects){
       for(int i = -floor(tamanho_matriz/2); i <= floor(tamanho_matriz/2); i++){
           for(int j = -floor(tamanho_matriz/2); j <= floor(tamanho_matriz/2); j++){
                teste << i,j,-10;
                cout << "Ponto da grade: " << "x: 0 "   << "y: " << j << "z: -10" << endl;
                tie(p1,p2) = o->IntersecaoReta(biblioteca::CriarPonto(0,0,0),teste,3);
                if(p1!=nullptr){
                    testem(floor(tamanho_matriz/2)-j,i+floor(tamanho_matriz/2)) = 1;
                    cout << "Ponto1: " << "x: " << p1->x << "y: " << p1->y << "z: " << p1->z << endl;
                }
                if(p2!=nullptr){
                    testem(floor(tamanho_matriz/2)-j,i+floor(tamanho_matriz/2)) = 1;
                    cout << "Ponto2: " << "x: " << p2->x << "y: " << p2->y << "z: " << p2->z << endl;
                }
           }
       }
   }
   cout << endl << testem << endl;

   char c = 32;
       for(int i = -floor(tamanho_matriz/2); i <= floor(tamanho_matriz/2); i++){
           for(int j = -floor(tamanho_matriz/2); j <= floor(tamanho_matriz/2); j++){  
            if (testem(i+floor(tamanho_matriz/2),floor(tamanho_matriz/2)-j) == 1)
                cout << "█";
            else
                cout << c;
        }
        cout << endl;
    }
    */
}