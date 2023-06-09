#include <stdio.h>
#include <string.h>
#include "head.h"

extern char arr[100];
extern int ptBacI();

int main(){
  printf("Nhap bieu thuc: ");
  scanf("%s", arr);

  ptBacI();  
  return 0;
  } 
