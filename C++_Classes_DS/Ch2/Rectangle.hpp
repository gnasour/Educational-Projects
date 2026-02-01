template <class DataType>
class Rectangle
{
public:
    void setLength(DataType length);
    void setWidth(DataType width);

    bool cmpSides();

    DataType calcPerimeter();
    DataType calcArea();

private:
    DataType length, width;
};

#include "Rectangle.cpp"