#include <stdio.h>
#define LIM 10
void main(){
int i=0;
char c;
char *s;
	while(i < LIM - 1)
	{
		if((c=getchar())!='\n')
		{
			if(c != EOF)
			{
				s[i];
				i++;
			}
		}
		else
		i= LIM;
	}

}