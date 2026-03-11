#ifndef ARRAY_STACK_HPP
#define ARRAY_STACK_HPP

#include "Abst_Stack.hpp"


template <class DataType>
class Array_Stack : public Abst_Stack
{
public:

    Array_Stack();

    Array_Stack(const Array_Stack<DataType> & orig);
    Array_Stack<DataType> & operator=(const Array_Stack<DataType> & rval);
    ~Array_Stack();

    virtual void push(DataType elem);
    virtual bool pop(DataType & poppedElem);
    virtual bool peek(DataType & peekedElem);
    virtual bool isEmpty() const;
    virtual void makeEmpty();

private:

};



#endif