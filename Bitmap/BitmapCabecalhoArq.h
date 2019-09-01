//
// Created by fbeze on 31/08/2019.
//

#ifndef COMPUTACAOGRAFICA_BITMAPCABECALHOARQ_H
#define COMPUTACAOGRAFICA_BITMAPCABECALHOARQ_H

#include <cstdint>

#pragma pack(2)
struct BitmapCabecalhoArq{
    char header[2]{'B','M'};
    uint32_t filesize;
    uint32_t reserved{0};
    uint32_t dataOffset;
};
#endif //COMPUTACAOGRAFICA_BITMAPCABECALHOARQ_H
