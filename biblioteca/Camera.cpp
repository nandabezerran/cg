//
// Created by fbeze on 01/09/2019.
//

#include "Camera.hpp"

Camera::Camera(Ponto *pCoordCamera, Ponto *pLookAt, Ponto *pViewUp, double gradeTam, double distGrade, int pQtdFuros) :
coordCamera(pCoordCamera), lookAt(pLookAt), viewUp(pViewUp), qtdFuros(pQtdFuros) {
    observador = biblioteca::CriarPonto(0,0,0);
    kc = biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*lookAt, *coordCamera));
    ic = biblioteca::NormalizaVetor(biblioteca::ProdutoVetorial(
        biblioteca::SubtracaoPontos(*coordCamera, *viewUp),kc));
    jc = biblioteca::ProdutoVetorial(kc,ic);
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
    cameraMundo[0][0] = ic.x;
    cameraMundo[0][2] = kc.x;
    cameraMundo[0][1] = jc.x;
    cameraMundo[0][3] = coordCamera->x;

    cameraMundo[1][0] = ic.y;
    cameraMundo[1][1] = jc.y;
    cameraMundo[1][2] = kc.y;
    cameraMundo[1][3] = coordCamera->y;

    cameraMundo[2][0] = ic.z;
    cameraMundo[2][1] = jc.z;
    cameraMundo[2][2] = kc.z;
    cameraMundo[2][3] = coordCamera->z;

    cameraMundo[3][0] = 0;
    cameraMundo[3][1] = 0;
    cameraMundo[3][2] = 0;
    cameraMundo[3][3] = 1;


    mundoCamera[0][0] = ic.x;
    mundoCamera[0][1] = ic.y;
    mundoCamera[0][2] = ic.z;
    mundoCamera[0][3] = - biblioteca::ProdutoEscalar(*coordCamera, ic);

    mundoCamera[1][0] = jc.x;
    mundoCamera[1][1] = jc.y;
    mundoCamera[1][2] = jc.z;
    mundoCamera[1][3] = - biblioteca::ProdutoEscalar(*coordCamera, jc);

    mundoCamera[2][0] = kc.x;
    mundoCamera[2][1] = kc.y;
    mundoCamera[2][2] = kc.z;
    mundoCamera[2][3] = - biblioteca::ProdutoEscalar(*coordCamera, kc);

    mundoCamera[3][0] = 0;
    mundoCamera[3][1] = 0;
    mundoCamera[3][2] = 0;
    mundoCamera[3][3] = 1;
}

template<std::size_t S>
void multMatriz(const double matriz [S][S], const double vetor [S], double (&result)[S]) {
    for (int i = 0; i < S ; ++i) {
        result[i] = 0;
        for (int j = 0; j < S; ++j) {
            result[i] += matriz[i][j] * vetor[j];
        }
    }
}

void Camera::atualizaCamera(){
    kc = biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*lookAt, *coordCamera));
    ic = biblioteca::NormalizaVetor(biblioteca::ProdutoVetorial(
        biblioteca::SubtracaoPontos(*coordCamera,*viewUp), kc));
    jc = biblioteca::ProdutoVetorial(kc,ic);
    montarMatrizCoord();
}

void Camera::mudarMundoCamera(Ponto *ponto) {
    double result[4];
    double aux[4] = {ponto->x, ponto->y, ponto->z, 1};
    multMatriz<4>(mundoCamera, aux, result);
    ponto->x = result[0];
    ponto->y = result[1];
    ponto->z = result[2];
}

void Camera::mudarMundoCamera(Vetor &v) {
    double result[4];
    double vetorExt[4] = {v.x, v.y, v.z, 0};
    multMatriz<4>(mundoCamera, vetorExt, result);
    v.x = result[0];
    v.y = result[1];
    v.z = result[2];
}

void Camera::mudarCameraMundo(Ponto *ponto) {
    double result[4];
    double aux[4] = {ponto->x, ponto->y, ponto->z, 1};
    multMatriz<4>(cameraMundo,aux, result);
    ponto->x = result[0];
    ponto->y = result[1];
    ponto->z = result[2];
}

void Camera::mudarCameraMundo(Vetor &vetor) {
    double result[4];
    double vetorExt[4] = {vetor.x, vetor.y, vetor.z, 0};
    multMatriz<4>(cameraMundo, vetorExt, result);
    vetor.x = result[0];
    vetor.y = result[1];
    vetor.z = result[2];
}

void Camera::andarFrente() {
    coordCamera = biblioteca::EquacaoDaReta(*coordCamera, 3,
            biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*coordCamera, *lookAt)));
    atualizaCamera();
}

void Camera::andarTras() {
    coordCamera = biblioteca::EquacaoDaReta(*coordCamera, -3,
            biblioteca::NormalizaVetor(biblioteca::SubtracaoPontos(*coordCamera, *lookAt)));
    atualizaCamera();
}

