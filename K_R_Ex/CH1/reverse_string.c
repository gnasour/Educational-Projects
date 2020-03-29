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
            char temp;
            int index = counter/2;
            for(int i = 0; i < index; i++){
                temp = line[i];
                line[i] = line[counter-i-1];
                line[counter-i-1] = temp;
            }
            line[counter]='\0';
            printf("%s\n", line);
            memset(line, 0, sizeof(line));
            counter = 0;
        }
        
    }
}