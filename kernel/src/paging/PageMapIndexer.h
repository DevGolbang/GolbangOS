#pragma once
#include <stdint.h>

//virtualAddress Page구조에 맞는 주소에 변환시키기 위한 클래스
class PageMapIndexer{
    public:
    PageMapIndexer(uint64_t virtualAddress);
    uint64_t PDP_i;
    uint64_t PD_i;
    uint64_t PT_i;
    uint64_t P_i;
};