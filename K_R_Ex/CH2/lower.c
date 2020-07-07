#include <stdio.h>

#define MAX_LEN 256

int main(){

    char sentence[MAX_LEN];
    char c;
    int i = 0;
    for(i; (c=getchar())!=EOF; i++){
        c = (c >= 65 && c <= 90) ? c+32 : c;
        sentence[i] = c;
    }
    sentence[i+1] = '\0';
    printf("%s", sentence);

    return 0;
}