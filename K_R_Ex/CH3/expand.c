#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BUF_SIZE 512

void expand(char**,char*);

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stderr, "Improper usage, enter a hyphenated series to expand");
        exit(EXIT_FAILURE);
    }

    char* string_buff[BUF_SIZE];
    expand(argv[1], &string_buff[0]);

    exit(EXIT_SUCCESS);

    return 0;

}

void expand(char** s1, char* s2){
    
    for(int i = 0; i < strlen(s1); i++){
        if(s1[i] == '-'){
            for(char j = s1[i-1]; j <= s1[i+1]; j++){
                printf("%c", j);
            }

        }
    }
}
