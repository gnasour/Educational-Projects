#include <stdio.h>

#define MAXLINE 1000

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

void reverse(char s[], int len)
{
    char temp;
    
    
    for(int i = 0; i < len/2; i++){
        temp = s[i];
        s[i] = s[len-i-1];
        s[len-i-1] = temp;    
    }
}

int main()
{
    char line[MAXLINE];
    int len = getlines(line, MAXLINE);

    reverse(line, len);

    printf("%s\n", line);

    return 0;
}