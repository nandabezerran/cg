#include <utility>

//
// Created by fbeze on 02/09/2019.
//

#include "Cenario.hpp"

Cenario::Cenario(Camera *pCamera, vector<Objeto*> pObjetos) : camera(pCamera),
imagem(camera->qtdFuros, camera->qtdFuros), objetos(pObjetos) {
    iniciarPintura();
}

void Cenario::addObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}

/// Função para comparar qual dos pontos de interseçao foi o primeiro.
/// \param i
/// \param j
/// \return
bool comparacaoDistancia(PontoIntersecao* i,PontoIntersecao* j){
    return (i->distOrigem < j->distOrigem);
}

void Cenario::iniciarPintura(){
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros ; ++j) {
            imagem.setPixel(i,j,(uint8_t)235,(uint8_t)206,
                            (uint8_t)135);
        }
    }
}

vector<PontoIntersecao*> Cenario::rayCasting(Ponto* pCoordCamera, Ponto* pontoGrade){
    int tamanho = 3;
    VectorXd vetorObGrade;
    vetorObGrade = biblioteca::SubtracaoPontos(pCoordCamera, pontoGrade, 3);
    vector<PontoIntersecao*> pInts;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    for (auto &Object : objetos) {
        if(!Object->visibilidade) {
            tie(p_int1, p_int2) = Object->IntersecaoReta(camera->coordCamera, vetorObGrade, tamanho);
            if (p_int1 != nullptr) {
                auto *p = new PontoIntersecao(p_int1, Object,
                        biblioteca::distanciaEntrePontos(camera->coordCamera, p_int1));
                pInts.push_back(p);
            }
            if (p_int2 != nullptr) {
                auto *p = new PontoIntersecao(p_int2, Object,
                        biblioteca::distanciaEntrePontos(camera->coordCamera, p_int2));
                pInts.push_back(p);
            }
        }
    }
    if (pInts.empty()){
        return pInts;
    }

    //Ordena o vetor por meio da distancia do ponto da interseção e da posição do observador
    std::sort(pInts.begin(), pInts.end(), comparacaoDistancia);
    return pInts;
}

vector<PontoIntersecao*> interceptaObjeto(Objeto* Object, Ponto *posObs, Ponto* pointGrid){
    int tamanho = 3;

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(posObs, pointGrid, tamanho);

    vector<PontoIntersecao*> pInts;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    tie(p_int1, p_int2) = Object->IntersecaoReta(posObs, lineObGrid, tamanho);

    if (p_int1 != nullptr) {
        auto *p = new PontoIntersecao(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1));
        pInts.push_back(p);
    }
    if (p_int2 != nullptr) {
        auto *p = new PontoIntersecao(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2));
        pInts.push_back(p);

    }

    if (pInts.empty()){
        return pInts;
    }
    //Ordena o vetor por meio da distancia do ponto da interseção e da posição do observador
    std::sort(pInts.begin(), pInts.end(), comparacaoDistancia);
    return pInts;
}

int*** MatrixAllocatioColour(int size){
    auto **matrix = new int**[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new int*[size];
        for (int j = 0; j < size; ++j) {
            matrix[i][j] = new int[3];
        }
    }
    return matrix;
}

void Cenario::pintarObjeto(Ponto*** pGrade){
    auto *aux = new PontoIntersecao();
    bool auxDefinido = false;
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros; ++j) {
            for (auto &pObjeto : objetos) {
                if (pObjeto->visibilidade) {
                    vector<PontoIntersecao*> pints = interceptaObjeto(pObjeto, camera->coordCamera, pGrade[i][j]);
                    if(!(pints.empty()) && (!auxDefinido || pints[0]->distOrigem < aux->distOrigem)){
                        aux->distOrigem = pints[0]->distOrigem;
                        aux->p = pints[0]->p;
                        aux->objeto = pints[0]->objeto;
                        auxDefinido = true;
                    }
                    // Desalocando a memoria
                    for (auto p : pints){
                        delete p;
                    }
                    pints.clear();

                }

            }
            if (auxDefinido) {
                imagem.setPixel(j,i,(uint8_t)aux->objeto->rgb[2],(uint8_t)aux->objeto->rgb[1],
                        (uint8_t)aux->objeto->rgb[0]);
            }
            auxDefinido = false;
        }
    }
}



void Cenario::salvarCenario() {
    imagem.salvar("TesteCamera.bmp");
}

