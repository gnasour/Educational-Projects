#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000
#define NUM_OF_SPACES 4

int main(){
    char c;
    char line[MAX_LINE];
    int counter = 0;
    int blanks = 0;
    while((c = getchar())!=EOF){
        if(c!='\n'){
            if(c == ' '){
                blanks++;
                if(blanks == NUM_OF_SPACES){
                    for(int i = counter; i < counter - 4; i--){
                        line[i] = '\0';

                    }
                    counter -= 3;
                    line[counter] = '\t';
                }else{
                    line[counter] = c;
                    counter++;
                }
            }else{
                line[counter] = c;
                counter++;
            }
        }
        else{
            line[counter] = '\0';
            printf("%s", line);
            memset(line, 0, sizeof(line));
            counter = 0;
        }
    }
}