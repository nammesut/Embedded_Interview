#include <stdio.h>
#include <stdint.h>

struct sizeofStruct1
{
    char a;
    int b;
    double c;
}str1;

struct sizeofStruct2
{
    uint32_t a[3];
    uint8_t b[4];
    uint16_t c[2];
}str2;

struct sizeofStruct3
{
    uint8_t a[3];
    uint32_t b[2];
    uint16_t c[2];
}str3;

union sizeofUnion1
{
    uint8_t a[5];
    uint8_t b[3];
}uni1;

union sizeofUnion2
{
    uint32_t a;
    uint8_t b[17];
    uint64_t c;
}uni2;

int main()
{
    printf("%lu \n", sizeof(str1));  
    printf("%lu \n", sizeof(str2));  
    printf("%lu \n", sizeof(str3));
    printf("%lu \n", sizeof(uni1)); 
    printf("%lu \n", sizeof(uni2)); 
}
