#include <stdio.h>

float fahr_to_cels(float fahr)
{
    return (5/9.0)*(fahr-32.0);
}

int main()
{
    float fahr;

    for(fahr = 0; fahr <= 200; fahr += 20){
        printf("%3.0f\t%6.1f\n", fahr, fahr_to_cels(fahr));
    }

}