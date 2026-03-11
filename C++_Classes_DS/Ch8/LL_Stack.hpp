#ifndef LL_STACK_HPP
#define LL_STACK_HPP

#include "Abst_Stack.hpp"
#include <iostream>

template <class DataType>
struct Node
{
    DataType val;
    Node<DataType> *next;
};

template <class DataType>
class LL_Stack : public Abst_Stack<DataType>
{
public:
    LL_Stack();

    LL_Stack(const LL_Stack<DataType> & rval);
    LL_Stack<DataType> & operator=(const LL_Stack<DataType> & rval);
    ~LL_Stack();

    virtual void push(DataType elem);
    virtual bool pop(DataType & poppedElem);
    virtual bool peek(DataType & peekedElem);
    virtual bool isEmpty() const;
    virtual void makeEmpty();

private:
    Node<DataType> *top;

    inline void deepCopy(const LL_Stack<DataType> & ap);

};


template <class DataType>
LL_Stack<DataType>::LL_Stack()
{
    top = nullptr;
}


template <class DataType>
LL_Stack<DataType>::LL_Stack(const LL_Stack<DataType> & rval)
{
    deepCopy(rval);
}

template <class DataType>
LL_Stack<DataType> & LL_Stack<DataType>::operator=(const LL_Stack<DataType> & rval)
{
    if(this==rval)
        return *this;

    makeEmpty();
    deepCopy(rval);
    return *this;
}

template <class DataType>
LL_Stack<DataType>::~LL_Stack()
{
    std::cout << "destructor called" << std::endl;
    makeEmpty();
}

template <class DataType>
void LL_Stack<DataType>::push(DataType elem)
{
    Node<DataType> *temp = new Node<DataType>;
    temp->val = elem;
    temp->next = top;
    top = temp;
}

template <class DataType>
bool LL_Stack<DataType>::pop(DataType & poppedElem)
{
    if(isEmpty())
        return false;

    poppedElem = top->val;
    
    Node<DataType> *temp = top;
    top = top->next;
    delete temp;

    return true;
}

template <class DataType>
bool LL_Stack<DataType>::peek(DataType & peekedElem)
{
    if(isEmpty())
        return false;
    
    peekedElem = top->val;
    
    return true;
}

template <class DataType>
bool LL_Stack<DataType>::isEmpty() const
{
    if(top == nullptr)
        return true;
    else
        return false;
}

template <class DataType>
void LL_Stack<DataType>::makeEmpty()
{
    while(top->next){
        Node<DataType> *temp = top;
        top = top->next;
        delete temp;
    }

    delete top;
}

#endif