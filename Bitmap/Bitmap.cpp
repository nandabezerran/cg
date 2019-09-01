//
// Created by fbeze on 31/08/2019.
//

#include "Bitmap.hpp"
#include "BitmapCabecalhoArq.h"
#include "BitmapCabecalhoInfo.h"
#include <iostream>
#include <fstream>

Bitmap::Bitmap(int largura, int altura) : largura(largura), altura(altura), pixels(new uint8_t[altura*largura*3]()){}

void Bitmap::setPixel(int x, int y, uint8_t red, uint8_t green, uint8_t blue) {
    uint8_t *aux = pixels;
    aux+=(y*3)*largura+(x*3);
    aux[0] = red;
    aux[1] = green;
    aux[2] = blue;
}

bool Bitmap::salvar(string nomeArquivo) {
    BitmapCabecalhoInfo cabecalhoInfo;
    char b = 'B';
    char m = 'M';
    int filesize = sizeof(BitmapCabecalhoArq) + sizeof(BitmapCabecalhoInfo) + (altura*largura*3);
    int reserved = 0;
    int dataOffset = sizeof(BitmapCabecalhoArq) + sizeof(BitmapCabecalhoInfo);
    cabecalhoInfo.height = altura;
    cabecalhoInfo.width = largura;

    FILE* arquivo;
    arquivo = fopen(nomeArquivo.c_str(), "wb");

    if(!arquivo){
        return false;
    }

    fwrite((const void*)&b, sizeof(char), 1, arquivo);
    fwrite((const void*)&m, sizeof(char), 1, arquivo);
    fwrite((const void*)&filesize, sizeof(int), 1, arquivo);
    fwrite((const void*)&reserved, sizeof(int), 1, arquivo);
    fwrite((const void*)&dataOffset, sizeof(int), 1, arquivo);

    fwrite((const void*)&cabecalhoInfo, sizeof(BitmapCabecalhoInfo), 1, arquivo);
    fwrite((const void*)pixels, (size_t)altura*largura*3, 1, arquivo);

    fclose(arquivo);

    return true;
}
