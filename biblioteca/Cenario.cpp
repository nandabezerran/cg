//
// Created by fbeze on 02/09/2019.
//

#include "Cenario.hpp"

Cenario::Cenario(Camera *pCamera) : camera(pCamera), imagem(camera->qtdFuros, camera->qtdFuros){}

void Cenario::addObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}
/// Função para comparar qual dos pontos de interseçao foi o primeiro.
/// \param i
/// \param j
/// \return
bool comparacaoDistancia(pontoIntersecao* i,pontoIntersecao* j){
    return (i->distOrigem < j->distOrigem);
}

void iniciarPintura(colour** &pintura, int tam){
    for (int i = 0; i < tam; ++i) {
        for (int j = 0; j < tam ; ++j) {
            pintura[i][j] = BLUE;
        }
    }
}
/// \return ponteiro para pontoIntersecao
pontoIntersecao* criarPint(Ponto *p, Objeto *objeto, double distancia){
    auto *pInt = new pontoIntersecao;
    pInt->p = p;
    pInt->objeto = objeto;
    pInt->distOrigem = distancia;
    return pInt;
}

vector<pontoIntersecao*> Cenario::rayCasting(VectorXd vetorObGrade){
    int tamanho = 3;
    vector<pontoIntersecao*> pInts;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    for (auto &Object : objetos) {
        if(!Object->visibilidade) {
            tie(p_int1, p_int2) = Object->IntersecaoReta(camera->coordCamera, vetorObGrade, tamanho);
            if (p_int1 != nullptr) {
                pInts.push_back(criarPint(p_int1, Object, biblioteca::distanciaEntrePontos(camera->coordCamera, p_int1)));
            }
            if (p_int2 != nullptr) {
                pInts.push_back(criarPint(p_int2, Object, biblioteca::distanciaEntrePontos(camera->coordCamera, p_int2)));
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

vector<pontoIntersecao*> intersections(Objeto* Object, Ponto *posObs, Ponto* pointGrid){
    int tamanho = 3;

    VectorXd lineObGrid = biblioteca::SubtracaoPontos(posObs, pointGrid, tamanho);

    vector<pontoIntersecao*> pInts;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    tie(p_int1, p_int2) = Object->IntersecaoReta(posObs, lineObGrid, tamanho);

    if (p_int1 != nullptr) {
        pInts.push_back(criarPint(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1)));
    }
    if (p_int2 != nullptr) {
        pInts.push_back(criarPint(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2)));

    }

    if (pInts.empty()){
        return pInts;
    }
    //Ordena o vetor por meio da distancia do ponto da interseção e da posição do observador
    std::sort(pInts.begin(), pInts.end(), comparacaoDistancia);
    return pInts;
}

colour** MatrixAllocatioColour(int size){
    auto **matrix = new colour*[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new colour[size];
    }
    return matrix;
}

colour** Cenario::pintarObjeto(Ponto*** pGrade){
    colour** pintura = MatrixAllocatioColour(camera->qtdFuros);
    iniciarPintura(pintura, camera->qtdFuros);
    pontoIntersecao aux;
    bool auxDefinido = false;
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros; ++j) {
            for (auto &pObjeto : objetos) {
                if (pObjeto->visibilidade) {
                    vector<pontoIntersecao*> pints = intersections(pObjeto, camera->coordCamera, pGrade[i][j]);
                    if(!(pints.empty()) && (!auxDefinido || pints[0]->distOrigem < aux.distOrigem)){
                        aux.distOrigem = pints[0]->distOrigem;
                        aux.p = pints[0]->p;
                        aux.objeto = pints[0]->objeto;
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
                pintura[i][j] = aux.objeto->cor;
            }
            auxDefinido = false;
        }
    }
    return pintura;
}

uint8_t* getRgb(colour cor){

    auto *rgb = new uint8_t[3];
    switch (cor) {
        case DARKBLUE:
            rgb[0] = 0;
            rgb[1] = 0;
            rgb[2] = 139;
            break;
        case DARKGREEN:
            rgb[0] = 0;
            rgb[1] = 100;
            rgb[2] = 0;
            break;
        case DARKTEAL:
            rgb[0] = 0;
            rgb[1] = 100;
            rgb[2] = 0;
            break;
        case BROWN:
            rgb[0] = 139;
            rgb[1] = 69;
            rgb[2] = 19;
            break;
        case DARKPINK:
            rgb[0] = 231;
            rgb[1] = 84;
            rgb[2] = 128;
            break;
        case DARKYELLOW:
            rgb[0] = 0;
            rgb[1] = 100;
            rgb[2] = 0;
            break;
        case GRAY:
            rgb[0] = 128;
            rgb[1] = 128;
            rgb[2] = 128;
            break;
        case DARKGRAY:
            rgb[0] = 105;
            rgb[1] = 105;
            rgb[2] = 105;
            break;
        case BLUE:
            rgb[0] = 135;
            rgb[1] = 206;
            rgb[2] = 235;
            break;
        case GREEN:
            rgb[0] = 34;
            rgb[1] = 139;
            rgb[2] = 34;
            break;
        case TEAL:
            rgb[0] = 0;
            rgb[1] = 128;
            rgb[2] = 128;
            break;
        case PINK:
            rgb[0] = 255;
            rgb[1] = 20;
            rgb[2] = 147;
            break;
        case YELLOW:
            rgb[0] = 100;
            rgb[1] = 100;
            rgb[2] = 0;
            break;
        case WHITE:
            rgb[0] = 100;
            rgb[1] = 100;
            rgb[2] = 100;
            break;
    }
    return rgb;
}

void Cenario::imprimirCenario(colour **matrix) {
    uint8_t *rgb;
    for (int l = 0; l < camera->qtdFuros; ++l) {
        for (int m = 0; m < camera->qtdFuros; ++m) {
            rgb = getRgb(matrix[m][l]);
            imagem.setPixel(l,m,rgb[2],rgb[1],rgb[0]);
            delete[] rgb;
        }
    }
    imagem.salvar("TesteCamera.bmp");
}

