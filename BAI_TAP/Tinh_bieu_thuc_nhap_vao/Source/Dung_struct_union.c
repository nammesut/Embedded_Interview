#include <stdio.h>
#include <stdint.h>

typedef enum {
    NUMBER,
    OPERATOR
}tydeMath;

typedef struct {
    tydeMath key;
    union {
        uint16_t number;
        char operator;
    }value;
}tydeMaths;

void numToDec(char input[], tydeMaths output[]){
    uint16_t number = 0;
    uint8_t i = 0;

    while(*input != '\0'){
        if(*input >= '0' && *input <= '9'){
            uint8_t temp = *input - '0';
            number = 10*number + temp;
            input++;
            continue;
        }

        else if(*input == '+' || *input == '-' || 
            *input == '*' || *input == '/'){
                output[i].key = OPERATOR;
                output[i].value.operator = *input;
                input++;
                i++;
                continue;
            } 
        else{
            if(number != 0){
                output[i].key = NUMBER;
                output[i].value.number = number;
                i++;
                number = 0;
            }
        }
        input++; 
        
    }
    output[i].key = NUMBER;
    output[i].value.number = number;
}

int8_t calculate(tydeMaths output[]){
    uint8_t i = 0;
    int8_t result = output[0].value.number;

    while(output[i].key == OPERATOR || output[i].key == NUMBER){
        if(output[i].key != OPERATOR){
            i++;
            continue;
        }
        else{
            if(output[i].value.operator == '+'){
                result += output[i+1].value.number;
                i++;
                continue;
            }
            else if(output[i].value.operator == '-'){
                result -= output[i+1].value.number;
                i++;
                continue;
            }
            else if(output[i].value.operator == '*'){
                result *= output[i+1].value.number;
                i++;
                continue;
            }
            else{
                result /= output[i+1].value.number; 
                i++;
            }
        }
    }
    return result;
}

int main()
{
    tydeMaths output[20];
    char input[] = "2 + 1 * 10";

    numToDec(input, output);

    printf("%d\n", calculate(output));

    return 0;
}
