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
    void checarUmPonto(int linha, int coluna);
    void objetosVisiveis();
    void mudarCamera(Camera *pCamera);
    void atualizarCamera();
    float* getCenarioData();
private:
    void iniciarPintura();
    void iniciarCenario();
    void terminarCenario();
};


#endif //COMPUTACAOGRAFICA_CENARIO_HPP
