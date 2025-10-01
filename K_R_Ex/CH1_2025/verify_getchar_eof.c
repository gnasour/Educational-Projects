#include <stdio.h>

int main()
{
    int c;

    while(c = (getchar()!=EOF)){
        printf("%d\n", c);
    }
    printf("%d\n", c);      // This is necessary because encountering EOF will produce 0
                            // and the while loop will not execute on this condition
}