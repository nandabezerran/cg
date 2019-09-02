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
    vector<PontoIntersecao*> rayCasting(Ponto* pCoordCamera, Ponto* pontoGrade);
    colour** pintarObjeto(Ponto*** pGrade);
    void addObjeto(Objeto* objeto);
    void imprimirCenario(colour **matrix);

};


#endif //COMPUTACAOGRAFICA_CENARIO_HPP
