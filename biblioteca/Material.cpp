//
// Created by fbeze on 08/09/2019.
//

#include "Material.hpp"

Material::Material() = default;

Material::Material(float *pKa, float *pKd, float *pKs, double pm) : m(pm) {
    Ka[0] = pKa[0];
    Ka[1] = pKa[1];
    Ka[2] = pKa[1];

    Kd[0] = pKd[0];
    Kd[1] = pKd[1];
    Kd[2] = pKd[1];

    Ks[0] = pKs[0];
    Ks[1] = pKs[1];
    Ks[2] = pKs[1];
}

double* Material::getKa() {
    return Ka;
}

double* Material::getKd() {
    return Kd;
}
