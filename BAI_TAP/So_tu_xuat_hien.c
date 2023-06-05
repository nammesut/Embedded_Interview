#include <stdio.h>
#include <stdint.h>

int sizeArr(uint8_t arr[]){
    uint8_t size, count=0, i=0;
    while(arr[i++] != '\0')
        count++;
    return count;
}

int main(){
    char arr[] = "Mot hai ba hai";
    char kq[] = "";
    
    int i, j=0, count=0;
    int x=0, y=0, flag=1;
    
    int size, size_kq;
    size = sizeArr(arr);

    for(i=0; i<=size; i++){
        if((arr[i] == ' ') || (arr[i] == '\0')){
            kq[j] = '\0';
            j=0;
            i++;
            size_kq = sizeArr(kq);
            
            printf("%s\n", kq);
            while(arr[x] != '\0'){
                if(arr[x] == kq[y]){
                    y++;
                    if(kq[y] == '\0'){
                        flag++;
                        y=0;
                    }
                }
                x++;
            }

            printf("%s xuat hien %d lan\n", kq, flag);
        }

        kq[j] = arr[i];
        j++;
    }
    // char arr1[] = "mothai";
    // char arr2[] = "mot hai";
    // int size1, size2, count=0;
    // size1 = sizeArr(arr1);
    // size2 = sizeArr(arr2);
    // for(int i=0; i<size1; i++)
    //     for(int j=0; j<size2; j++){
    //         if(arr1[i] == arr2[j]){
    //             i++;
    //             count++;
    //         }
    //     }
    
}