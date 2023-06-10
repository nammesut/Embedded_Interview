#include <stdio.h>
#include <string.h>
#include "head.h"

extern char arr[100];
extern float ptBacI();

int main(){
  printf("Nhap bieu thuc: ");
  scanf("%s", arr);
  printf("%.1f\n", ptBacI());
  
  return 0;
  } 
