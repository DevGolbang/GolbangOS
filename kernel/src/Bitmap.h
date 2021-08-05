#pragma once
#include <stddef.h>
#include <stdint.h>

//PageTable 구성 위한 비트맵 정의
class Bitmap{
    public:
    size_t Size;
    uint8_t* Buffer;
    bool operator[](uint64_t index);
    bool Set(uint64_t index, bool value);

};
