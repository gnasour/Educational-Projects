#ifndef ARRAY_H
#define ARRAY_H


template <class DataType>
class Array
{
public:
    Array(int size);

    Array(const Array<DataType> & rval);
    Array<DataType> & operator=(const Array<DataType> & rval);
    ~Array();

    inline DataType & operator[](int index);
    void changeSize(int newSize);
    inline int length() const;

private:
    DataType *elements;
    int capacity;
    DataType dud;
    inline void deepCopy(const Array<DataType> & ap);

};

#include "Array.cpp"

#endif