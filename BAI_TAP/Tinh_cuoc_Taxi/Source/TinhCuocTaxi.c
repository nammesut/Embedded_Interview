/** Tinh gia cuoc taxi:
 * Neu di <= 1km: 14000
 * Neu di <= 30km: 10000
 * Neu di > 30km: 8000
 */

#include "head.h"

int tinhCuocTaxi(int soKm){
    if(soKm <= 1){
        return 14000;
    }
    else if (soKm <= 30){
        return 14000 + (soKm-1)*10000;
    }
    else{
        return 14000 + 29*10000 + (soKm-30)*8000;
    }
    
}