//
// Created by fbeze on 02/09/2019.
//

#ifndef COMPUTACAOGRAFICA_CENARIO_HPP
#define COMPUTACAOGRAFICA_CENARIO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include <vector>
#include "Camera.hpp"
#include "PontoIntersecao.hpp"
#include "../Bitmap/Bitmap.hpp"
#include "PontoIntersecao.hpp"
#include "Luz.hpp"
#include "LuzAmbiente.hpp"
#include "Matriz.hpp"


class Cenario {
public:
    Camera* camera;
    vector<Objeto*> objetos;
    Bitmap imagem;
    LuzAmbiente* luzAmbiente;
    vector<Luz*> luzes;

    Cenario(Camera* pCamera, vector<Objeto*> objetos, LuzAmbiente* pLuzAmb, vector<Luz*> pLuzes);

    bool rayCasting(Ponto* pCoordObs, Ponto* pontoGrade, PontoIntersecao &intersecao);
    void pintarObjeto(Ponto*** pGrade);
    void addObjeto(Objeto* objeto);
    void imprimirCenarioCompleto();
    PontoIntersecao* checarUmPonto(int linha, int coluna);
    void objetosVisiveis();
    void mudarCamera(Camera *pCamera);
    void gerarEspelho(int linha, int coluna);
    void atualizarCamera(int sentido);
    float* getCenarioData();
    void rotacaoPlanoArbitrario(Objeto *obj, float angulo, Ponto* p1, Ponto* p2);
private:
    void iniciarPintura();
    void iniciarCenario();

};


#endif //COMPUTACAOGRAFICA_CENARIO_HPP
