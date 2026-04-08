#ifndef HEAP_PRIO_QUEUE_H
#define HEAP_PRIO_QUEUE_H


#include "../Array.h"

template <class T>
class HeapPriorityQueue
{
public:
    HeapPriorityQueue()
        : elements(2), heapSize(0)
    {
    }
    
    HeapPriorityQueue(const Array<T> & arrCopy)
        : elements(arrCopy), heapSize(arrCopy.length())
    {
        for(int i = ((heapSize - 2) >> 1); i >= 0; i--){
            heapify(i);
        }

        int tryPower = 2;
        for(; tryPower < elements.length(); tryPower <<= 1){
            // Just need the condition
            ; 
        }

        if(tryPower != elements.length()){
            elements.changeSize(tryPower);
        }
    }


    void enqueue(const T & newElem)
    {
        if(heapSize == elements.length()){
            elements.changeSize(elements.length() << 1);
        }

        int i = heapSize;
        for(; (i != 0) && newElem > elements[((i-1) >> 1)]; i = ((i-1) >> 1)){
            elements[i] = elements[((i-1) >> 1)];
        }

        elements[i] = newElem;
        heapSize++;
    }

    bool dequeue(T & remElem)
    {
        if(heapSize == 0){
            return false;
        }

        // Dequeue the root (highest prio)
        remElem = elements[0];
        heapSize--;
        // Swap root with right-most child
        elements[0] = elements[heapSize];
        // Enforce heap rules
        heapify(0);

        int trySize = elements.length();
        while((heapSize <= (trySize >> 2)) && trySize > 2){
            trySize >>= 1;
        }

        if(trySize < elements.length()){
            try{
                elements.changeSize(trySize);
            }
            catch(...){}
        }

        return true;
    }

    bool isEmpty() const
    {
        return !heapSize;
    }

    void makeEmpty()
    {
        heapSize = 0;
        try{
            elements.changeSize(2);
        }
        catch(...){}
    }

private:
    Array<T> elements;
    int heapSize;

    inline void heapify(int ind)
    {
        int lChild, rChild, largest;
        bool stop = false;
        T temp = elements[i];
        
        lChild = (i << 1) + 1;
        while(lChild < heapSize && !stop){
            rChild = lChild + 1;
            largest = (rChild == heapSize) ? lChild :
                ((elements[lChild] > elements[rChild]) ? lChild : rChild);
            
            if(elements[largest] > temp){
                elements[i] = elements[largest];
                i = largest;
                lChild = (i << 1) + 1;
            }
            else{
                stop = true;
            }
        }

        elements[i] = temp;
    }
};



#endif