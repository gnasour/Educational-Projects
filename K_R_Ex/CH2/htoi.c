#include <stdio.h>

#define MAX_LENGTH 1000

int main(){

    char c;
    char hex_number[MAX_LENGTH];
    int length = 0;
    printf("Enter the hex number: ");
    for(int i = 0; i < MAX_LENGTH && (c=getchar()) != EOF && c != '\n'; i++){
        hex_number[i] = c;
        length = i;
    }
    int hex_to_int_num = 0;
    for(int i = length; i >= 0; i--){
        int temp_hex_num = 1;
        if(hex_number[i] >= '0' && hex_number[i] <='9'){
            for(int j = 0; j < length-i; j++){
                temp_hex_num *= 16;
            }
            temp_hex_num *= (hex_number[i] - '0');
            hex_to_int_num += temp_hex_num;
        }else{
            for(int j = 0; j < i; j++){
                temp_hex_num *= 16;
            }
            temp_hex_num *= (hex_number[i] - 'a') + 10;
            hex_to_int_num += temp_hex_num;
        }

    }

    printf("\n%d", hex_to_int_num);
    
    

}