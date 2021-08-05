#include "kernelUtil.h"


extern "C" void _start(BootInfo* bootInfo){


    KernelInfo kernelInfo = InitializeKernel(bootInfo);
    PageTableManager* pageTableManager = kernelInfo.pageTableManager;

    BasicRenderer newRenderer(bootInfo->framebuffer, bootInfo->PSF1_Font);


    newRenderer.Print("Kernel Initialized!");
    
    for(int t= 0; t < 2000; t++){
        GlobalAllocator.RequestPage();
    }

    newRenderer.Print("Done");

    while(true);
}