//
// Created by 安博 on 2019/9/3.
//

#ifndef UTILS_CRC32C_H
#define UTILS_CRC32C_H

#include <stdint.h>
#include <stddef.h>

namespace  crc32c{

    uint32_t Extend(uint32_t init_crc, const char* data, size_t n);

    inline uint32_t Value(const char* data, size_t n){return Extend(0, data, n);}

    static const uint32_t kMaskDelta = 0xa282ead8ul;

    inline uint32_t Mask(uint32_t crc){
        return ((crc >> 15) | (crc << 17)) + kMaskDelta;
    }

    inline uint32_t Unmask(uint32_t masked_crc){
        uint32_t rot = masked_crc - kMaskDelta;
        return ((rot >> 17) | (rot << 15));
    }


}

#endif //UTILS_CRC32C_H
