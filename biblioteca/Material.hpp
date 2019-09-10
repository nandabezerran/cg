//
// Created by fbeze on 08/09/2019.
//

#ifndef COMPUTACAOGRAFICA_MATERIAIS_HPP
#define COMPUTACAOGRAFICA_MATERIAIS_HPP


class Material {
public:
    Material();
    Material(float pKa[3], float pKd[3], float pKs[3], double pm);
    double* getKa();
    double* getKd();
    double Ka[3];
    double Kd[3];
    double Ks[3];
    double m;
};


#endif //COMPUTACAOGRAFICA_MATERIAIS_HPP
