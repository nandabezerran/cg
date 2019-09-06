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

class Cenario {
public:
    Camera* camera;
    vector<Objeto*> objetos;
    Bitmap imagem;


    Cenario(Camera* pCamera, vector<Objeto*> objetos);

    vector<PontoIntersecao*> rayCasting(Ponto* pCoordObs, Ponto* pontoGrade);
    void pintarObjeto(Ponto*** pGrade);
    void addObjeto(Objeto* objeto);
    void salvarCenario();
    void imprimirCenarioCompleto();
    void checarUmPonto(int linha, int coluna);
    void objetosVisiveis();
    void mudarCamera(Camera *pCamera);
private:
    void iniciarPintura();
    void iniciarCenario();
    void terminarCenario();
};


#endif //COMPUTACAOGRAFICA_CENARIO_HPP
