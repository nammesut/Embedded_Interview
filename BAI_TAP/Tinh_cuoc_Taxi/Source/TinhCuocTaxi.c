#include "head.h"

int tinhCuocTaxi(int n){
    if(n <= 1){
        return 14000;
    }
    else if (n <= 30){
        return 14000 + (n-1)*10000;
    }
    else{
        return 14000 + 29*10000 + (n-30)*8000;
    }
    
}