#include <c++/cmath>
#include "biblioteca.hpp"

double biblioteca::ProdutoEscalar(const Vetor &v1, const Vetor &v2) {
    return v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
}

double biblioteca::ProdutoEscalar(const Ponto &p, const Vetor &v) {
    return p.x * v.x + p.y * v.y + p.z * v.z;
}

Vetor biblioteca::ProdutoVetorial(const Vetor &v1, const Vetor &v2)
{
    return {v1.y * v2.z - v1.z * v2.y, v1.z * v2.x - v1.x * v2.z, v1.x * v2.y - v1.y * v2.x};
}

Vetor biblioteca::NormalizaVetor(const Vetor &vetor) {
    return vetor/sqrt(ProdutoEscalar(vetor,vetor));
}

Vetor biblioteca::EncontrarNormal(const Vetor &vetor1, const Vetor &vetor2){
    Vetor vetor_normal;
    vetor_normal = ProdutoVetorial(vetor1, vetor2);
    vetor_normal = NormalizaVetor(vetor_normal);
    return vetor_normal;
}

double biblioteca::distanciaEntrePontos(Ponto *p1, Ponto *p2) {
    return sqrt(pow((p2->x - p1->x),2) + pow((p2->y - p1->y),2) + pow((p2->z - p1->z),2));
}

double biblioteca::distanciaEntrePontos(const Ponto &p1, const Ponto &p2) {
    return sqrt(pow((p2.x - p1.x),2) + pow((p2.y - p1.y),2) + pow((p2.z - p1.z),2));
}

Vetor biblioteca::SubtracaoPontos(const Ponto &p1, const Ponto &p2) {
    return Vetor{p2.x - p1.x, p2.y - p1.y, p2.z - p1.z};
}

Ponto*** biblioteca::MatrixAllocation(int size){
    auto ***matrix = new Ponto**[size];

    for (int i = 0; i < size; i++){
        matrix[i] = new Ponto*[size];
    }
    return matrix;
}

Ponto* biblioteca::EquacaoDaReta(const Ponto &p, const double &t,const Vetor &vetor){
    return new Ponto{p.x + t * vetor.x, p.y + t * vetor.y, p.z + t * vetor.z};
}

Ponto* biblioteca::CriarPonto(double x, double y, double z) {
    Ponto* p = new Ponto;
    p->x = x;
    p->y = y;
    p->z = z;
    return p;
}

tuple<Ponto*, Ponto*> biblioteca::PontosDadoDistancia(Ponto* p_origem, const Vetor &v1, const Vetor &v2,
    double l_comprimento){
    double s, t;
    Ponto* p1;
    Ponto* p2;

    s = pow(l_comprimento, 2);
    s = s/((ProdutoEscalar(v2,v2)) -
           (pow(ProdutoEscalar(v1,v2),2)/ProdutoEscalar(v1,v1)));
    s = sqrt(s);

    t = ProdutoEscalar(v1,v2)/ProdutoEscalar(v1,v1);
    t = t * s;

    p1 = EquacaoDaReta(*p_origem, t, v1);
    p2 = EquacaoDaReta(*p_origem, s, v2);

    return make_tuple(p1,p2);

}

bool biblioteca::distanciaPontoPlano(Vetor &pNormal, Ponto &pPi, Ponto &pObj) {
    return biblioteca::ProdutoEscalar(pObj,pNormal) + ((- (pNormal.x*pPi.x) - (pNormal.y*pPi.y) - (pNormal.z*pPi.z))/
           sqrt(pow(pNormal.x,2) + pow(pNormal.y,2) +pow(pNormal.z,2))) > 0;
}

