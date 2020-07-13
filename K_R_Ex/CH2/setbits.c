#include <stdio.h>

int getbits(unsigned x, int p, int n){
    return (x >> (p+1-n)) & ~(~0<<n);
}

int setbits(unsigned x, int p, int n, unsigned y){
    y = getbits(y, p, n);
    int bitarray[p+1-n];
    int temp_x = x;
    for(int i = 0; i < (p+1-n); i++){
        bitarray[i] = temp_x&1;
    }
    x >> p+1;
    for(int i = 0; i < n; i++){
        x<<1;
        x | (y & 1);
        y >> 1;
    }
    for(int i = p+1-n; i > 0; i--){
        x<<1;
        x | bitarray[i];
    }
    
}


//000001001
int main(){
    unsigned x, y;
    int n, p;
    printf("%d", getbits(0b10010101, 4, 3));
    return 0;
}