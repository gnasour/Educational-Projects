#include <stdio.h>

int main()
{
    int c;

    while((c=getchar()) != EOF){

        if( c == ' ' || c == '\n' || c == '\t'){
            while((c=getchar()) == ' ' || c == '\n' || c == '\t')
                ;
            putchar('\n');
        }
        
        if( c != EOF)
            putchar(c);
        
    }
}