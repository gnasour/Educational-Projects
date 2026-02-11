#include <iostream>

template <class DataType>
LL_Stack<DataType>::LL_Stack()
{
    top = new DataType;
    top.next = NULL;
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

}