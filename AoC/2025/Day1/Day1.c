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

        // If num_of_rotations is >= 100, divide by 100 to get extra 0 counts, then calculate how many rotations are left over and yet to be made
        int num_of_rotations;
        num_of_rotations = atoi(rotations);
        if(num_of_rotations >= 100){
            zero_count += num_of_rotations/100;
            num_of_rotations = num_of_rotations - (num_of_rotations/100)*100;
        }


        // Calculate position
        if(dir == 'R'){
            dial += num_of_rotations;
            if(dial >= 100){
                dial-=100;
                zero_count++;
            }
        }
        else{
            dial -= num_of_rotations;
            if(dial < 0){
                dial+=100;
                zero_count++;
            }
            else if(dial == 0){
                zero_count++;
            }
        }
        

    }

    printf("Num of Zeroes: %d\n", zero_count);
    
    return 0;
    
}