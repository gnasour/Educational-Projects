struct Fraction{
    float numerator, denominator;

    Fraction operator +(Fraction frac){
        if(denominator != frac.denominator){
            
        }
    };
    Fraction operator *(Fraction frac);
    bool operator >(Fraction frac);
    Fraction operator *(int scalar);
};

Fraction operator *(int scalar, Fraction frac){
    Fraction scaled_frac;
    scaled_frac.numerator = frac.numerator*scalar;
    scaled_frac.denominator = frac.denominator;
    return scaled_frac;
}