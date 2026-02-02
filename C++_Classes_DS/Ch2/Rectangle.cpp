template <class DataType>
Rectangle<DataType>::Rectangle()
{

}

template <class DataType>
Rectangle<DataType>::Rectangle(DataType length, DataType width)
{
    this->length = length;
    this->width = width;
}


template <class DataType>
void Rectangle<DataType>::setLength(DataType length)
{
    this->length = length;
}

template <class DataType>
void Rectangle<DataType>::setWidth(DataType width)
{
    this->width = width;
}

// Return true if length > width
template <class DataType>
bool Rectangle<DataType>::cmpSides()
{
    return (length > width);
}

template <class DataType>
DataType Rectangle<DataType>::calcPerimeter() 
{
    DataType temp_length = length * 2;
    DataType temp_width = width * 2;
    return temp_length + temp_width;
}

template <class DataType>
DataType Rectangle<DataType>::calcArea() 
{
    return length*width;
}