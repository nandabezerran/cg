//
// Created by fbeze on 26/08/2019.
//

#include "Objeto.hpp"

Objeto::Objeto(const string& pNome, int r, int g, int b, bool pVisibilidade) : nome(pNome),
                                                    visibilidade(pVisibilidade){
    rgb[0] = r;
    rgb[1] = g;
    rgb[2] = b;

}


