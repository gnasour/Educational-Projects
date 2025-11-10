#include "helpers.h"


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