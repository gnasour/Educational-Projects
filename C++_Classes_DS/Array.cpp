#include <stdexcept>

template <class DataType>
Array<DataType>::Array(int size)
{
    if(size < 1){
        throw std::runtime_error("Bad size(Array(int)): " + size);
    }

    capacity = size;
    elements = new DataType[capacity];

}

template <class DataType>
Array<DataType>::Array(const Array<DataType> & rval)
{
    deepCopy(rval);
}

template <class DataType>
Array<DataType> & Array<DataType>::operator=(const Array<DataType> & rval)
{
    if(this == rval)
        return *this;
    
    delete [] elements;
    deepCopy(rval);

    return *this;
    
}

template <class DataType>
Array<DataType>::~Array()
{
    delete [] elements;
}

template <class DataType>
void Array<DataType>::changeSize(int newSize)
{
    if(newSize < 1){
        throw std::runtime_error("Bad size(changeSize(int)): " + newSize);
    }

    DataType *newArray = new DataType[newSize];

    int limit = (newSize>capacity) ? capacity : newSize;
    for(int i = 0; i < limit; i++){
        newArray[i] = elements[i];
    }

    delete [] elements;

    elements = newArray;
    capacity = newSize;

}

template <class DataType>
inline int Array<DataType>::length() const
{
    return capacity;
}

template <class DataType>
inline DataType& Array<DataType>::operator[](int index)
{
    if(index < 0 || index >= capacity){
        return dud;
    }

    return elements[index];

}

template <class DataType>
inline void Array<DataType>::deepCopy(const Array<DataType> & orig)
{
    capacity = orig.capacity;
    elements = new DataType[capacity];

    for(int i = 0; i < capacity; i++){
        elements[i] = orig.elements[i];
    }
}