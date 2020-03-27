#include <stdio.h>

#define UPPER 300
#define LOWER 0
#define STEP 20

int main()
{
    for(int fahrenheit = UPPER; fahrenheit > LOWER; fahrenheit-=STEP)
    {
        printf("%3d %6.1f\n", fahrenheit, (fahrenheit - 32)*(5.0/9));
    }
}