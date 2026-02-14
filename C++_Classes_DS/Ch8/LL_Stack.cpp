#include <iostream>

template <class DataType>
LL_Stack<DataType>::LL_Stack()
{

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
    if(top == NULL)
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