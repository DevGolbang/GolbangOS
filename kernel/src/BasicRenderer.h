#pragma once
#include "math.h"
#include "Framebuffer.h"
#include "SimpleFonts.h"
#include <stdint.h>

class BasicRenderer{
public:
    BasicRenderer(FrameBuffer* targetFramebuffer, PSF1_FONT* psf1_font);
    Point CursorPosition;
    FrameBuffer* TargetFramebuffer;
    PSF1_FONT* PSF1_Font;
    unsigned int Colour;
    void Print(const char* str);
    void PrintLine(const char* str);
    void PutChar(char chr, unsigned int xOff, unsigned yOff);
    void PutChar(char chr);
    void Clear(uint32_t colour);
    void Next();
};

extern BasicRenderer* GlobalRenderer;