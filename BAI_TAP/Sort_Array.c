#include <stdio.h>
#include <stdint.h>
 
void sortList(uint8_t arr[], uint8_t n){
    int temp;
    for(int i=0; i < n-1; i++){
        for(int j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;        
            }
        }
    }

    printf("\nMang da sap xep la: ");
    for(int i = 0; i < n; i++){
        printf("%5d", arr[i]);
    }

    
    for(int i = 0; i<n; i++){ 
        int count = 1;
        if(arr[i] == arr[i-1])
            continue;
        for(int j = i + 1; j<n; j++){
                if(arr[i] == arr[j])
                    count++;
        }
        printf("\n%d xuat hien %d lan\n", arr[i], count);
    }
}

int main(){
    uint8_t arr[] = {1, 3, 4, 2, 6, 7, 8, 3, 5};
    uint8_t size;
    
    size = sizeof(arr)/sizeof(arr[0]);
    sortList(arr, size);
    
    
}