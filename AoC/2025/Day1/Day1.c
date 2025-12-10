#include "../helpers.h"

int main()
{
    FILE* data = fopen("Day1.txt", "r");
    char* line = NULL;
    size_t n = 0;

    int dial = 50;
    char dir;
    char rotations[4];
    int zero_count = 0;
    
    while(getline(&line, &n, data) != -1){
        
        // Extract direction and rotation amount
        dir = line[0];
        int i = 0;
        while((*(rotations+i)=*(line+i+1)) != '\n')
            i++;
        rotations[i] = '\0';

        // Calculate position
        int rotated_zero = 0;
        if(dir == 'R'){
            dial += atoi(rotations);
            while(dial >= 100){
                dial -= 100;
                zero_count++;
                rotated_zero = 1;
            }
        }
        else{
            dial -= atoi(rotations);
            while(dial < 0){
                dial += 100;
                zero_count++;
                rotated_zero = 1;
            }
        }

        if(dial == 0 && !rotated_zero){
            zero_count++;
        }
        

    }

    printf("Num of Zeroes: %d\n", zero_count);
    
    return 0;
    
}