#include <stdio.h>

#undef strncpy

char* strncpys(char*, char*, int);

int main(){
    char s[256] = "Hello, ";
    char t[256] = "World!";
    strncpys(s,t,3);
    printf("%s\n", s);
}

char* strncpys(char* s, char* t, int n){
    
    while(*s!='\0')
        s++;

    for(int i = 0; i < n; i++,s++){
        if(*t == '\0')
            *s = '\0';
        else{
            *s = *t;
            t++;
        }
    }
    s++;
    *s = '\0';
    return s;
}