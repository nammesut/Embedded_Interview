#include <stdio.h>
#include <stdint.h>

void readByte(uint8_t byte)
{
    uint8_t temp;
    printf("0b");
    for(int i=0; i<8; i++)
    {
        temp = ((byte<<i) & 0b10000000)?1:0;
        printf("%d", temp);   
    }
}

int main()
{
    uint8_t test = 2;

    readByte(test);
    return 0;
}