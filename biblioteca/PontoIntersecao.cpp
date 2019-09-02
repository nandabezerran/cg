//
// Created by fbeze on 02/09/2019.
//

#include "PontoIntersecao.hpp"
PontoIntersecao::PontoIntersecao(Ponto* pP, Objeto *pObjeto, double pDistOrigem) : p(pP), objeto(pObjeto),
distOrigem(pDistOrigem){}

PontoIntersecao::PontoIntersecao() = default;;