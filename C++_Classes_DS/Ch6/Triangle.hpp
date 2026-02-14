

class Triangle : public Shape
{
public:
    Triangle(float base, float height);
    virtual float calcArea();
protected:
//  You could write variables to captue the three side lengths, 
//  the ratios of which will depend on the class of triangle
private:
    float base;
    float height;
};