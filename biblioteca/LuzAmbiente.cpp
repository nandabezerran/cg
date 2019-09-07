
#include "LuzAmbiente.hpp"

LuzAmbiente::LuzAmbiente(int r, int g, int b, int x, int y, int z): Luz(r, g, b){
    posicaoAmbiente = new Ponto();
    posicaoAmbiente->x = x;
    posicaoAmbiente->y = y;
    posicaoAmbiente->z = z;
}