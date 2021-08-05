#pragma once
#include "paging.h"

//페이지 전체(PML4)관리 클래스
class PageTableManager{
    public:
    PageTableManager(PageTable* PML4Address);
    PageTable* PML4;
    void* MapMemory(void* virtualMemory, void* physicalMemory);
};