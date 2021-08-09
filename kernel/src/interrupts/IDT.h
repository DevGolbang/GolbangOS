#pragma once
#include <stdint.h>

#define IDT_TA_InterruptGate    0b10001110
#define IDT_TA_CallGate         0b10001100
#define IDT_TA_TrapGate         0b10001111
//Interrupt Descriptor Table 인터럽트 서술자 테이블

struct IDTDescEntry{
    uint16_t offset0; // 오프셋 비트 0..15
    uint16_t selector; //GDT/LDT 상에서 코드있는 부분 골라주는(Select) 변수 
    uint8_t ist; //Interrupt Stack Table offset
    uint8_t type_attr;
    uint16_t offset1;// 오프셋 비트 16..31
    uint32_t offset2;// 오프셋 비트 32..63
    uint32_t ignore;
    void SetOffset(uint64_t offset);
    uint64_t GetOffset();
};

struct IDTR{
    uint16_t Limit;
    uint64_t Offset;
}__attribute__((packed));