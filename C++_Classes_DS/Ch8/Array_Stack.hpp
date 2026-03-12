#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Abst_Stack.hpp"
#include "../Array.h"

template <class DataType>
class Array_Stack : public Abst_Stack
{
public:

    Array_Stack();

    virtual void push(DataType elem);
    virtual bool pop(DataType & poppedElem);
    virtual bool peek(DataType & peekedElem);
    virtual bool isEmpty() const;
    virtual void makeEmpty();

private:
    Array<DataType> elements;
    int top;
};

template <class DataType>
Array_Stack<DataType>::Array_Stack()
    : elements(2), top(-1)
{

}

template <class DataType>
void Array_Stack<DataType>::push(DataType elem)
{
    
}


#endif