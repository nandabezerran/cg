//
// Created by fbeze on 01/09/2019.
//

#ifndef COMPUTACAOGRAFICA_CAMERA_HPP
#define COMPUTACAOGRAFICA_CAMERA_HPP
#include "biblioteca.hpp"

class Camera {
public:
    Ponto* coordCamera;
    Ponto* lookAt;
    Ponto* viewUp;
    Ponto* observador;
    Vetor ic;
    Vetor jc;
    Vetor kc;
    double cameraMundo[4][4];
    double mundoCamera[4][4];
    Ponto*** gradeCamera;
    int qtdFuros;

    Camera(Ponto* pCoordCamera, Ponto* pLookAt, Ponto* pViewUp, double gradeTam, double distGrade, int pQtdFuros);
    void montarMatrizCoord();
    void mudarMundoCamera(Ponto *ponto);
    void mudarCameraMundo(Ponto *ponto);
    void mudarMundoCamera(Vetor &v);
    void mudarCameraMundo(Vetor &vetor);
    void atualizaCamera();
    void andarFrente();
    void andarTras();


};


#endif //COMPUTACAOGRAFICA_CAMERA_HPP
