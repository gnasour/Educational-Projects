#include <stdio.h>
#include <ctype.h>

int getch(void);
void ungetch(int);
float getfloat(float*);


int main(){
    float fp;
    getfloat(&fp);
    printf("%f\n", fp);
}

float getfloat(float *pf){

    int c;
    float decimal;
    int whole_num;
    int sign;
    while(isspace(c=getch()));

    if(!isdigit(c) && c != EOF && c != '+' && c != '-'){
        ungetch(c);
        return 0;
    }

    sign = (c == '-') ? -1:1;
    if(c=='+' || c=='-')
        c = getch();
    while(!isdigit(c)){
        ungetch(c);
        c = getch();
    }
    for(whole_num = 0; isdigit(c); c = getch())
        whole_num = 10 * whole_num + (c - '0');
    if(c=='.'){
        decimal = 0;
        while(isdigit(c=getch()))
            decimal = decimal + (1.0/10)*(c - '0');
    }else{
        ungetch(c);
    }
    *pf = 0.0;
    *pf += decimal;
    *pf += whole_num;
    *pf *= sign;
    if(c != EOF)
        ungetch(c);
    return c;

}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c){
    
    if(bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
        
}