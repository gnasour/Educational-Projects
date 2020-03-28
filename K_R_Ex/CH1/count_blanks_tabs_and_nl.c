#include <stdio.h>

int main(){

	//Temp variable to retrieve next input from STDIN
	char c;

	//Integer variables that count the number of blanks/tabs/new lines
	int new_line = 0;
	int tab = 0;
	int blanks = 0;

	while((c = getchar())!=EOF){
		if(c == '\t')
			tab++;
		else if(c == '\n')
			new_line++;
		else if(c == ' ')
			blanks++;
	}

	printf("Number of blanks: %d\n", blanks);
	printf("Number of tabs: %d\n", tab);
	printf("Number of new lines: %d\n", new_line);
}