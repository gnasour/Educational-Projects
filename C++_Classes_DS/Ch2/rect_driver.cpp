#include "Rectangle.hpp"
#include <iostream>

struct Fraction{

    float numerator, denominator;

    Fraction operator+(Fraction & frac){

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

    Fraction operator *(Fraction & frac){
        
        Fraction temp;
        temp.numerator = numerator * frac.numerator;
        temp.denominator = denominator * frac.denominator;

        return temp;
    }

    bool operator >(Fraction & frac){

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
    
    Rectangle<float> r1;
    Rectangle<Fraction> r2;

    r1.setLength(5.6);
    r1.setWidth(4.7);

    Fraction len, width;

    len.numerator = 9;
    len.denominator = 18;
    
    width.numerator = 8;
    width.denominator = 48;

    r2.setLength(len);
    r2.setWidth(width);

    // Did the computations twice to ensure that functions w/ ref parameters don't 
    // incorrectly modify the dimensions of the Rectangle

    std::cout << "cmpSides() for r1: " << r1.cmpSides() << std::endl;
    std::cout << "cmpSides() for r2: " << r2.cmpSides() << std::endl;

    std::cout << "calcPerimeter for r1: " << r1.calcPerimeter() << std::endl;
    Fraction res = r2.calcPerimeter();
    std::cout << "calcPerimeter for r2: " << res.numerator << "/" << res.denominator << std::endl;
    
    std::cout << "calcArea for r1: " << r1.calcArea() << std::endl;
    res = r2.calcArea();
    std::cout << "CalcArea for r2: " << res.numerator << "/" << res.denominator << std::endl;

    std::cout << "cmpSides() for r1: " << r1.cmpSides() << std::endl;
    std::cout << "cmpSides() for r2: " << r2.cmpSides() << std::endl;

    std::cout << "calcPerimeter for r1: " << r1.calcPerimeter() << std::endl;
    res = r2.calcPerimeter();
    std::cout << "calcPerimeter for r2: " << res.numerator << "/" << res.denominator << std::endl;
    
    std::cout << "calcArea for r1: " << r1.calcArea() << std::endl;
    res = r2.calcArea();
    std::cout << "CalcArea for r2: " << res.numerator << "/" << res.denominator << std::endl;

    return 0;
}