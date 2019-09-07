#include <utility>

//
// Created by fbeze on 02/09/2019.
//

#include "Cenario.hpp"

Cenario::Cenario(Camera *pCamera, vector<Objeto*> pObjetos) : camera(pCamera),
imagem(camera->qtdFuros, camera->qtdFuros), objetos(pObjetos) {
    iniciarPintura();
    iniciarCenario();
}

void Cenario::iniciarCenario(){
    for (auto objeto : objetos) {
        objeto->mudaCoodCamera(camera);
    }
}

void Cenario::addObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}

void Cenario::iniciarPintura(){
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros ; ++j) {
            imagem.setPixel(i,j,0.9,0.7,0.3);
        }
    }
}

/// Função para comparar qual dos pontos de interseçao foi o primeiro.
/// \param i
/// \param j
/// \return
bool comparacaoDistancia(PontoIntersecao* i,PontoIntersecao* j){
    return (i->distOrigem < j->distOrigem);
}

PontoIntersecao* Cenario::rayCasting(Ponto* pCoordObs, Ponto* pontoGrade){
    VectorXd vetorObGrade(3);
    biblioteca::SubtracaoPontos(pCoordObs, pontoGrade, vetorObGrade);
    vector<PontoIntersecao*> pInts;

    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    for (auto &Object : objetos) {
        if(!Object->visibilidade) {
            tie(p_int1, p_int2) = Object->IntersecaoReta(pCoordObs, vetorObGrade, 3);
            if (p_int1) {
                auto *p = new PontoIntersecao(p_int1, Object,
                        biblioteca::distanciaEntrePontos(pCoordObs, p_int1));
                pInts.push_back(p);
            }
            if (p_int2) {
                auto *p = new PontoIntersecao(p_int2, Object,
                        biblioteca::distanciaEntrePontos(pCoordObs, p_int2));
                pInts.push_back(p);
            }
        }
    }
    if (pInts.empty()){
        return nullptr;
    }

    //Ordena o vetor por meio da distancia do ponto da interseção e da posição do observador
    std::sort(pInts.begin(), pInts.end(), comparacaoDistancia);
    return pInts[0];
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

void Cenario::pintarObjeto(Ponto*** pGrade){
    auto *aux = new PontoIntersecao();
    bool auxDefinido = false;
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros; ++j) {
            for (auto &pObjeto : objetos) {
                if (pObjeto->visibilidade) {
                    vector<PontoIntersecao*> pints = interceptaObjeto(pObjeto, camera->observador, pGrade[i][j]);
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
                imagem.setPixel(j,i,aux->objeto->rgb[2],aux->objeto->rgb[1],
                        aux->objeto->rgb[0]);
            }
            else{
                imagem.setPixel(j,i,0.9,0.7,0.3);
            }
            auxDefinido = false;
        }
    }
}

void Cenario::salvarCenario() {
    imagem.salvar("TesteCamera.bmp");
}
float* Cenario::getCenarioData(){
    return imagem.getPixels();
}
void Cenario::imprimirCenarioCompleto() {
    PontoIntersecao* pInt;
    for (int i = 0; i < camera->qtdFuros ; ++i) {
        for (int j = 0; j < camera->qtdFuros; ++j) {
            pInt = rayCasting(camera->observador, camera->gradeCamera[j][i]);
            if(pInt){
                pInt->objeto->visibilidade = true;
            }
        }
    }
    pintarObjeto(camera->gradeCamera);
}

void Cenario::checarUmPonto(int linha, int coluna) {
    PontoIntersecao* pInts;
    cout << "----------------------------------------------------------------------" << "\n";
    cout << "Centro (" << linha << ", "<< coluna <<"): " << camera->gradeCamera[linha][coluna]->x << ", "
    << camera->gradeCamera[linha][coluna]->y<< ", "<< camera->gradeCamera[linha][coluna]->z << "\n";
    cout << "----------------------------------------------------------------------" << "\n";
    pInts = rayCasting(camera->observador, camera->gradeCamera[linha][coluna]);
    if(pInts){
        pInts->objeto->visibilidade = true;
        cout << "Primeiro objeto encontrado: " << pInts->objeto->nome << " - Ponto Interceptado: " << pInts->p->x
        << ", " <<pInts->p->y<< ", "<< pInts->p->z<< "\n";
        cout << "----------------------------------------------------------------------" << "\n";
    }
    cout << "----------------------------------------------------------------------" << endl;
    pintarObjeto(camera->gradeCamera);
}

void Cenario::objetosVisiveis() {
    cout << "Objetos visiveis: " << "\n";
    for(auto objeto : objetos){
        if(objeto->visibilidade){
            cout << objeto->nome << "\n";
        }
    }
    cout << endl;
}

void Cenario::mudarCamera(Camera *pCamera) {
    camera = pCamera;
    for (auto objeto : objetos) {
        objeto->mudaCoodCamera(camera);
    }
}

