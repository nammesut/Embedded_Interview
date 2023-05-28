#include <stdio.h>

/*Macro*/
#define MAX 10
#define SUM(a, b) (a+b)

/*Macro function*/
#define CREATE_FUNC(name, contents)      \
void name(){                             \
    printf("%s\n", contents);            \
}

CREATE_FUNC(test, "This is test\n");

/*Inline*/
inline int MIN(int a, int b){
    return (a<b)?a:b;
}

int main(){
    printf("Max: %d\n", MAX);
    printf("Tong a + b = %d\n", SUM(5, 4));
    printf("Min a, b: %d\n", MIN(4, 6));

    test();
    return 0;
}