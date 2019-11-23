//
// Created by Celito on 2019-09-08.
//

#ifndef COMPUTACAOGRAFICA_VETOR_H
#define COMPUTACAOGRAFICA_VETOR_H


#include "biblioteca.hpp"

struct Ponto{
    double x;
    double y;
    double z;
};

class Vetor {
public:
    Vetor();
    Vetor(double pX, double pY, double pZ);

    double x;
    double y;
    double z;

    Vetor operator-() {
        return Vetor{-x, -y, -z};
    }

    void operator+=(const Vetor &v) {
        x += v.x;
        y += v.y;
        z += v.z;
    }
};

inline Vetor operator/(const Vetor& dividendo, const double &divisor) {
    return Vetor{dividendo.x/divisor, dividendo.y/divisor, dividendo.z/divisor};
}

inline Vetor operator-(const Ponto &p1, const Ponto &p2) {
    return Vetor(p2.x - p1.x, p2.y - p1.y, p2.z - p1.z);
}

inline Vetor operator-(const Vetor &v1, const Vetor &v2) {
    return Vetor(v1.x - v2.x, v1.y - v2.y, v1.z - v2.z);
}

inline Vetor operator*(const Vetor &v1, const double &mult) {
    return Vetor{v1.x * mult, v1.y * mult, v1.z * mult};
}

inline Vetor operator*( const double &mult, const Vetor &v1) {
    return v1 * mult;
}

inline Ponto operator+(const Ponto &p, const Vetor &v) {
    return Ponto{p.x + v.x, p.y + v.y, p.z + v.z};
}

#endif //COMPUTACAOGRAFICA_VETOR_H
