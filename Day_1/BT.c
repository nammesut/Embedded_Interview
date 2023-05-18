#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00100000;

void readByte(uint8_t byte)
{
    uint8_t temp;
    printf("0b");
    for(int i=0; i<8; i++)
    {
        temp = ((byte<<i) & 0b10000000)?1:0;
        printf("%d", temp); 
    }
    printf("\n");
}

typedef enum{
    PIN0, PIN1, PIN2, PIN3, PIN4, PIN5, PIN6, PIN7
}pins;


void pinHigh(pins pin)
{
    PORTA = PORTA | (0b10000000 >> pin); 
}

void pinLow(pins pin)
{
    PORTA = PORTA & ~(0b10000000 >> pin); 
}
int main()
{
    pinHigh(PIN7);
    readByte(PORTA);
    pinLow(PIN2);
    readByte(PORTA);
    return 0;
}