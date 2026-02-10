#include "Shape.hpp"


class Quadrilateral : public Shape
{
public:
    Quadrilateral(float diag, float h1, float h2);
    void setNumSides(int numSides);
    virtual float calcArea();
protected:
private:
};