#include <stdio.h>

#define MAX_SIZE 256

void escape(char*);

int main(){

  char s[MAX_SIZE];
  int i;
  for(i = 0; i < MAX_SIZE-1 && (s[i]=getchar())!=EOF; i++);
  s[i] ='\0';
  escape(s);
  

  return 0;
}

void escape(char* s){

  for(int j = 0; s[j] !='\0'; j++){
    switch(s[j]){
      case '\a':
        printf("\\a");
        break;
      case '\b':
        printf("\\b");
        break;
      case '\n':
        printf("\\n");
        break;
      case '\t':
        printf("\\t");
        break;
      default:
        printf("%c", s[j]);
    }
  }
}
