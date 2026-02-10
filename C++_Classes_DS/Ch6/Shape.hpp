#ifndef SHAPE_HPP
#define SHAPE_HPP

class Shape
{
public:
    Shape();
    void setIntAngle(float intAngle);
    virtual float calcArea() = 0;
protected:
    float area;
    float intAngle;
    int numSides;
private:
};

#endif