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

float check(){
    float n = 1;

    if(arr[i] == '('){
        i++;
        n = ptBacI();
        
        if(arr[i] == ')'){
            i++;
            return n;
        }
    }
    else{
        
        while('0' <= arr[i] && arr[i] <= '9'){
            n = arr[i] - '0';
            i++;
        }
    }
    return n;
}

float ptBacI(){
    float a, b, c;
    
    a = check();
    
    while(1){
        if(arr[i] == '*'){
            i++;
            b = check();
            a *= b; 
        }
        else if(arr[i] == '/'){
            i++;
            b = check();
            a /= b;
        }

        else if(arr[i] == 'x'){
            i++;
            // if(arr[i] == '^'){
            //     i += 2;
            //     if(arr[i] == '+'){
            //         i++;
            //         b = check();
            //         if(arr[i] == 'x'){
            //             i++;
            //             c = check();
            //         }
            //     }

            // }

            if(arr[i] == '+'){
                i++;
                b = check();
                a = -(b/a); 
            }
            else if (arr[i] == '-'){
                i++;
                b = check();
                a = b/a; 
            } 
            printf("Bieu thuc nhap vao la PT bac 1: x = ");
        }

        else if(arr[i] == '+'){
            i++;

            if(arr[i] == 'x'){
                b = check();
                i++;
                printf("Bieu thuc nhap vao la PT bac 1: x = ");
                a = -(a/b);
            }
            else if((arr[i] != 'x') && (arr[i+1] == 'x')){
                b = check();
                i++;
                printf("Bieu thuc nhap vao la PT bac 1: x = ");
                a = -(a/b);
            }
            else{
                b = check();
                a += b;
            } 
        }

        else if(arr[i] == '-'){
            i++;

            if(arr[i] == 'x'){
                b = check();
                i++;
                printf("Bieu thuc nhap vao la PT bac 1: x = ");
                a = a/b;
            }
            else if((arr[i] != 'x') && (arr[i+1] == 'x')){
                b = check();
                i++;
                printf("Bieu thuc nhap vao la PT bac 1: x = ");
                a = a/b;
            }
            else{
                b = check();
                a -= b;
            }
        }

        else
            return a;
    }
}

// int main(){
//   printf("%.1f\n", ptBacI());
//   return 0;
// }

// int muldiv(){
//   int a,b;
  
//   a = check();
//   for(;;){
//     if(arr[i] == '*'){
//       i++;
//       b = check();
//       a *= b; 
//     }else if(arr[i] == '/'){
//       i++;
//       b = check();
//       a /= b;
//     }else{
//       return a;
//     }
//   }
// }

// int addsub(){
//   int a,b;
  
//   a = muldiv();
  
//   for(;;){
//     if(arr[i] == '+'){
//       i++;
//       b = muldiv();
//       a += b; 
//     }else if(arr[i] == '-'){
//       i++;
//       b = muldiv();
//       a -= b;
//     }else{
//       return a;
//     }
//   }
  
// }