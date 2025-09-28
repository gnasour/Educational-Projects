#include <stdio.h>

int main()
{
  float fahr, celsius;
  int lower, upper, step;

  lower = 0;
  upper = 300;
  step = 20;


  fahr = lower;
  printf("Fahrenheit\tCelsius\n");    /* Header */
  while(celsius <= upper){
    //celsius = (5.0/9)*(fahr - 32);
    fahr = (9.0/5) * celsius + 32;
    printf("%6.1f\t\t    %3.0f\n", fahr, celsius);
    celsius += step;
  }
}
