#ifndef LINKED_LIST
#define LINKED_LIST

template <class T>
struct Node
{
    T data;
    Node<T> *next;
};

template <class T>
class LinkedList
{
public:
    //Constructors
    LinkedList();
    LinkedList(const LinkedList<T> & ap);
    ~LinkedList();
    LinkedList<T> & operator=(const LinkedList<T> & rval);

    //Methods
    void insert(const T & elem);
    bool first(T & elem);
    inline bool getNext(T & elem);
    bool find(const T & elem);
    bool retrieve(T & elem);
    bool replace(const T & newElem);
    bool remove(T & elem);
    bool isEmpty() const;
    void makeEmpty();

private:
    Node<T> *start;
    Node<T> *current;
    
    inline void deepCopy(const LinkedList<T> & original);

};

template <class T>
LinkedList<T>::LinkedList()
{
    start = current = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & ap)
{
    deepCopy(ap);
}

template <class T>
LinkedList<T>::~LinkedList()
{
    makeEmpty();
}

template <class T>
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rval)
{
    if(this == &rval)
        return *this;
        
    makeEmpty();
    deepCopy(rval);
    return *this;
}

template <class T>
LinkedList<T>::makeEmpty()
{
    Node<T> *temp;
    while(start->next != nullptr){
        temp = start;
        start = start->next;
        delete temp;
    }
    
    delete start;
}

template <class T>
void LinkedList<T>::insert(const T & elem)
{
    current = nullptr;

    Node<T> *newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = start;

    start = newNode;

}

template <class T>
bool LinkedList<T>::first(T & elem)
{
    if(start == nullptr)
        return false;
    
    current = start;
    elem = start->data;
    return true;

}

template <class T>
inline bool LinkedList<T>::getNext(T & elem)
{
    if(current == nullptr)
        return false;
    if(current->next == nullptr){
        current = nullptr;
        return false;
    }

    current = current->next;
    elem = current->data;
    return true;

}

template <class T>
bool LinkedList<T>::find(const T & elem)
{
    T item;

    if(!first(item)){
        return false;

    }

    do{
        if(item == elem){
            return true;
        }

    }while(getNext(item));

    return false;


}

template <class T>
bool LinkedList<T>::retrieve(T & elem)
{
    if(!find(elem))
        return false;
    

    // Test to see if code works without the following line (I expect its redundent)
    //element = current->data;
    return true;

}

template <class T>
bool LinkedList<T>::replace(const T & newElem)
{
    if(current == nullptr)
        return false;
    
    current->data = newElem;
    return true;

}

template <class T>
bool LinkedList<T>::remove(T & elem)
{
    current = nullptr;

    if(start == nullptr)
        return false;
    
    Node<T> *ptr = start;

    if(ptr->data == elem){
        // Again, might be redundent
        //elem = ptr->data;
        start = start->next;
        delete ptr;
        return true;
    }

    while(ptr->next != nullptr){
        if(ptr->next->data == elem){
            Node<T> *temp = ptr->next;
            //elem = temp->data;
            ptr->next = temp->next;
            delete temp;
            return true;
        }
        ptr = ptr->next;
    }

    return false;


}

#endif