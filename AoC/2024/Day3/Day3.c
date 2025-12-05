#include "../helpers.h"

int state = 1;

int process_line(char* line)
{
    const static char* init_pattern = "mul(";
    // Use strstr to get pointer of mul(
    // and set line's value to it
    // This ensures that we march along the entire string
    int line_tot = 0;
    while(line = strstr(line, init_pattern)){
        
        int num1, num2;
        int len;
        char* comma_pos;
        char* paren_pos;

        line += 4; // Point to potential first argument
        
        //Grabbing first arg
        comma_pos = strstr(line, ",");
        len = comma_pos - line;
        if(comma_pos == NULL || len > 3 || len == 0)
            continue;
        else{
            char a_num[len+1];  // C strings have a terminating null character at the end
            for(int i = 0; i < len; i++){
                a_num[i] = *(line+i);
            }
            a_num[len]='\0';
            num1 = atoi(a_num);
        }

        //Advance pointer to right after comma
        line = comma_pos+1;

        //Grabbing second arg
        paren_pos = strstr(line, ")");
        len = paren_pos - line;
        if(paren_pos == NULL || len > 3 || len == 0)
            continue;
        else{
            char a_num[len+1];
            for(int i = 0; i < len; i++){
                a_num[i] = *(line+i);
            }
            a_num[len]='\0';
            num2 = atoi(a_num);
        }
        
        line_tot += (num1*num2);
        
    }
    return line_tot;
}

char* find_enable_parts(char* line)
{
    const static char* dont_text = "don't()";
    const static char* do_txt = "do()";

    char* next_dont = strstr(line, dont_text);

    if(state){
        
    }
}

int main()
{
    FILE* day3data = fopen("Day3.txt", "r");
    size_t num_bytes;
    char* line;
    char* do_line; // Strings that have mul enabled

    int tot=0;

    while(getline(&line, &num_bytes, day3data) != -1){
        while(do_line=find_enable_parts(line)){
            tot += process_line(do_line);
            line += strlen(do_line);
        }
    }

    printf("total: %d\n", tot);

    return 0;
}