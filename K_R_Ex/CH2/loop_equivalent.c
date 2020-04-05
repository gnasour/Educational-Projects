#include <stdio.h>

#define MAX_LINE 1000;

int main(){

    int limit = MAX_LINE;
    char c;
    char s[limit];
    for(int i = 0; i < limit; i++){
        if((c = getchar())!='\n'){
            if(c!=EOF){
                s[i] = c;
            }else{
                i = limit;
            }

        }else{
            i = limit;
        }
    }
    return 0;
}