#include <stdio.h>

#define LEN 512

void recur_reverse(char[]);

int main(){
    
    char s[LEN] = "Hello, World!";

    recur_reverse(s);

    return 0;
}

void recur_reverse(char[] s){
    if(s[0]!= '\0')
        recur_reverse
}