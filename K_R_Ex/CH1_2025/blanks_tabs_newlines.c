#include <stdio.h>

int main()
{

    long nl = 0, tab = 0, blank = 0;
    int c;
    while((c=getchar()) != EOF){
        if(c == '\t')
            ++tab;
        else if(c == '\n')
            ++nl;
        else if(c == ' ')
            ++blank;
    }

    printf("New Line: %ld, Tab: %ld, Blank: %ld\n", nl, tab, blank);

}