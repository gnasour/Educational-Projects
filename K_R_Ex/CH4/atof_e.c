#include <stdio.h>
#include <ctype.h>

double atof(char *);

int main(){
    char* string = "12.8\0";
    printf("%f",atof(string));
    return 0;
}

double atof(char* s){
    
    int i;
    
    double value = 0;
    double power = 1;
    for(i = 0; isdigit(s[i]); i++){
        value = value*10 + (s[i] - '0');
    }
    
    if(s[i] == '.'){
        i++;
    }
    
    for(i; s[i] != '\0'; i++){
        value += (s[i]-'0')/(power*=10);
    }

    return value;
}