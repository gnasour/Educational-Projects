#include <stdio.h>
#include <string.h>

void itob(int, char*, int);

int main(){
  char string[100];
  itob(8, string, 2);
  printf("%s", string);
  return 0;
}

void itob(int n, char* s, int b){

    int i = 0;
    char sign = 0;
    
    if(n < 0){
        n = ~n;
        sign = '1';
    }

    do{

      s[i++] = n%b + '0';
        
    }while((n/=b) > 0);
    
    if(sign){
        s[i++] = '-';
    }
    s[i++] = '\0';
    strrev(s);

}
