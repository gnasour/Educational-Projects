#include <stdio.h>

void main(){
int c, wordLength=0;
int freq [10]={0};
while((c = getchar())!=EOF){
	if(c == ' ' || c == '\t' || c == '\n'){
		++freq[wordLength];
		wordLength = 0;
		
	 }

	else{
	putchar(c);
	wordLength++;
	 }

	}
	printf("\n");
	int i = 0, stars;
	for(i;i < 10; i++){
		printf("Word Length %d: ", i);
		stars = freq[i];
		for(stars; stars > 0; stars--)
			printf(" *");
			printf("\n");
	}
}