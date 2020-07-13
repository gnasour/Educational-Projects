#include <stdio.h>

#define MAX_LENGTH 1000

void escape(const char* s, int length){
    for(int i = 0; i < length && s[i] != '\0'; i++){
        swtich(s[i]){
            case '\t':
                printf("\\t");
                break;
            case '\n':
                printf("\\n");
                break;
            default:
                printf("%c", s[i]);
        }
    }
}

int main(void){
    char s[MAX_LENGTH];
    escape(s, MAX_LENGTH);
    return 0;
    }