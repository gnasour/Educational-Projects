#include <stdio.h>

#define MAX_SIZE 256

void escape(char*);
void escape_reverse(char*);

int main(){

  char s[MAX_SIZE];
  int i;
  for(i = 0; i < MAX_SIZE-1 && (s[i]=getchar())!=EOF; i++);
  s[i] ='\0';
  escape_reverse(s);
  

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


void escape_reverse(char* s){
  for(int i = 0; s[i] != '\0'; i++){
    if(s[i] == '\\'){
      i++;
      switch(s[i]){
        case 'a':
          printf("\a");
          break;
        case 'b':
          printf("\b");
          break;
        case 'n':
          printf("\n");
          break;
        case 't':
          printf("\t");
          break;
        default:
          break;
      }
    }else{
      printf("%c", s[i]);
    }
  }
}
