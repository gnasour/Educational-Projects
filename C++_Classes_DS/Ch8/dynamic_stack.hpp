#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

#include "LL_Stack.hpp"
#include "Array_Stack.hpp"


template <class DataType>
class Dynamic_Stack : public Abst_Stack()
{
public:
    Dynamic_Stack();

private:
    Abst_Stack *abst_st;

};

template <class DataType>
Dynamic_Stack<DataType>::Dynamic_Stack()
{
    if(sizeof(DataType) > 3*sizeof(DataType*)){
        abst_st = new LL_Stack;
    }
    else{
        abst_st = new Array_Stack;
    }
}

#endif