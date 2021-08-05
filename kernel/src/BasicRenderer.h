#pragma once
#include "math.h"
#include "Framebuffer.h"
#include "SimpleFonts.h"

class BasicRenderer{
public:
    BasicRenderer(FrameBuffer* targetFramebuffer, PSF1_FONT* psf1_font);
    Point CursorPosition;
    FrameBuffer* TargetFramebuffer;
    PSF1_FONT* PSF1_Font;
    unsigned int Colour;
    void Print(const char* str);
    void PutChar(char chr, unsigned int xOff, unsigned yOff);
};