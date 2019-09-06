//
// Created by fbeze on 01/09/2019.
//

#include "Camera.hpp"

Camera::Camera(Ponto *pCoordCamera, Ponto *pLookAt, Ponto *pViewUp, double gradeTam, double distGrade, int pQtdFuros) :
coordCamera(pCoordCamera), lookAt(pLookAt), viewUp(pViewUp), qtdFuros(pQtdFuros) {

    observador = biblioteca::CriarPonto(0,0,0);
    int tamanho = 3;
    kc = biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(lookAt, coordCamera, tamanho),tamanho);
    ic = biblioteca::NormalizaVetor(biblioteca::ProdutoVetorial(biblioteca::SubtracaoPontos(coordCamera,viewUp,tamanho)
            ,kc,tamanho), tamanho);
    jc = biblioteca::ProdutoVetorial(kc,ic,tamanho);
    montarMatrizCoord();

    double pointDistance = gradeTam/(qtdFuros);
    double posX;
    double posY;
    double z = distGrade;

    gradeCamera = biblioteca::MatrixAllocation(qtdFuros);
    for(int column = 0; column < qtdFuros; ++column ){
        posX = gradeTam/2 - pointDistance - column*pointDistance;
        for (int row = 0; row < qtdFuros; ++row){
            posY = -gradeTam/2 + pointDistance + row*pointDistance;

            Ponto *p = biblioteca::CriarPonto(posX,posY,z);

            gradeCamera[row][column] = p;
        }
    }
}

void Camera::montarMatrizCoord() {
    cameraMundo[0][0] = ic[0];
    cameraMundo[0][2] = kc[0];
    cameraMundo[0][1] = jc[0];
    cameraMundo[0][3] = coordCamera->x;

    cameraMundo[1][0] = ic[1];
    cameraMundo[1][1] = jc[1];
    cameraMundo[1][2] = kc[1];
    cameraMundo[1][3] = coordCamera->y;

    cameraMundo[2][0] = ic[2];
    cameraMundo[2][1] = jc[2];
    cameraMundo[2][2] = kc[2];
    cameraMundo[2][3] = coordCamera->z;

    cameraMundo[3][0] = 0;
    cameraMundo[3][1] = 0;
    cameraMundo[3][2] = 0;
    cameraMundo[3][3] = 1;


    mundoCamera[0][0] = ic[0];
    mundoCamera[0][1] = ic[1];
    mundoCamera[0][2] = ic[2];
    mundoCamera[0][3] = - biblioteca::ProdutoEscalar(coordCamera, ic);

    mundoCamera[1][0] = jc[0];
    mundoCamera[1][1] = jc[1];
    mundoCamera[1][2] = jc[2];
    mundoCamera[1][3] = - biblioteca::ProdutoEscalar(coordCamera, jc);

    mundoCamera[2][0] = kc[0];
    mundoCamera[2][1] = kc[1];
    mundoCamera[2][2] = kc[2];
    mundoCamera[2][3] =  - biblioteca::ProdutoEscalar(coordCamera, kc);

    mundoCamera[3][0] = 0;
    mundoCamera[3][1] = 0;
    mundoCamera[3][2] = 0;
    mundoCamera[3][3] = 1;
}
VectorXd multMatrix(double matriz[4][4], VectorXd &vetor){
    VectorXd aux(4);
    for (int i = 0; i < 4 ; ++i) {
        aux[i] = 0;
        for (int j = 0; j < 4; ++j) {
            aux[i] += matriz[i][j] * vetor[j];
        }
    }
    return aux;
}

void Camera::mudarMundoCamera(Ponto *ponto) {
    VectorXd aux(4);
    aux << ponto->x, ponto->y, ponto->z, 1;
    aux = multMatrix(mundoCamera,aux);
    ponto->x = aux[0];
    ponto->y = aux[1];
    ponto->z = aux[2];
}

void Camera::mudarMundoCamera(VectorXd &pNormal) {
    VectorXd aux(4);
    aux << pNormal[0], pNormal[1], pNormal[2], 0;
    aux = multMatrix(mundoCamera,aux);
    pNormal[0] = aux[0];
    pNormal[1] = aux[1];
    pNormal[2] = aux[2];
}

void Camera::mudarCameraMundo(Ponto *ponto) {
    VectorXd aux(4);
    aux << ponto->x, ponto->y, ponto->z, 1;
    aux = multMatrix(cameraMundo,aux);
    ponto->x = aux[0];
    ponto->y = aux[1];
    ponto->z = aux[2];
}

void Camera::mudarCameraMundo(VectorXd &pNormal) {
    VectorXd aux(4);
    aux << pNormal[0], pNormal[1], pNormal[2], 0;
    aux = multMatrix(cameraMundo,aux);
    pNormal[0] = aux[0];
    pNormal[1] = aux[1];
    pNormal[2] = aux[2];
}