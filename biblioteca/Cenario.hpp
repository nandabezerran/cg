//
// Created by fbeze on 02/09/2019.
//

#ifndef COMPUTACAOGRAFICA_CENARIO_HPP
#define COMPUTACAOGRAFICA_CENARIO_HPP
#include "biblioteca.hpp"
#include "Objeto.hpp"
#include <vector>
#include "Camera.hpp"
#include "../Bitmap/Bitmap.hpp"

/// Struct para salvar os pontos de interseção, nela temos o ponto o objeto e a distancia da interseção pra origem
struct pontoIntersecao{
    Ponto *p;
    Objeto *objeto;
    double distOrigem;

};

class Cenario {
public:
    Camera* camera;
    vector<Objeto*> objetos;
    Bitmap imagem;

    Cenario(Camera* pCamera);
    vector<pontoIntersecao*> rayCasting(VectorXd raioObGrade);
    colour** pintarObjeto(Ponto*** pGrade);
    void addObjeto(Objeto* objeto);
    void imprimirCenario(colour **matrix);

};


#endif //COMPUTACAOGRAFICA_CENARIO_HPP
