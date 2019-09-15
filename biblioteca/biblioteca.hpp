#ifndef BIBLIOTECA_H
#define BIBLIOTECA_H
#include <iostream>
#include <string>
#include <tuple>
#include "Vetor.hpp"

using namespace std;

class Vetor;
struct Ponto;

class biblioteca{
    public:
        static double ProdutoEscalar(const Vetor &v1, const Vetor &v2);
        static double ProdutoEscalar(const Ponto &v1, const Vetor &v2);
        static Vetor ProdutoVetorial(const Vetor &v1, const Vetor &v2);
        static Vetor NormalizaVetor(const Vetor &vetor);
        static Vetor EncontrarNormal(const Vetor &vetor1, const Vetor &vetor2);
        static Ponto* EquacaoDaReta(const Ponto &p, const double &t, const Vetor &vetor);
        static Ponto* CriarPonto(double x, double y, double z);
        static double distanciaEntrePontos(Ponto* p1, Ponto* p2);
        static double distanciaEntrePontos(const Ponto &p1, const Ponto &p2);
        static Vetor SubtracaoPontos(const Ponto &p1, const Ponto &p2);
        static Ponto*** MatrixAllocation(int size);

    //TODO: Encontrar nome melhor pra essa função (solução da prova 1)
    static tuple<Ponto*, Ponto*> PontosDadoDistancia(Ponto* p_origem, const Vetor &v1, const Vetor &v2,
                                                     double l_comprimento);

};

#endif //BIBLIOTECA_H