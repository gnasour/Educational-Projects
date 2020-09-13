#include <stdio.h>

#define swap(t, x, y) {t = x; x = y; y = t;}

int main(){
    int x = 5;
    int y = 4;
    int t;

    swap(t,x,y);

    printf("x = %d y = %d\n",x,y);

    return 0;
}