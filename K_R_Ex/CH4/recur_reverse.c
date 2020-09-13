#include <stdio.h>
#include <string.h>

#define LEN 512

void recur_reverse(char[]);

int main(){
    
    char s[LEN] = "Hello, World!";

    recur_reverse(s);
    printf("%s\n", s);
    return 0;
}

void recur_reverse(char* s){
    
    static int string_pos = 0;
    static int string_rev_pos = 0;

    char c;
    
    if((c = s[string_pos++]) != '\0'){
        recur_reverse(s);
        s[string_rev_pos++] = c;
    }

    

}