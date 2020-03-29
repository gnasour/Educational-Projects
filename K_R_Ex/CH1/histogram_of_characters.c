#include <stdio.h>
#include <stdlib.h>

#ifdef _WIN32
#define CLEAR_SCREEN system("cls")
#endif
#ifdef linux
#define CLEAR_SCREEN system("clear")
#endif

//Number of letters in the alphabet
#define NUM_OF_CHARS 26
//Common ranges in the ASCII table
#define UPPER_TO_LOWER_CONV 32
#define UPPER_CASE_START_RANGE_ASCII 65
#define UPPER_CASE_END_RANGE_ASCII 90
#define LOWER_CASE_START_RANGE 97
#define LOWER_CASE_END_RANGE 122

//Function prototypes
void input_characters();
void print_histogram(char*);

//Pointer of character frequencies


int main(){
    char* char_freq_array = calloc(NUM_OF_CHARS, sizeof(char));
    input_characters(char_freq_array);
    print_histogram(char_freq_array);
    free(char_freq_array);
}

void input_characters(char* char_freq_array){
    char c;

    while((c = getchar())!=EOF){
        if(c >= UPPER_CASE_START_RANGE_ASCII && c <= UPPER_CASE_END_RANGE_ASCII)
            c+=UPPER_TO_LOWER_CONV;
        if(c >= LOWER_CASE_START_RANGE && c <= LOWER_CASE_END_RANGE)
            char_freq_array[c-LOWER_CASE_START_RANGE]++;
    }
}

void print_histogram(char* char_freq_array){
    CLEAR_SCREEN;
    printf("--------------------\n");
    for(int i = 0; i < NUM_OF_CHARS; i++){
        printf("%c| ", LOWER_CASE_START_RANGE+i);
        for(int j = 0; j < char_freq_array[i]; j++){
            printf(" *");
        }
        printf("\n----------------------\n");
    }
}
