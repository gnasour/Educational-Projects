#ifndef LL_STACK_HPP
#define LL_STACK_HPP


template <class DataType>
struct Node
{
    DataType val;
    Node *next;
};

template <class DataType>
class LL_Stack
{
public:
    LL_Stack();

    LL_Stack(const LL_Stack<DataType> & rval);
    LL_Stack<DataType> & operator=(const LL_Stack<DataType> & rval);
    ~LL_Stack();

    void push(DataType elem);
    bool pop(DataType & poppedElem);
    bool peek(DataType & peekedElem);
    bool isEmpty() const;
    void makeEmpty();
private:
    Node<DataType> *top;
    inline void deepCopy(const LL_Stack<DataType> & ap);
};

#include "LL_Stack.cpp"

#endif