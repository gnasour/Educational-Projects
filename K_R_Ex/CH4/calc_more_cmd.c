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
            case 'p':
                printf("%f", peak());
                break;
            case 'd':
                duplicate();
                break;
            case 's':
                swap();
                break;
            case 'c':
                clear();
                break;
            case '\n':
                printf("\t%.8g\n", pop());
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


//Look at the top of the stack without removing the element
double peak(){

    if(sp > 0){
        return val[sp-1];
    }else{
        printf("Error: Stack is empty\n");
        return 0.0;
    }  

}


//Duplicate the value at the top of the stack
void duplicate(){
    
    val[++sp] = val[sp-1];

}


//Swap the top two elements of the stack
void swap(){

    float temp = pop();
    float temp2 = pop();
    push(temp);
    push(temp2);

}


//Clears the array
void clear(){

    int i;
    for(i = 0; i < MAXVAL; i++)
        val[i] = 0;

}