#include "Shape.hpp"


class Trapezoid : public Shape
{
public:
    Trapezoid(float base_1, float base_2, float height);
    virtual float calcArea();
protected:
private:
};