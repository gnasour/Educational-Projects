#include <stdio.h>

main(){
int c;
while ((c = getchar()) != EOF)
{
	if(c == '\t'){
	//printf("\\t");
	putchar('\\');
	putchar('t');
	}
	else if(c == '\n'){
	//printf("\\n");
	putchar('\\');
	putchar('n');
	}
	else if(c == '\b'){
	//printf("\\b");
	putchar('\\');
	putchar('b');
	}
	else
	putchar(c);
	printf("\n");

	
}

}