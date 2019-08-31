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
#include <algorithm>

#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

struct pontoIntersecao{
    Ponto *p;
    Objeto *objeto;
    double distOrigem;

};
bool comparacaoDistancia(pontoIntersecao i,pontoIntersecao j){
    return (i.distOrigem < j.distOrigem);
}
pontoIntersecao* criarPint(Ponto *p, Objeto *objeto, double distancia){
    auto *pInt = new pontoIntersecao;
    pInt->p = p;
    pInt->objeto = objeto;
    pInt->distOrigem = distancia;
    return pInt;
}
struct setcolour
{
    colour _c;
    HANDLE _console_handle;


    setcolour(colour c, HANDLE console_handle)
            : _c(c), _console_handle(0)
    {
        _console_handle = console_handle;
    }
};

// We could use a template here, making it more generic. Wide streams won't
// work with this version.
basic_ostream<char> &operator<<(basic_ostream<char> &s, const setcolour &ref)
{
    SetConsoleTextAttribute(ref._console_handle, ref._c);
    return s;
}

//Como compilar: g++ -c TrabalhoGrade.cpp -I eigen -std=c++11 ./biblioteca/*.cpp && g++ -o principal *.o
//Como executar: ./principal



Ponto** MatrixAllocation(int size){
    auto **matrix = new Ponto*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new Ponto[size];
    }
    return matrix;
}

colour** MatrixAllocationInt(int size){
    auto **matrix = new colour*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new colour[size];
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

vector<pontoIntersecao> intersections(vector<Objeto*> Objects, Ponto *posObs, Ponto pointGrid){
    int tamanho = 3;

    auto *p = new Ponto;
    *p = pointGrid;

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(posObs, p, tamanho);

    vector<pontoIntersecao> pInts;
    Ponto* p_int1;
    Ponto* p_int2;

    for (auto &Object : Objects) {
        if(!Object->visibilidade) {
            tie(p_int1, p_int2) = Object->IntersecaoReta(posObs, lineObGrid, tamanho);

            if (p_int1 != nullptr && p_int2 != nullptr) {
                pInts.push_back(*criarPint(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1)));
                pInts.push_back(*criarPint(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2)));

            } else {
                if (p_int1 != nullptr) {
                    pInts.push_back(*criarPint(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1)));
                } else if (p_int2 != nullptr) {
                    pInts.push_back(*criarPint(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2)));

                }
            }
        }
    }
    //Ordena o vetor
    if (pInts.empty()){
        return pInts;
    }

    std::sort(pInts.begin(), pInts.end(), comparacaoDistancia);
    delete(p);
    return pInts;
}

vector<pontoIntersecao> intersections(Objeto* Object, Ponto *posObs, Ponto pointGrid){
    int tamanho = 3;

    auto *p = new Ponto;
    *p = pointGrid;

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(posObs, p, tamanho);

    vector<pontoIntersecao> pInts;
    Ponto* p_int1;
    Ponto* p_int2;

    tie(p_int1, p_int2) = Object->IntersecaoReta(posObs, lineObGrid, tamanho);

    if (p_int1 != nullptr && p_int2 != nullptr) {
        pInts.push_back(*criarPint(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1)));
        pInts.push_back(*criarPint(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2)));

    } else {
        if (p_int1 != nullptr) {
            pInts.push_back(*criarPint(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1)));
        } else if (p_int2 != nullptr) {
            pInts.push_back(*criarPint(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2)));

        }
    }
    delete(p);
    return pInts;
}

void iniciarPintura(colour** &pintura, int tam){
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam ; ++j) {
            pintura[i][j] = BLUE;
        }
    }
}

colour** pintarObjeto(vector<Objeto*> pObjetos, int pMatrixSize, Ponto *posObs, Ponto** pGrade){
    colour** pintura = MatrixAllocationInt(pMatrixSize);
    iniciarPintura(pintura, pMatrixSize);
    for (auto &pObjeto : pObjetos) {
        if (pObjeto->visibilidade) {
            for (int i = 0; i < pMatrixSize; ++i) {
                for (int j = 0; j < pMatrixSize; ++j) {
                    vector<pontoIntersecao> pints = intersections(pObjeto, posObs, pGrade[i][j]);
                    if (!pints.empty()) {
                        pintura[i][j] = pObjeto->cor;
                    }
                }
            }
        }
    }
    return pintura;
}

void PrintPintura(colour **matrix, int size){
    HANDLE chandle = GetStdHandle(STD_OUTPUT_HANDLE);
    for (int l = 0; l < size; ++l) {
        for (int m = 0; m < size; ++m) {
            #ifdef _WIN32
            cout << setcolour(matrix[m][l], chandle) << '\xDB';
            #elif __linux__
            cout << "█";
            #endif
        }
        cout << "\n";
    }
    cout << "\n";
}

/// Primeira pergunta que o creto quer, dado a linha e a coluna retornar o centro do ponto;
/// \param linha
/// \param coluna
/// \param matriz
/// \return
Ponto* celulaMatrizPonto(int linha, int coluna, Ponto** matriz){
    auto centroPonto = new Ponto;
    *centroPonto = matriz[linha][coluna];
    return centroPonto;
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
    int matrixSize = 10;
    float tamGrade = 4;
    float zGrade = -4;
    Ponto** grade = createGrid(tamGrade, zGrade, matrixSize);

    //int** pintura = MatrixAllocationInt(matrixSize);
    colour** pintura;
    int linha = 0;
    int coluna = 0;
    int qtdObjVisiveis = objetos.size();
    vector<pontoIntersecao> pInts;
    cout << "Quantidade de furos: " << matrixSize << "\n";
    while(qtdObjVisiveis != 0){
        cout << "Digite a linha desejada: " << "\n";
        cin >> linha;
        cout << "Digite a coluna desejada: " << "\n";
        cin >> coluna;

        pInts = intersections(objetos, posObs, grade[linha][coluna]);

        cout << "Quantida de intersecoes: " << pInts.size() << "\n";


        if(!pInts.empty()){
            pInts[0].objeto->visibilidade = true;
            cout << pInts[0].objeto->visibilidade << "\n";
            cout << "Primeiro objeto acertado: " << pInts[0].objeto->nome << "\n";
            qtdObjVisiveis -= 1;
            PrintPintura(pintarObjeto(objetos, matrixSize, posObs, grade), matrixSize);
            cout << objeto1->visibilidade << endl;
        }

        if(qtdObjVisiveis == 0){
            cout << "Todos os objetos encontrados !!" << endl;
            break;
        }

    }


// ---------------------------------- Loop Para Percorrer Toda a Matriz ----------------------------------------------
//    for (int i = 0; i < matrixSize ; ++i) {
//        for (int j = 0; j < matrixSize ; ++j) {
//            if(!intersections(objetos, posObs, grade[i][j]).empty()){
//                pInts[0].objeto->visibilidade = true;
//                PrintPintura(pintarObjeto(objetos, matrixSize, posObs, grade), matrixSize);
//            }
//        }
//    }



    system("pause");


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