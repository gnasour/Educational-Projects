#include <stdio.h>



unsigned invert(unsigned x, int n, int p){

  int bit_array[p];
  for(int i = 0; i < p; i++){
    bit_array[i] = x&1;
    x >> 1;
  }
  for(int i = p; i > p-n; i--){
    x<<1;
    x | (~bit_array[i]);
  }
  for(int i = p-n; i > 0; i--){
    x<<1;
    x | bit_array[i];
  }
  return x;

  
}


int main(){

  unsigned x;
  int n,p;
  x = 49;
  n = 3;
  p = 4;
  printf("%u\n", invert(x,n,p));
  return 0;
}
