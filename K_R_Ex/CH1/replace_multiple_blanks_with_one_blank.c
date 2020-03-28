#include <stdio.h>

int main()
{

    //Temp variable to retrieve a character
    char c;

    while ((c = getchar()) != EOF)
    {
        if (c == ' ')
        {
            putchar(c);
            while((c=getchar())== ' '){
            }
            if(c!=EOF){
                putchar(c);
            }
        }else{
            putchar(c);
        }
    }

    return 0;

}