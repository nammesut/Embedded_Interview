#include <stdio.h>
#include <stdint.h>

uint8_t PORTA = 0b00010000;

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

typedef enum{
    HIGH, LOW
}pinStatus;


void pinHigh(pins pin)
{
    PORTA = PORTA | (0b10000000 >> pin); 
}

void pinLow(pins pin)
{
    PORTA = PORTA & ~(0b10000000 >> pin); 
}

void digitalWrite(pins pin, pinStatus status)
{
    if(HIGH == status)
        pinHigh(pin);   
    else
        pinLow(pin);
}

int main()
{
    
    readByte(PORTA);
    digitalWrite(PIN2, HIGH);
    readByte(PORTA);
    return 0;
}