#include <stdio.h>
#include <stdlib.h>

#define MAX_WORD 1000

int main(){
    char array[MAX_WORD];
    char c;
    int counter = 0;
    while((c = getline())!=EOF){
        if(c!='\n'){
            array[counter] = c;
            counter++;
        }
        else{
            if(counter >= 80 && counter < 1000){
                array[counter] = '\0';
                printf("%s", array);
                memset(array, 0, sizeof(array));
                counter = 0;
            }

        }
    }
}