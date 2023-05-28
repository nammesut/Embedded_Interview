#include <stdio.h>
#include <stdint.h>

union sizeofUnion
{
    uint32_t x;
    uint8_t s[16];
    uint64_t f;
}uni;

int main()
{
    printf("%lu \n", sizeof(uni));
}
