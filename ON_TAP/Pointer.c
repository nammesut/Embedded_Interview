#include <stdio.h>
#include <string.h>

void tong(int a, int b){
    printf("%d\n", a+b);
}

void tinhtoan(int a, int b, void (*ptr)(int, int)){
    ptr(a, b);
}

int main()
{
    /*Con trỏ hàm*/
    void (*ptr)(int, int) = NULL; 
    ptr = &tong;
    ptr(5, 6);

    tinhtoan(7, 10, tong);

    /*Khai báo con trỏ void*/
    int a = 10;
    double b = 1.2;

    void *ptr_void = &a;
    printf("%d\n", *(int *)ptr);

    ptr_void = &b;
    printf("%f\n", *(double *)ptr_void);

    ptr_void = &tong;
    ((void (*)(int, int))ptr_void)(12, 10);
}
