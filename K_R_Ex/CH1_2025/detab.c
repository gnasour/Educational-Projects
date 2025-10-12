#include <stdio.h>

#define MAXLINE 1000
#define TAB_SPACE 4

int getlines(char s[], int lim)
{
    int c, i;

    for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; ++i){
        s[i] = c;
    }  
    if(c == '\n'){
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void detab(char s[], char t[])
{

    for(int i = 0, j = 0; s[i] != '\0' && j < MAXLINE-1; i++){
        if(s[i] == '\t' && i+j+TAB_SPACE<MAXLINE-1){
            for(int k = 0; k < TAB_SPACE; k++){
                t[i+j+k] = ' ';
            }
            j += TAB_SPACE;
        }
        
    }

}

int main()
{
    char line[MAXLINE];
    char detabbed_line[MAXLINE];

    getlines(line, MAXLINE);

    detab(line, detabbed_line);

    printf("%s\n", detabbed_line);

    return 0;

}