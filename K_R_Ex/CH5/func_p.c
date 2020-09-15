#include <stdio.h>


void printf_stuff(){
    printf("Hello world");
}

void call_print(void (*printer)()){
    printer();
}

int main(){
    call_print((void (*)())printf_stuff);
    return 0;
}