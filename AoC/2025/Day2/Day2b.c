#include "../helpers.h"

// Function checks whether the two numbers in sequence are increasing or decreasing
// Returns 2 if increasing, 1 if decreasing, and 0 if the same
int check_monotonicity(int first, int next){
    if(first>next)
        return 1;
    else if(first < next)
        return 2;
    else
        return 0;
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

    // Current line being checked
    int line_num = 1;
    
    while(getline(&line, &num_bytes, day2data) != -1){

        // Boolean to check if current line is safe
        int safe = 1;

        // Check if a line has a bad value and if its been forgiven once
        int bad_val = 0;
        
        
        num_arr = data_tok(line);

        // Counters to check amount of increasing and decreasing pairs
        int increasing = 0, decreasing = 0;

        for(int i = 0; num_arr[i+1] != -1; i++){
            
            int monotonicity = check_monotonicity(num_arr[i], num_arr[i+1]);
            int diff = abs(num_arr[i] - num_arr[i+1]);

            if(monotonicity == 0){
                bad_val++;
            }
            else if(monotonicity == 2){
                increasing++;
            }
            else if(monotonicity == 1){
                decreasing++;
            }

            if(increasing > 1 && decreasing > 1){
                safe = 0;
                break;
            }
            
            if(diff > 3){
                bad_val++;
            }

            if(bad_val > 1){
                safe = 0;
                break;
            }
        }

        // Print line number currently being checked
        // printf(": %d\n", line_num);
        // line_num++;
        
        
        if(safe){
            safe_lines++;
        }
        free(num_arr);
    }

    free(line);

    printf("%d\n", safe_lines);
}