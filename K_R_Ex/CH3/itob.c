#include <stdio.h>


void itob(int, char*, int);
void strrev(char*);

int main(){
  char string[100];
  itob(19, string, 2);
  printf("%s\n", string);
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
void strrev(char* s){

  char temp = 0;
  int length;

  //Find the length of the string
  for(length = 0; s[length]!='\0'; length++);
  //printf("%d\n", length);
  //Reverse the string
  int i;
  for(i = 0; i < length/2; i++){
    printf("%d %d\n", i, length);
    temp = s[length - i -1];
    s[length - i -1]=s[i];
    s[i]=temp;
  }
}
    
