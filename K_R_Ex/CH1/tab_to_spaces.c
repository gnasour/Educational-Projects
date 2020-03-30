#include <stdio.h>

#define TAB_SPACE_COUNT 4
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
            if (c == '\t')
            {
                counter += 4;
            }
            else
            {
                counter++;
            }
        }
        else
        {
            for (int i = 0; i < counter; i++)
            {
                if (c == '\t')
                {
                    for (int j = 0; j < TAB_SPACE_COUNT; j++)
                    {
                        line[j + i] = ' ';
                    }
                }
            }
            printf("%s\n", line);
            memset(line, 0, sizeof(line));
            counter = 0;
        }
    }
}