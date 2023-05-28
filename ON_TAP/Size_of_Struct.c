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

int main()
{
    printf("%lu \n", sizeof(str3));  
}
