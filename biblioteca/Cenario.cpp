#include <utility>
#include <c++/algorithm>

//
// Created by fbeze on 02/09/2019.
//

#include "Cenario.hpp"

Cenario::Cenario(Camera *pCamera, vector<Objeto*> pObjetos, LuzAmbiente* pLuzAmb, vector<Luz*> pLuzes) : camera(pCamera),
imagem(camera->qtdFuros, camera->qtdFuros), objetos(pObjetos), luzAmbiente(pLuzAmb), luzes(pLuzes) {
    iniciarPintura();
    iniciarCenario();
}

void Cenario::iniciarCenario(){
    for (auto objeto : objetos) {
        objeto->mudaCoodCamera(camera);
    }
    for (auto luz : luzes) {
        luz->mudaCoodCamera(camera);
    }
}

void Cenario::addObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}

void Cenario::iniciarPintura(){
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros ; ++j) {
            imagem.setPixel(i,j,0.3,0.7,0.9);
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

PontoIntersecao* interceptaObjeto(Objeto* Object, Ponto *posObs, Ponto* pointGrid){

    Vetor lineObGrid = biblioteca::SubtracaoPontos(*posObs, *pointGrid);

    vector<PontoIntersecao*> pInts;
    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    tie(p_int1, p_int2) = Object->IntersecaoReta(posObs, lineObGrid);

    if (p_int1 != nullptr) {
        auto *p = new PontoIntersecao(p_int1, Object, biblioteca::distanciaEntrePontos(posObs, p_int1));
        pInts.push_back(p);
    }
    if (p_int2 != nullptr) {
        auto *p = new PontoIntersecao(p_int2, Object, biblioteca::distanciaEntrePontos(posObs, p_int2));
        pInts.push_back(p);

    }

    if (pInts.empty()){
        return nullptr;
    }
    //Ordena o vetor por meio da distancia do ponto da interseção e da posição do observador
    std::sort(pInts.begin(), pInts.end(), comparacaoDistancia);
    return pInts[0];
}

void Cenario::pintarObjeto(Ponto*** pGrade){
    auto *aux = new PontoIntersecao();
    bool auxDefinido = false;
    Vetor intensidadeFuro;
    for (int i = 0; i < camera->qtdFuros; ++i) {
        for (int j = 0; j < camera->qtdFuros; ++j) {
            for (auto &pObjeto : objetos) {
                if (!pObjeto->visibilidade) {
                    PontoIntersecao* pint = interceptaObjeto(pObjeto, camera->observador, pGrade[i][j]);
                    if(pint && (!auxDefinido || pint->distOrigem < aux->distOrigem)){
                        aux->distOrigem = pint->distOrigem;
                        aux->p = pint->p;
                        aux->objeto = pint->objeto;
                        auxDefinido = true;
                    }
                    // Desalocando a memoria
                    delete pint;
                }

            }
            if (auxDefinido) {
                intensidadeFuro = luzAmbiente->calcularIntensidadeAmbiente(aux);
                for (auto &l : luzes) {
                    intensidadeFuro += l->calcularIntensidadeDifusa(aux);
                    intensidadeFuro += l->calcularIntensidadeEspecular(aux);
                }

                imagem.setPixel(j,i,intensidadeFuro.x,intensidadeFuro.y,
                                intensidadeFuro.z);
            }
            else{
                imagem.setPixel(j,i,0.3,0.7,0.9);
            }
            auxDefinido = false;
        }
    }
}

float* Cenario::getCenarioData(){
    return imagem.getPixels();
}

void Cenario::imprimirCenarioCompleto() {
    PontoIntersecao intersecao;
//    for (int i = 0; i < camera->qtdFuros ; ++i) {
//        for (int j = 0; j < camera->qtdFuros; ++j) {
//            pInt = rayCasting(camera->observador, camera->gradeCamera[j][i]);
//            if(pInt){
//                pInt->objeto->visibilidade = true;
//            }
//        }
//    }
    pintarObjeto(camera->gradeCamera);
}

void Cenario::checarUmPonto(int linha, int coluna) {
    PontoIntersecao intersecao;
    cout << "----------------------------------------------------------------------" << "\n";
    cout << "Centro (" << linha << ", "<< coluna <<"): " << camera->gradeCamera[linha][coluna]->x << ", "
    << camera->gradeCamera[linha][coluna]->y<< ", "<< camera->gradeCamera[linha][coluna]->z << "\n";

    if(rayCasting(camera->observador, camera->gradeCamera[linha][coluna], intersecao)){
        //pInts->objeto->visibilidade = true;
        cout << "Objeto encontrado: " << intersecao.objeto->nome << " - Ponto Interceptado: " << intersecao.p->x
        << ", " <<intersecao.p->y<< ", "<< intersecao.p->z<< "\n";
        cout << "----------------------------------------------------------------------" << "\n";
        pintarObjeto(camera->gradeCamera);
    }

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

void Cenario::atualizarCamera() {
    for (auto objeto : objetos) {
        objeto->mudaCoodCamera(camera);
    }
    for (auto luz : luzes) {
        luz->mudaCoodCamera(camera);
    }
    imprimirCenarioCompleto();
}

bool Cenario::rayCasting(Ponto *pCoordObs, Ponto *pontoGrade, PontoIntersecao &intersecao) {
    Vetor vetorObGrade = biblioteca::SubtracaoPontos(*pCoordObs, *pontoGrade);

    Ponto* p_int1 = nullptr;
    Ponto* p_int2 = nullptr;

    bool bateu = false;

    for (auto &objeto : objetos) {
        if(!objeto->visibilidade) {
            tie(p_int1, p_int2) = objeto->IntersecaoReta(pCoordObs, vetorObGrade);
            if (p_int1) {
                if(!bateu) {
                    intersecao = PontoIntersecao(p_int1, objeto,
                        biblioteca::distanciaEntrePontos(pCoordObs, p_int1));
                    bateu = true;
                } else {
                    auto dist = biblioteca::distanciaEntrePontos(pCoordObs, p_int1);
                    if(dist < intersecao.distOrigem){
                        intersecao = PontoIntersecao(p_int1, objeto, dist);
                    }
                }
            }
            if (p_int2) {
                if(!bateu) {
                    intersecao = PontoIntersecao(p_int1, objeto,
                        biblioteca::distanciaEntrePontos(pCoordObs, p_int1));
                    bateu = true;
                } else {
                    auto dist = biblioteca::distanciaEntrePontos(pCoordObs, p_int1);
                    if(dist < intersecao.distOrigem){
                        intersecao = PontoIntersecao(p_int1, objeto, dist);
                    }
                }
            }
        }
    }
    return bateu;
}

