//
// Created by fbeze on 31/08/2019.
//

#ifndef COMPUTACAOGRAFICA_BITMAPCABECALHOINFO_H
#define COMPUTACAOGRAFICA_BITMAPCABECALHOINFO_H

#include <cstdint>
#pragma pack(2)
struct BitmapCabecalhoInfo{
    int32_t headerSize{40};
    int32_t width;
    int32_t height;
    int16_t planes{1};
    int16_t bitPerPixel{24};
    int32_t compression{0};
    int32_t dataSize{0};
    int32_t horizontalRes{2400};
    int32_t verticalRes{2400};
    int32_t colors{0};
    int32_t importantColors{0};
};
#endif //COMPUTACAOGRAFICA_BITMAPCABECALHOINFO_H
