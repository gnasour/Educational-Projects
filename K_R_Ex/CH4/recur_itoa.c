#include <stdio.h>

#define LEN 512

void itoa(int, char[]);

int main(){
    int num = 589432;
    char s[LEN];
    itoa(num, s);
    printf("%s", s);

}

void itoa(int numToChar, char* numString){
    
    static int string_pos = 0;
    if(numToChar > 0){
        itoa(numToChar/10,numString);
        numString[string_pos++] = numToChar%10+'0';
    }else{
        numString[string_pos] = '\0';
    }
    
    

}