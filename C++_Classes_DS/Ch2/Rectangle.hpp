template <class DataType>
class Rectangle
{
public:
    Rectangle();
    Rectangle(DataType length, DataType width);

    void setLength(DataType length);
    void setWidth(DataType width);

    bool cmpSides();

    DataType calcPerimeter() ;
    DataType calcArea() ;

private:
    DataType length, width;
};

#include "Rectangle.cpp"