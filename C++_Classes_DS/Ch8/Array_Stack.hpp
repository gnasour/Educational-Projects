#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Abst_Stack.hpp"
#include "../Array.h"

template <class DataType>
class Array_Stack : public Abst_Stack
{
public:
    Array_Stack();
    Array_Stack(const Array_Stack<DataType> & original);
    ~Array_Stack();
    Array_Stack<DataType> & operator=(const Array_Stack<DataType> & rval);

    virtual void push(DataType elem);
    virtual bool pop(DataType & poppedElem);
    virtual bool peek(DataType & peekedElem);
    virtual bool isEmpty() const;
    virtual void makeEmpty();

private:
    void testToShrink();   // These two functions dynamically change the length of the array
    void testToGrow();     // depending on a constant factor of the ratio (top/elements.length())
    inline void deepCopy(const Array_Stack<DataType> & ap);

    Array<DataType> *elements;
    int top;

};

template <class DataType>
Array_Stack<DataType>::Array_Stack()
{
    elements = new Array<DataType>(2);
    top = -1;
}

template <class DataType>
Array_Stack<DataType>::Array_Stack(const Array_Stack<DataType> & original)
{
    deepCopy(original);
}

template <class DataType>
Array_Stack<DataType>::~Array_Stack()
{
    delete elements;
}

template <class DataType>
Array_Stack<DataType> & Array_Stack<DataType>::operator=(const Array_Stack<DataType> & rval)
{
    if(this == &rval){
        return *this;
    }

    delete elements;
    deepCopy(rval);

    return *this;
}

template <class DataType>
inline void Array_Stack<DataType>::deepCopy(const Array_Stack<DataType> & ap)
{
    top = ap.top;
    elements = ap.elements;
}

template <class DataType>
void Array_Stack<DataType>::testToGrow()
{
    if(++top == elements.length()){
        elements.changeSize(elements.length()<<1); // Double the capacity each time the array is full
    }
}

template <class DataType>
void Array_Stack<DataType>::testToShrink()
{
    int trySize = elements.length();
    while( ((top+1) <= (trySize >> 2)) && trySize > 2){
        trySize >>= 1;
    }

    if(trySize < elements.length()){
        try{
            elements.changeSize(trySize);
        }
        catch(...){}
    }
    
}

template <class DataType>
void Array_Stack<DataType>::push(DataType elem)
{
    testToGrow();

    elements[top] = elem;
}

template <class DataType>
bool Array_Stack<DataType>::pop(DataType & poppedElem)
{
    if(top == -1){
        return false;
    }

    poppedElem = elements[top];
    top--;

    testToShrink();

    return true;
}

template <class DataType>
bool Array_Stack<DataType>::peek(DataType & topElem)
{
    if(top == -1){
        return false;
    }

    topElem = elements[top];

    return true;
}

template <class DataType>
bool Array_Stack<DataType>::isEmpty() const
{
    return top == -1;
}

template <class DataType>
void Array_Stack<DataType>::makeEmpty()
{
    delete elements;
    top = -1; 
}


#endif