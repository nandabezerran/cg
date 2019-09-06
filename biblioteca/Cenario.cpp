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
            imagem.setPixel(i,j,(uint8_t)235,(uint8_t)206,
                            (uint8_t)135);
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

vector<PontoIntersecao*> Cenario::rayCasting(Ponto* pCoordObs, Ponto* pontoGrade){
    int tamanho = 3;
    VectorXd vetorObGrade;
    vetorObGrade = biblioteca::SubtracaoPontos(pCoordObs, pontoGrade, 3);
    vector<PontoIntersecao*> pInts;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    for (auto &Object : objetos) {
        if(!Object->visibilidade) {
            tie(p_int1, p_int2) = Object->IntersecaoReta(pCoordObs, vetorObGrade, tamanho);
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

void Cenario::imprimirCenarioCompleto() {
    vector<PontoIntersecao*> pInts;
    for (int i = 0; i < camera->qtdFuros ; ++i) {
        for (int j = 0; j < camera->qtdFuros; ++j) {
            pInts = rayCasting(camera->observador, camera->gradeCamera[j][i]);
            if(!pInts.empty()){
                pInts[0]->objeto->visibilidade = true;
            }
        }
    }
    pintarObjeto(camera->gradeCamera);
    salvarCenario();
}

void Cenario::checarUmPonto(int linha, int coluna) {
    vector<PontoIntersecao*> pInts;
    cout << "----------------------------------------------------------------------" << "\n";
    cout << "Centro (" << linha << ", "<< coluna <<"): " << camera->gradeCamera[linha][coluna]->x << ", "
    << camera->gradeCamera[linha][coluna]->y<< ", "<< camera->gradeCamera[linha][coluna]->z << "\n";
    cout << "----------------------------------------------------------------------" << "\n";
    pInts = rayCasting(camera->observador, camera->gradeCamera[linha][coluna]);
    if(!pInts.empty()){
        pInts[0]->objeto->visibilidade = true;
        cout << "Primeiro objeto encontrado: " << pInts[0]->objeto->nome << " - Ponto Interceptado: " << pInts[0]->p->x
        << ", " <<pInts[0]->p->y<< ", "<< pInts[0]->p->z<< "\n";
        cout << "----------------------------------------------------------------------" << "\n";
        if(pInts.size()>1) {
            cout << "Outros objetos atingidos (em ordem):" << "\n";
            for (int i = 1; i < pInts.size(); ++i) {
                cout << i+1 << "o - "<< pInts[i]->objeto->nome << "|" << "Ponto Interceptado: " << pInts[i]->p->x << ", "
                << pInts[i]->p->y<< ", "<< pInts[i]->p->z<< "\n";
            }
        }
    }
    cout << "----------------------------------------------------------------------" << endl;
    pintarObjeto(camera->gradeCamera);
    salvarCenario();
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

