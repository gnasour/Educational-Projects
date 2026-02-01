#include <iostream>

struct Fraction{

    float numerator, denominator;

    Fraction operator +(Fraction frac){

        if(denominator != frac.denominator){

            float temp_factor = denominator; // Save the denominator so we can multiply the second fraction
            numerator *= frac.denominator;
            denominator *= frac.denominator;
            frac.numerator *= temp_factor;
            frac.denominator *= temp_factor;
        }

        Fraction temp;
        temp.numerator = numerator + frac.numerator;
        temp.denominator = denominator;

        return temp;
    }

    Fraction operator *(Fraction frac){
        
        Fraction temp;
        temp.numerator = numerator * frac.numerator;
        temp.denominator = denominator * frac.denominator;

        return temp;
    }

    bool operator >(Fraction frac){
        if(denominator != frac.denominator){
            float temp_factor = denominator;
            numerator *= frac.denominator;
            denominator *= frac.denominator;
            frac.numerator *= temp_factor;
            frac.denominator *= temp_factor;
        }

        if(numerator > frac.numerator)
            return true;
        else
            return false;
    }

    Fraction operator *(int scalar){
        
        Fraction temp;
        temp.numerator = numerator*scalar;
        temp.denominator = denominator;

        return temp;
    }

};

Fraction operator *(int scalar, Fraction frac){

    Fraction scaled_frac;
    scaled_frac.numerator = frac.numerator*scalar;
    scaled_frac.denominator = frac.denominator;
    return scaled_frac;
}

int main()
{

    Fraction f1, f2;
    f1.numerator = 2;
    f1.denominator = 3;
    f2.numerator = 9;
    f2.denominator = 30;

    f1 = f1 + f2;
    std::cout << "f1 after adding f2\nNumerator: " << f1.numerator << " Denominator: " << f1.denominator << std::endl;
    f1 = f1 * 6;
    std::cout << "f1 after scalar multiplication with 6\nNumerator: " << f1.numerator << " Denominator: " << f1.denominator << std::endl;

    return 0;
}