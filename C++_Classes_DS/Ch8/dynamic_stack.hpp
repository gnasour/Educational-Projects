#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

#include "LL_Stack.hpp"
#include "Array_Stack.hpp"
#include <iostream>

template <class DataType>
class Dynamic_Stack
{
public:
    Dynamic_Stack();

private:
    Abst_Stack<DataType> *abst_st;

};

template <class DataType>
Dynamic_Stack<DataType>::Dynamic_Stack()
{
    if(sizeof(DataType) > 3*sizeof(DataType*)){
        abst_st = new LL_Stack<DataType>();
        std::cout << "Making LL Stack" << std::endl;
    }
    else{
        abst_st = new Array_Stack<DataType>();
        std::cout << "Making Array Stack" << std::endl; 
    }
}

#endif