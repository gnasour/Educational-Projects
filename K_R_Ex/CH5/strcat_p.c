#include <stdio.h>
#include <stdlib.h>

char* strcat_p(char*, char*);

int main(){
    char* s = malloc(256);
    char* t = malloc(256);
    s[0] = 'H';
    s[1] = 'E';
    s[2] = '\0';
    t[0] = 'L';
    t[1] = 'o';
    t[2] = '\0';
    strcat_p(s,t);
    printf("%s\n", s);
    return 0;
}

char* strcat_p(char* s, char* t){
    
    //Skip til the end of s
    for(s; *s!='\0'; s++);

    //Copy t to the end of s
    for(t; *t!='\0'; t++,s++){
        *s = *t;
    }

    return s;

}