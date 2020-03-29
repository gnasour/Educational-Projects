#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int main(){

    char c;
    char line[MAX_LINE];
    int counter = 0;
    while((c = getchar())!=EOF){
        if(c != '\n'){
            line[counter] = c;
            counter++;
        }else{
            line[counter] = '\0';
            for(int i = counter; i < 0; i--){
                if((line[counter] == '\t' || line[counter] == ' ') && line[counter] == line[counter-1]){
                    line[counter] = line[counter-1];
                }
            }
            printf("%s\n", line);
            memset(line, 0, sizeof(line));
            counter = 0;
        }
    }


}