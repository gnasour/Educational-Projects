#include <stdio.h>

#define MAX_WORD_LEN 10         // The histogram will have a simple domain of lengths ranging from 1 to 10+

int main()
{
    int c, wl;

    int wl_hist[MAX_WORD_LEN];  // Array holds the count of word lengths encountered during execution

    wl = 0;                     // Temp variable to store current word length

    for(int i = 0; i < MAX_WORD_LEN; i++){
        wl_hist[i]=0;           // Initializing hist array
    }
    while((c=getchar()) != EOF){
        
        // If a blank is encountered, increment appropriate spot in hist array and reset word length 
        if( c=='\n' || c=='\t' || c==' ' ){
            
            if(wl >= 10){
                wl_hist[9]++;
            }
            else{
                wl_hist[wl]++;
            }

            wl = 0;
        }
        else{
            wl++;
        }
    }

    //  Print the histogram
    printf("Word Length Histogram\n");
    printf("---------------------\n");
    for(int i = 0; i < MAX_WORD_LEN; i++){
        
        printf("%d:\t", i+1);
        for(int j = wl_hist[i]; j > 0; j--){
            putchar('*');
        }
        putchar('\n');
    }
}