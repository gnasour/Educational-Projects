#include <stdio.h>
#include <limits.h>
#include <float.h>

int main()
{
    //Integral types
    char c;
    short s;
    int i;
    long l;

    //Unsigned integral types
    unsigned char c;
    unsigned short s;
    unsigned int i;
    unsigned long l;


    // Floating point types
    float f;
    double d;
    long double ld;

    printf("                    MIN  MAX\n");
    
    //char
    printf("UNSIGNED CHAR RANGE: %d\t%d\n", 0, UCHAR_MAX);
    printf("SIGNED CHAR RANGE: %d\t%d\n", SCHAR_MIN, SCHAR_MAX);

    //short
    printf("UNSIGNED SHORT RANGE: %d\t%d\n", 0, USHRT_MAX);
    printf("SIGNED SHORT RANGE: %d\t%d\n", SHRT_MIN, SHRT_MAX);

    //int
    printf("UNSIGNED INT RANGE: %u\t%u\n", 0, UINT_MAX);
    printf("SIGNED INT RANGE: %d\t%d\n", INT_MIN, INT_MAX);

    //long
    printf("UNSIGNED LONG RANGE: %u\t%lu\n", 0, ULONG_MAX);
    printf("SIGNED LONG RANGE: %ld\t%ld\n", LONG_MIN, LONG_MAX);

    //float
    printf("FLOAT RANGE: %e\t%e\n", -FLT_MAX, FLT_MAX);

    //double
    printf("DOUBLE RANGE: %e\t%e\n", -DBL_MIN, DBL_MAX);

    //long double
    printf("LONG DOUBLE RANGE: %Le\t%Le\n", -LDBL_MIN, LDBL_MAX);
    
}