#include <stdio.h>
#include <stdlib.h>

#define DEFAULT_ROWS 10
#define MIN_TEMP 0
#define MAX_TEMP 100

void calculateTemp(int);
float tempFormula(float);
void printTable(float*,int);

int main(int argc, char**argv){
  if(argc > 1)
    calculateTemp(atoi(argv[1]));
  else
    calculateTemp(DEFAULT_ROWS);
  return 0;
}

void calculateTemp(int print_rows){
  float * temperatures = malloc(sizeof(float)*print_rows*2);
  for(int i = 0; i < print_rows*2; i+=2){
     temperatures[i] = (float)i*5;
     temperatures[i+1] = tempFormula(i*5);
  }
  printTable(temperatures, print_rows);
}

float tempFormula(float celcius){
  return ((celcius*9/5.0)+32);
}

void printTable(float* temperatures, int tempLen){
printf("==============\n");
printf("|");
printf("            |\n");
for(int i = 0; i < tempLen*2; i+=2){
  printf("|%.0f\t%.0f|\n",temperatures[i],temperatures[i+1]);
}
free(temperatures);
}
