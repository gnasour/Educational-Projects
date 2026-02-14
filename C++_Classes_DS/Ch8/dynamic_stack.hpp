#ifndef DYNAMIC_STACK_HPP
#define DYNAMIC_STACK_HPP

#include "../Array.h"
#include "Abst_Stack.hpp"

// template <class DataType>
// struct DS_Node
// {
//     DataType element;
//     DS_Node *next;

// };

template <class DataType>
class Dynamic_Stack
{
public:
    Dynamic_Stack();

private:
    Abst_Stack *absts;
    // DS_Node<DataType> *head;
    // Array<DataType> *arr;
    // int top;
};

template <class DataType>
Dynamic_Stack::Dynamic_Stack()
{
    if(sizeof(DataType) > 3*sizeof(DataType*)){
        absts = new LL_Stack;
    }
    else{
        absts = new Array_Stack;
    }
}

#endif