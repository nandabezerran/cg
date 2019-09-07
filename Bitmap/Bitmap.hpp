//
// Created by fbeze on 31/08/2019.
//

#ifndef COMPUTACAOGRAFICA_BITMAP_HPP
#define COMPUTACAOGRAFICA_BITMAP_HPP


#include <cstdint>
#include <string>
#include <memory>
using namespace std;
class Bitmap {
public:
    Bitmap(int largura, int altura);
    void setPixel(int x, int y, float red, float green, float blue);
    bool salvar(string nomeArquivo);
    float* getPixels();
private:
    int largura{0};
    int altura{0};
    float *pixels{nullptr};
};


#endif //COMPUTACAOGRAFICA_BITMAP_HPP
