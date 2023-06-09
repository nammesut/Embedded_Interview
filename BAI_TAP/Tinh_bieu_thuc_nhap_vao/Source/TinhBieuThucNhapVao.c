/** Tinh bieu thuc nhap vao la chuoi:
 * 2+3-(6*8) = ?
 * PT bac 1: 2x+5=0 => x = ?
 * PT bac 2: 2x^2+4x-6 = 0 => x1, x2 = ?  
 */
#include <stdio.h>
#include <string.h>
#include "head.h"

char arr[100];
int i = 0;

int check(){
  int n = 0;

  if(arr[i] == '('){
    i++;
    n = addsub();
    
    if(arr[i] == ')'){
      i++;
      return n;
    }
  }
  else{
    while('0' <= arr[i] && arr[i] <= '9'){
      n = (arr[i] - '0');
      i++;
    }
  }
  return n;
}

int muldiv(){
  int a,b;
  
  a = check();
  for(;;){
    if(arr[i] == '*'){
      i++;
      b = check();
      a *= b; 
    }else if(arr[i] == '/'){
      i++;
      b = check();
      a /= b;
    }else{
      return a;
    }
  }
}

int addsub(){
  int a,b;
  
  a = muldiv();
  
  for(;;){
    if(arr[i] == '+'){
      i++;
      b = muldiv();
      a += b; 
    }else if(arr[i] == '-'){
      i++;
      b = muldiv();
      a -= b;
    }else{
      return a;
    }
  }
  
}

int ptBacI(){
  int a,b;
  
  a = addsub();
  
  for(;;){
    if(arr[i] == 'x'){
      i++;
      if(arr[i] == '+'){
        i++;
        b = addsub();
        a = -(b/a); 
      }
      else if (arr[i] == '-'){
        i++;
        b = addsub();
        a = b/a; 
      } 
      printf("Bieu thuc nhap vao la PT bac 1: x = %d\n", a);
    }else{
      printf("%d\n", a);
      return a;
    }
  }
  
}
