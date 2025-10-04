#include <stdio.h>

#define CHAR_SET_LEN 27     // Size of English alphabet + undef chars


int main()
{
    int c;

    int char_freq[CHAR_SET_LEN];
    while((c=getchar())!=EOF){
        
        if(c >= 'A' && c < 'Z'+1){
            char_freq[c - 'A']++;
        }
        else if(c >= 'a' && c < 'z'+1){
            char_freq[c-'a']++;
        }else{
            char_freq[26]++;
        }
    }

    //  Print the histogram
    printf("Word Length Histogram\n");
    printf("----------------------\n");
    for(int i = 0; i < CHAR_SET_LEN; i++){

        printf("%d:\t", i+1);
        for(int j = char_freq[i]; j > 0; j--){
            putchar('*');
        }
        putchar('\n');
    }
}