#include <utility>
#include <c++/algorithm>
#include <cmath>

//
// Created by fbeze on 02/09/2019.
//

#include "Cenario.hpp"
#include "Plano.hpp"

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
                    if(l->estado) {
                        intensidadeFuro += l->calcularIntensidadeDifusa(aux);
                        intensidadeFuro += l->calcularIntensidadeEspecular(aux);
                    }
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

PontoIntersecao* Cenario::checarUmPonto(int linha, int coluna) {
    auto *intersecao = new PontoIntersecao();
    cout << "----------------------------------------------------------------------" << "\n";
    cout << "Centro (" << linha << ", "<< coluna <<"): " << camera->gradeCamera[linha][coluna]->x << ", "
    << camera->gradeCamera[linha][coluna]->y<< ", "<< camera->gradeCamera[linha][coluna]->z << "\n";

    if(rayCasting(camera->observador, camera->gradeCamera[linha][coluna], *intersecao)){
        //pInts->objeto->visibilidade = true;
        cout << "Objeto encontrado: " << intersecao->objeto->nome << " - Ponto Interceptado: " << intersecao->p->x
        << ", " <<intersecao->p->y<< ", "<< intersecao->p->z<< "\n";
        cout << "----------------------------------------------------------------------" << "\n";
        pintarObjeto(camera->gradeCamera);
        return intersecao;
    }
    return nullptr;
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
    for (auto objeto : objetos) {
        objeto->mudaCoodMundo(camera);
    }
    camera = pCamera;
    for(auto objeto : objetos){
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
                    intersecao = PontoIntersecao(p_int2, objeto,
                        biblioteca::distanciaEntrePontos(pCoordObs, p_int2));
                    bateu = true;
                } else {
                    auto dist = biblioteca::distanciaEntrePontos(pCoordObs, p_int2);
                    if(dist < intersecao.distOrigem){
                        intersecao = PontoIntersecao(p_int2, objeto, dist);
                    }
                }
            }
        }
    }
    return bateu;
}

void Cenario::gerarEspelho(int linha, int coluna) {
    PontoIntersecao intersecao;
    Matriz espelhamento = Matriz(4,4, 0);
    Matriz translacao = Matriz(4, 4, 0);
    Matriz translacao2 = Matriz(4, 4, 0);
    Vetor normal;
    if(rayCasting(camera->observador, camera->gradeCamera[linha][coluna], intersecao)) {
        normal = intersecao.objeto->calcularNormal(intersecao.p);
        translacao(0, 3) = -intersecao.p->x;
        translacao(1, 3) = -intersecao.p->y;
        translacao(2, 3) = -intersecao.p->z;

        translacao2(0, 3) = intersecao.p->x;
        translacao2(1, 3) = intersecao.p->y;
        translacao2(2, 3) = intersecao.p->z;

        espelhamento(0, 0) = 1 - (2 * normal.x * normal.x);
        espelhamento(0, 1) = -2 * normal.x * normal.y;
        espelhamento(0, 2) = -2 * normal.x * normal.z;

        espelhamento(1, 0) = -2 * normal.y * normal.x;
        espelhamento(1, 1) = 1 - 2 * normal.y * normal.y;
        espelhamento(1, 2) = -2 * normal.y * normal.z;

        espelhamento(2, 0) = -2 * normal.z * normal.x;
        espelhamento(2, 1) = -2 * normal.z * normal.y;
        espelhamento(2, 2) = 1 - 2 * normal.z * normal.z;

        vector<Matriz> transf;
        transf.push_back(translacao);
        transf.push_back(espelhamento);
        transf.push_back(translacao2);
        int tam = objetos.size();
        for (int i = 0; i < tam; ++i) {
            if (biblioteca::distanciaPontoPlano(normal, *intersecao.p, *objetos[i]->getCentro())) {
                objetos.push_back(objetos[i]->aplicarEspelhamento(transf));
            }
        }
    }
    imprimirCenarioCompleto();
}

void Cenario::rotacaoPlanoArbitrario(Objeto *obj, float angulo, Ponto* p1, Ponto* p2){
    Vetor planoArbitrario = biblioteca::SubtracaoPontos(*p1,*p2);
    Vetor vq = sin(angulo/2) * biblioteca::NormalizaVetor(planoArbitrario);
    double wq = cos(angulo/2);
    Matriz Mteta = Matriz(4,4,0);
    Matriz translacao = Matriz(4, 4, 0);
    Matriz translacao2 = Matriz(4, 4, 0);

    Mteta(0,0) = pow(wq,2) + pow(vq.x,2) - pow(vq.y,2) - pow(vq.z,2);
    Mteta(1,0) = 2*vq.x*vq.y - 2*wq*vq.z;
    Mteta(2,0) = 2*wq*vq.y + 2*vq.x*vq.z;
    Mteta(3,0) = 0;

    Mteta(0,1) = 2*vq.x*vq.y + 2*wq*vq.z;
    Mteta(1,1) = pow(wq,2) - pow(vq.x,2) + pow(vq.y,2) - pow(vq.z,2);
    Mteta(2,1) = -2*wq*vq.x+2*vq.y*vq.z;
    Mteta(3,1) = 0;

    Mteta(0,2) = -2*wq*vq.y + 2*vq.x*vq.z;
    Mteta(1,2) = 2*wq*vq.x + 2*vq.y*vq.z;
    Mteta(2,2) = pow(wq,2) - pow(vq.x,2) - pow(vq.y,2) + pow(vq.z,2);
    Mteta(3,2) = 0;

    Mteta(0,3) = 0; Mteta(1,3) = 0; Mteta(2,3) = 0; Mteta(3,3) = 1;

    translacao(0, 3) = -p1->x;
    translacao(1, 3) = -p1->y;
    translacao(2, 3) = -p1->z;

    translacao2(0, 3) = p1->x;
    translacao2(1, 3) = p1->y;
    translacao2(2, 3) = p1->z;

    vector<Matriz> transf;
    transf.push_back(translacao);
    transf.push_back(Mteta);
    transf.push_back(translacao2);
    obj->aplicarTransformacao(transf);


}
