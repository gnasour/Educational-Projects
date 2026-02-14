#include "LL_Stack.hpp"

int main()
{
    LL_Stack<int> *lls = new LL_Stack<int>;

    for(int i = 0; i < 5; i++){
        lls->push(i);
    }
    for(int i = 0; i < 5; i++){
        int x;
        lls->pop(x);
        std::cout << x << " ";
    }
    std::cout << std::endl;
    delete lls;
    return 0;
}