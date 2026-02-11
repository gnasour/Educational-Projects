#include <iostream>

template <class DataType>
LL_Stack<DataType>::LL_Stack()
{
    top = new Node<DataType>;
    top->next = NULL;
}


template <class DataType>
LL_Stack<DataType>::LL_Stack(const LL_Stack<DataType> & rval)
{
    deepCopy(rval);
}

template <class DataType>
LL_Stack<DataType> & LL_Stack<DataType>::operator=(const LL_Stack<DataType> & rval)
{
    deepCopy(rval);
}

template <class DataType>
LL_Stack<DataType>::~LL_Stack()
{
    std::cout << "destructor called" << std::endl;
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
bool LL_Stack<DataType>::isEmpty()
{
    if(top == NULL)
        return true;
    else
        return false;
}

template <class DataType>
void LL_Stack<DataType>::makeEmpty()
{

}