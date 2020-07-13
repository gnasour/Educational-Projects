#include <stdio.h>


void del_char(char* s, int del_index){
	for(int i = del_index; s[i] != '\0'; i++){
		s[i] = s[i+1];
	}
}
void squeeze(char* s1, char* s2){

	for(int i = 0; s1[i] != '\0'; i++){
		for(int j = 0; s2[j] != '\0'; j++){
			if(s1[i] == s2[j]){
				del_char(s1, i);
			}
		}
	}

}

int main(){
	char line[10] = {'h', 'i', 'w', 'o', 'r', 'l', 'd','\0'};
	char del[4] = {'i', 'r', 'd', '\0'};
	
	squeeze(line, del);
	printf("%s", line);
	return 0;
	}