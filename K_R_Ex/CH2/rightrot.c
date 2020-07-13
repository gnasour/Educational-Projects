#include <stdio.h>

int rightrot(unsigned x, int n){
    return x >> n;
}

int main(){
    
    unsigned x = 0;
    int n = 0;

    printf("Enter the number you want to rotate: ");
    scanf("%d", &x);

    printf("Enter the times you want the bits rotated: ");
    scanf("%d", &n);

    printf("%d\n", rightrot(x,n));
    
    return 0;

}