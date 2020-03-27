#include <stdio.h>

#define UPPER 300 //Upper limit of Celsius
#define LOWER 0   //Lower limit of Celsius
#define STEP 20   //Increment operand for Celsius

void calculate_cel_to_far()
{

    int celcius = LOWER;
    for (celcius; celcius < UPPER; celcius += STEP)
    {
        printf("%3d\t%6.1f\n", celcius, (9.0 / 5) * celcius + 32);
    }
}

int main()
{
    calculate_cel_to_far();
}