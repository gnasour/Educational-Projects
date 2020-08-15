#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void itoa_ex(int, char[]);

int main(){

    srand(time(NULL));
    int n = rand()%1000;
    char* itoa = calloc(1000, sizeof(char));
    itoa_ex(n, itoa);
    printf("%s", itoa);
    exit(EXIT_SUCCESS);
    return 0;
}

void itoa_ex(int n, char s[]){
    
    
    int i, sign;

    if((sign = n) < 0){
        n = ~n;
    }
    
    i = 0;
    
    do{
        s[i++] = n % 10 + '0';
    }while((n /= 10) > 0);

    if(sign < 0){
        s[i++] = '-';
    }
    
    s[i] = '\0';

    strrev(s);

}