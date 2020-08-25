#include <stdio.h>
#include <string.h>


void itob(int, char*, int);

int main(){

    return 0;
}

void itob(int n, char* s, int b){

    int i = 0;
    char sign = 0;
    
    (if n < 0){
        n = ~n;
        sign = 1;
    }

    do{
        s[i++] = n%b + '0';
        
    }while((n/=b) > 0)
    
    if(sign){
        s[i++] = '-';
    }

    strrev(s);

}