#include <stdio.h>

int strncmp(char*, char*, int);

int main(){
    char s[256] = "Hello!";
    char t[256] = "Herring";
    if(strncmp(s,t,2)==0){
        printf("Good comparison\n");
    }
    return 0;
}

int strncmp(char* s, char* t, int n){
    
    for(int i = 0; i < n; i++,s++,t++){
        if(*s < *t || *s > *t)
            return *s - *t;
    }

    return 0;
}