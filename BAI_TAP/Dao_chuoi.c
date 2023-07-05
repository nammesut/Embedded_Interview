#include <stdio.h>
#include <stdint.h>

int sizeArr(char arr[]){
    int size, count=0, i=0;
    while(arr[i++] != '\0')
        count++;
    return count;
}

int main(){
    char arr[] = "Ba nam sau";
    char dao[] = "";
    
    int i, j=0, count=0;
    
    int size;
    size = sizeArr(arr);
    printf("%d\n", size);


    for(i=size-1; i>=0; i--){
        count++;

        if (arr[i] == ' '){
            printf("%d\n", count);
            for(int k = i; k < i+count; k++){
                dao[j] = arr[k+1];
                j++;
            }
            dao[j-1] = ' ';
            count = 0;
        }

        if (i == 0){
            for(int k = i; k < i+count; k++){
                dao[j] = arr[k];
                j++;
            }
        }
    }

    dao[sizeArr(arr)] = '\0';
    printf("%s\n", dao);
}
