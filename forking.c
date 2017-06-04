/*
 *Example of forking
 *Comment out the exit function 
 *to see how it runs in both processes
 */

#include <stdlib.h>
#include <sys/types.h>
#include <stdio.h>

void main(){
pid_t pid = fork();

if(pid > 0){
printf("Hello\n");
exit(0);
}
wait();

printf("World\n");

}