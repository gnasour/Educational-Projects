#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 1000 //Max length of 1000 characters and 1000 word lengths

void print_histogram(int *word_lengths, int word_lengths_index_size)
{
    int format_dashes = 0;
    //printf("%d\n", word_lengths_index_size);

    //Clean the screen to present the histogram
    system("cls");
    printf("\n");

    for (int i = 1; i <= word_lengths_index_size; i++)
    {
        if (format_dashes < word_lengths[i])
            format_dashes = word_lengths[i];
    }
    printf("-----");
    for (int i = 0; i < format_dashes; i++)
    {
        printf("---");
    }
    printf("\n");
    for (int i = 1; i <= word_lengths_index_size; i++)
    {
        printf("| %d |", word_lengths[i]);
        for (int j = 0; j < word_lengths[i]; j++)
        {
            printf(" *");
        }
        printf("\n");
        for (int j = 0; j < format_dashes; j++)
        {
            printf("---");
        }
        printf("\n");
    }
}

int main()
{

    int word_lengths[MAXLENGTH] = {0};
    char letter;
    int word_size = 0;
    int word_lengths_index_size = 0;

    printf("Start input \n");

    while ((letter = getchar()) != EOF)
    {

        if (letter == '\n')
        {
            if (word_size > word_lengths_index_size)
                word_lengths_index_size = word_size;
            word_lengths[word_size]++;
            word_size = 0;
        }
        else
        {
            if (word_size < MAXLENGTH)
            {
                word_size++;
            }
            else
            {
                printf("Word is too long, please press enter and type a word that is less than %d letters long\n", MAXLENGTH);
                fseek(stdin, 0, SEEK_END);
                word_size = 0;
            }
        }
    }

    print_histogram(word_lengths, word_lengths_index_size);

    return 0;
}
