#include <stdio.h>
#include <string.h>

#define MAX_LINE 1000

int main()
{

    char c;
    char line[MAX_LINE];
    int counter = 0;

    while ((c = getchar()) != EOF)
    {
        if (c != '\n')
        {
            line[counter] = c;
            counter++;
        }
        else
        {
            for(int i = 0; i < counter; i++)
        }
        
    }
}