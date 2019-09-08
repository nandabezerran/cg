
#include "LuzAmbiente.hpp"

LuzAmbiente::LuzAmbiente(float r, float g, float b, double x, double y, double z): Luz(r, g, b){
    posicaoAmbiente = new Ponto();
    posicaoAmbiente->x = x;
    posicaoAmbiente->y = y;
    posicaoAmbiente->z = z;
}