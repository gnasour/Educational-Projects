#include <stdio.h>
#include <ctype.h>

double atof(char *);

int main(){
    char* string = "12.8564E2\0";
    printf("%f\n",atof(string));
    return 0;
}

double atof(char* s){
    int i;
    
    double value = 0;
    double power = 1;
    int exponent = 0;
    for(i = 0; isdigit(s[i]); i++){
        value = value*10 + (s[i] - '0');
    }
    
    if(s[i] == '.'){
        i++;
    }
    
    for(i; isdigit(s[i]); i++){
        value += (s[i]-'0')/(power*=10);
    }

    if(s[i] == 'e' || s[i] == 'E'){
        i++;
    }

    for(i; isdigit(s[i]); i++){
        exponent = exponent* 10 + (s[i] - '0');
    }

    for(exponent; exponent > 0; exponent--){
        value*=10;
    }

    return value;
}