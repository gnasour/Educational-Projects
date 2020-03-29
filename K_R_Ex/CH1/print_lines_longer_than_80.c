#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int main(){
    char array[MAX_LINE];
    char c;
    int counter = 0;
    while((c = getchar())!=EOF){
        if(c!='\n'){
            array[counter] = c;
            counter++;
        }
        else{
            if(counter > 80 && counter < 1000){
                array[counter] = '\0';
                printf("%s\n", array);
                memset(array, 0, sizeof(array));
                counter = 0;
            }else{
                memset(array, 0, sizeof(array));
                counter = 0;
            }

        }
    }
}
