#include <stdio.h>
#include <stdlib.h>

#define MAXOP 100
#define NUMBER '0'

int getop(char []);
void push(double);
double pop(void);

int main(){

    int type;
    double op2;
    char s[MAXOP];
    float var1, var2;

    while((type = getop(s))!=EOF){
        switch(type){
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                push(pop() + pop());
                break;
            case '*':
                push(pop() * pop());
                break;
            case '-':
                op2 = pop();
                push(pop()-op2);
                break;
            case '/':
                op2 = pop();
                if(op2 != 0.0)
                    push(pop()/op2);
                else
                    printf("Error: Zero in the divisor\n");
                break;
            //Handling the variables
            case 'x':
                var1 = pop();
                push(var1);
                break;
            case 'y':
                var2 = pop();
                push(var2);
                break;
            case '\n':
                var1 = pop();
                printf("\t%.8g\n", var1);
                break;
            default:
                printf("Error: unknown command %s\n", s);
                break;
            
        }
    }

    return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f){

    if(sp < MAXVAL)
        val[sp++] = f;
    else
        printf("Error: Stack is full, cannot push %g\n", f);
}

double pop(void){

    if(sp > 0){
        return val[--sp];
    }else{
        printf("Error: Stack is empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[]){

    int i, c;

    while((s[0] = c = getch()) == ' ' || c == '\t');

    s[1] = '\0';

    if(!isdigit(c) && c != '.')
        return c;
    i = 0;
    
    if(isdigit(c))
        while(isdigit(s[++i] = c = getch()));
    
    if(c == '.')
        while(isdigit(s[++i] = c = getch()));

    s[i] = '\0';
    if(c != EOF)
        ungetch(c);
    return NUMBER;
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