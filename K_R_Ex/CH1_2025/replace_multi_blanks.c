#include <stdio.h>

int main()
{
    int c;

    while((c=getchar()) != EOF){

        if( c == ' '){ 
            putchar(c);
            for(c; c == ' '; c = getchar()){ 
           }
        }

        if(c != EOF)
            putchar(c);
            
    }
}