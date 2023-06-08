#include <stdio.h>
#include <string.h>
#include "head.h"

extern char arr[100];
extern int addsub();

int main(){
  printf("Nhap bieu thuc: ");
  scanf("%s", arr);

  printf("%d\n",addsub());  
  return 0;
  } 
