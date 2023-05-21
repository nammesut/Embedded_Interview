#include <stdio.h>
#include <stdint.h>

struct sizeofStruct
{
    uint8_t a[3];
    uint32_t b[2];
    uint16_t c[2];
}str;

int main()
{
    printf("%lu \n", sizeof(str));
}
