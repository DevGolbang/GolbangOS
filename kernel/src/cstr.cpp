#include "cstr.h"

char uintTo_StringOutput[128];
const char* to_string(uint64_t value) {
    uint8_t size = 0;
    uint64_t sizeTest = value;
    while (sizeTest / 10 > 0) {
        sizeTest /= 10;
        size++; 
    }
    //더많은 코드수정이 필요할듯 원본 코드가 기본적으로 노답임.

    uint8_t index = 0;
    while (value / 10 > 0) {
        uint8_t remainder = value % 10;
        value /= 10;
        uintTo_StringOutput[size - index] = remainder + '0';
        index++;
    }
    uint8_t remainder = value % 10;
    uintTo_StringOutput[0] = remainder + '0';
    uintTo_StringOutput[size + 1] = 0;
    return uintTo_StringOutput;
}
char hexTo_StringOutput64[128];
const char* to_hstring(uint64_t value){
    uint64_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t temp;
    uint8_t size = 15; //8 * 2 - 1;
    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput64[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : '0');
        temp = ((*ptr & 0x0F));
        hexTo_StringOutput64[size - (i * 2)] = temp + (temp > 9 ? 55 : '0');
    }
    hexTo_StringOutput64[size + 1]  = 0;
    return hexTo_StringOutput64;
}
char hexTo_StringOutput32[128];
const char* to_hstring(uint32_t value){
    uint32_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t temp;
    uint8_t size = 15; //8 * 2 - 1;
    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput32[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : '0');
        temp = ((*ptr & 0x0F));
        hexTo_StringOutput32[size - (i * 2)] = temp + (temp > 9 ? 55 : '0');
    }
    hexTo_StringOutput32[size + 1]  = 0;
    return hexTo_StringOutput32;
}
char hexTo_StringOutput16[128];
const char* to_hstring(uint16_t value){
    uint16_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t temp;
    uint8_t size = 15; //8 * 2 - 1;
    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput16[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : '0');
        temp = ((*ptr & 0x0F));
        hexTo_StringOutput16[size - (i * 2)] = temp + (temp > 9 ? 55 : '0');
    }
    hexTo_StringOutput16[size + 1]  = 0;
    return hexTo_StringOutput16;
}
char hexTo_StringOutput8[128];
const char* to_hstring(uint8_t value){
    uint8_t* valPtr = &value;
    uint8_t* ptr;
    uint8_t temp;
    uint8_t size = 15; //8 * 2 - 1;
    for(uint8_t i = 0; i < size; i++){
        ptr = ((uint8_t*)valPtr + i);
        temp = ((*ptr & 0xF0) >> 4);
        hexTo_StringOutput8[size - (i * 2 + 1)] = temp + (temp > 9 ? 55 : '0');
        temp = ((*ptr & 0x0F));
        hexTo_StringOutput8[size - (i * 2)] = temp + (temp > 9 ? 55 : '0');
    }
    hexTo_StringOutput8[size + 1]  = 0;
    return hexTo_StringOutput8;
}

char intTo_StringOutput[128];
const char* to_string(int64_t value) {

    uint8_t isNegative = 0;

    if(value < 0){
        isNegative = 1;
        value *= -1;
        intTo_StringOutput[0] = '-';
    }

    uint8_t size = 0;
    uint64_t sizeTest = value;
    while (sizeTest / 10 > 0) {
        sizeTest /= 10;
        size++; 
    }
    //더많은 코드수정이 필요할듯 원본 코드가 기본적으로 노답임.

    uint8_t index = 0;
    while (value / 10 > 0) {
        uint8_t remainder = value % 10;
        value /= 10;
        intTo_StringOutput[isNegative + size - index] = remainder + '0';
        index++;
    }
    uint8_t remainder = value % 10;
    intTo_StringOutput[isNegative] = remainder + '0';
    intTo_StringOutput[isNegative + size + 1] = 0;
    return intTo_StringOutput;
}

char doubleTo_StringOutput[128];
const char* to_string(double value, uint8_t decimalPlaces){
    char* intPtr = (char*)to_string((int64_t)value);
    char* doublePtr = doubleTo_StringOutput;

    if(value < 0){
        value *= -1;
    }
    while(*intPtr != 0){
        *doublePtr = *intPtr;
        intPtr++;
        doublePtr++;
    }

    *doublePtr = '.';
    doublePtr++;

    double newValue = value - (int)value;

    for(uint8_t i = 0; i < decimalPlaces; i++){
        newValue *= 10;
        *doublePtr = (int)newValue + '0';
        newValue -= (int)newValue;
        doublePtr++;
    }
    *doublePtr = 0;
    return doubleTo_StringOutput;
}
const char* to_string(double value){
    return to_string(value,2);
}