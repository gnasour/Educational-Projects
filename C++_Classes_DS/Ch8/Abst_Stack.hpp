#ifndef ABST_STACK_HPP
#define ABST_STACK_HPP

template <class DataType>
class Abst_Stack
{
public:
    Abst_Stack();

    virtual Abst_Stack<DataType> & operator=(const Abst_Stack<DataType> & rval) = 0;

    virtual void push(DataType elem) = 0;
    virtual bool pop(DataType & poppedElem) = 0;
    virtual bool peek(DataType & peekedElem) = 0;
    virtual bool isEmpty() const = 0;
    virtual void makeEmpty() = 0;
private:
};


#endif