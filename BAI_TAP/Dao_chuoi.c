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

int sizeArr(uint8_t arr[]){
    uint8_t size, count=0, i=0;
    while(arr[i++] != '\0')
        count++;
    return count;
}

// void daoChuoi(char arr[], int size){
//     int i, j, k=0, count=0;;
//     char temp[100];
//     char dao[50];
//     for(i=size-1; i>0; i--){
//         if(arr[i] == ' '){
//             j=i+1;
//             while(count > 0){
//                 temp[k++] = arr[j++];
//                 count--;
//             }
//             temp[j] = '\0';
//         }
//         else{
//             count++;
//         }
//     }
// }

void daoChuoi(char arr[], char dao[], int size){
    int i, j=0, k, count=0;

    for(i=size-1; i>=0; i--){
        count++;

        if (arr[i] == ' '){
            for(k = i; k < i+count; k++){
                dao[j] = arr[k+1];
                j++;
            }
            dao[j-1] = ' ';
            count = 0;
        }

        if (i == 0){
            for(k = i; k < i+count; k++){
                dao[j] = arr[k];
                j++;
            }
        }
    }

    dao[sizeArr(arr)] = '\0';
    printf("%s\n", dao);
}

int main(){
    char arr[] = {"Mot hai"};
    char dao[] = "";
    
    int size;
    size = sizeArr(arr);
    printf("%d\n", size);

    //sortList(arr, size);
    daoChuoi(arr, dao, size);
}