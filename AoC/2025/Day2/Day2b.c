#include <string.h>
#include <stdio.h>
#include <stdlib.h>

// Arguments: A line of data to tokenize into integers, delimited by spaces
// Returns: a pointer to an array of positive integers. -1 is used to signal end of array
int* data_tok(char* line){
    
    
    // Array of int data to return
    int* num_arr = (int*) malloc(10*sizeof(int));
    // Index of array
    int num_in_line = 0;

    // Line of text to tokenize
    char* line_tok = strtok(line, " ");

    while(line_tok != NULL){
        num_arr[num_in_line] = atoi(line_tok);
        num_in_line++;
        line_tok = strtok(NULL, " ");
    }
    
    num_arr[num_in_line] = -1;

    return num_arr;
}

// Function checks whether the two numbers in sequence are increasing or decreasing
// Returns 1 if increasing and 0 if decreasing
int check_monotonicity(int first, int next){
    
}

int main()
{
    // Variables to access data in file
    FILE* day2data = fopen("Day2.txt", "r");
    size_t num_bytes = 0;
    char* line = 0;

    // Num of safe lines 
    int safe_lines = 0;

    // Array of ints holding a line of tokenized data
    int* num_arr;
    
    while(getline(&line, &num_bytes, day2data) != -1){
        
        num_arr = data_tok(line);
        for(int i = 0; num_arr[i] != -1; i++){
            printf("%d ", num_arr[i]);
        }
        
        free(num_arr);
    }

    free(line);

    printf("%d\n", safe_lines);
}