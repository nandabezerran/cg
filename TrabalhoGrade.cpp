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
#include "biblioteca/cores.hpp"


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
    for (int l = 0; l < size; ++l) {
        for (int m = 0; m < size; ++m) {
            
            if (matrix[m][l] == 1)
                cout << 219;
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
Ponto** createGrid(float pLength, float pZGrid, int pMatrixSize){
    float pointDistance = pLength/(pMatrixSize);
    float posX;
    float posY;
    float z = pZGrid;

    Ponto **finalMatrix = MatrixAllocation(pMatrixSize);

    for(int column = 0; column < pMatrixSize; ++column ){
        posY = pLength/2 - pointDistance - column*pointDistance;
        for (int row = 0; row < pMatrixSize; ++row){
            posX = -pLength/2 + pointDistance + row*pointDistance;

            Ponto p;
            p.x = posX;
            p.y = posY;
            p.z = z;

            finalMatrix[row][column] = p;
        }

    }
    return finalMatrix;
}

bool intersections(vector<Objeto*> Objects, Ponto *posObs, Ponto pointGrid){
    int tamanho = 3;

    auto *p = new Ponto;
    *p = pointGrid;

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(posObs, p, tamanho);

    Ponto* p_int1;
    Ponto* p_int2;
    bool temPonto = false;
    for (auto &Object : Objects) {
        tie(p_int1,p_int2) = Object->IntersecaoReta(posObs, lineObGrid, tamanho);
        
        if(p_int1 != nullptr && p_int2 != nullptr){
//            cout << "Duas intersecao no objeto : " << Object->nome<< "\n";
//            cout << "Primeira intersecao : " << p_int1->x << "," << p_int1->y  << "," << p_int1->z<< "\n";
//            cout << "Segunda intersecao : " << p_int2->x << "," << p_int2->y  << "," << p_int2->z << endl;
            temPonto = true;

        }
        else{
            if(p_int1 != nullptr){
//                cout << "Uma intersecao no objeto : " << Object->nome << "\n";
//                cout << "Ponto de intersecao : " << p_int1->x << "," << p_int1->y  << "," << p_int1->z<< "\n";
                temPonto = true;
            }
            else if(p_int2 != nullptr){
//                cout << "Uma intersecao no objeto : " << Object->nome << "\n";
//                cout << "Ponto de intersecao : " << p_int2->x << "," << p_int2->y  << "," << p_int2->z<< "\n";
                temPonto = true;
            }
            else{
//                cout << "Nenhuma intersecao no objeto : " << Object->nome<< "\n";

            }
        }

    }

    delete(p);
    return temPonto;
}

int main(){



    // ------------------------------------- Definição Objetos -------------------------------------------------------
    //                  ORDEM DOS PARAMETROS DE ENTRADA: ALTURA, RAIO, CENTRO, NORMAL

    Vector3d normal;
    normal << 0,1,0;
    auto *objeto1 = new Cone(4, 3, biblioteca::CriarPonto(0,0,-10), normal);
    auto *objeto2 = new Cilindro(5, 1, biblioteca::CriarPonto(0,-5,-10), normal);
    //auto *objeto3 = new Cubo(normal, 4, biblioteca::CriarPonto(0,0,-5));
    //auto *objeto4 = new Cubo();
    //auto *objeto5 = new Cubo();
    //auto *objeto6 = new Cone(20, 8, biblioteca::CriarPonto(0,0,-10), normal);
    //auto *objeto7 = new Esfera(3, biblioteca::CriarPonto(0,0,-10));


    vector<Objeto*> objetos;

    objetos.push_back(objeto1);
    objetos.push_back(objeto2);
    //objects.push_back(objeto3);
    //objects.push_back(objeto4);
    //objects.push_back(objeto5);
    //objects.push_back(objeto6);
    //objects.push_back(objeto7);
    
    // ------------------------------------- Coordenadas Observador --------------------------------------------------
    float xObs = 0;
    float yObs = 0;
    float zObs = 0;
    Ponto *posObs = biblioteca::CriarPonto(xObs, yObs, zObs);

    // ------------------------------------- Infos da Grade ----------------------------------------------------------
    int matrixSize = 50;
    float tamGrade = 4;
    float zGrade = -4;
    Ponto** grade = createGrid(tamGrade, zGrade, matrixSize);


    int** pintura = MatrixAllocationInt(matrixSize);

    for (int i = 0; i < matrixSize; ++i) {
        for (int j = 0; j < matrixSize ; ++j) {
            if(intersections(objetos, posObs, grade[i][j]))
                pintura[i][j] = 1;
            else
                pintura[i][j] = 0;
        }
    }
    PrintMatrixInt(pintura, matrixSize);
    printf("%scolor", COR_VERDE);
    cout << "sduahidusa" << endl;

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