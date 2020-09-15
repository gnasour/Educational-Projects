#include <stdio.h>

int strend(char*, char*);

int main(){
    char* s = "Hello, World!";
    char* t = "World!";
    char* u = "World";
    printf("%d\n", strend(s,t));
    printf("%d\n", strend(s,u));
    return 0;   
}

int strend(char* s, char* t){
    char* t_address = t;
    for(; *s != '\0'; *s++){
        while(*s == *t){
            if(*s == '\0' && *t == '\0')
                return 1;
            s++;
            t++;
        }
        t = t_address;
    }

    return 0;

}