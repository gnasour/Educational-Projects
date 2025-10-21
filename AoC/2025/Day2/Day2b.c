#include <string.h>
#include <stdio.h>
#include <stdlib.h>


int main()
{
    // Variables to access data in file
    FILE* day2data = fopen("Day2.txt", "r");
    size_t num_bytes = 0;
    char* line = 0;
    
    // Num of safe lines
    int safe_lines = 0;

    // Array to hold ints
    int* num_arr = (int*) malloc(10*sizeof(int));
    
    while(getline(&line, &num_bytes, day2data) != -1){
        
        int num_in_line = 0;
        char* line_tok = strtok(line, " ");
        while(line_tok != NULL){
            
            num_arr[num_in_line] = atoi(line_tok);
            num_in_line++;
            line_tok = strtok(NULL, " ");
        }

        // Boolean to check monotonicity of data
        int increasing = 0;
        if((num_arr[0] - num_arr[1]) < 0 ){
                increasing = 1;
        }

        // Boolean to check if a line is safe
        int safe = 1;

        // Check if a level has multiple bad values
        int bad_level = 0;

        for(int i = 0; i < num_in_line-1 && safe; i++){
            if((num_arr[i] - num_arr[i+1]) > 0 && increasing == 1){
                bad_level++;
                if(bad_level >= 2){
                    safe = 0;
                    break;
                }
                
            }
            else if((num_arr[i] - num_arr[i+1]) < 0 && increasing == 0){
                bad_level++;
                if(bad_level >= 2){
                    safe = 0;
                    break;
                }
            }
            int diff = abs(num_arr[i] - num_arr[i+1]);
            if(diff < 1 || diff > 3){
                safe = 0;
            }
        }
        if(safe){
            safe_lines++;
        }
        safe = 1;
    }
    free(num_arr);
    free(line);

    printf("%d\n", safe_lines);

    
}