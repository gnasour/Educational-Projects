#include "Shape.hpp"
#include "Triangle.hpp"

Triangle::Triangle(float base, float height)
: Shape(), base(base), height(height)
{
    
}

float Triangle::calcArea()
{
    return 0.5*base*height;
}


int main()
{
    Shape s = new Triangle(2,3);
}