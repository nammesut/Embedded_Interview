#include <stdio.h>

/*Macro*/
#define MAX 10
#define SUM(a, b) (a+b)

/*Inline*/
inline int MIN(int a, int b){
    return (a<b)?a:b;
}

int main(){
    printf("Max: %d\n", MAX);
    printf("Tong a + b = %d\n", SUM(5, 4));
    printf("Min a, b: %d\n", MIN(4, 6));
    return 0;
}