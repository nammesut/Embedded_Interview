#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

int main(){
    /*Bien local luu trong Stack*/
    int a = 10;

    /*Bien con tro duoc cap phat dong luu trong Heap*/
    uint8_t *ptr = (uint8_t *)malloc(sizeof(uint8_t)*5);
    return 0;
}