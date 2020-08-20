#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void itoa_expanded(int,char*,int);

int main(){
    srand(time(NULL));
    int n = rand()%1000;
    char* itoa = calloc(1000, sizeof(char));
    int min_width = 12;
    printf("%d\n", n);
    itoa_expanded(n, itoa, min_width);
    printf("%s", itoa);
    exit(EXIT_SUCCESS);
    return 0;
}

void itoa_expanded(int n, char* s, int min_width){
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

    while(min_width > i){
        s[i++] = 'x';
    }
    
    s[i] = '\0';


    strrev(s);

}