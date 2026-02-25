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
    start = new Node<T>;
    start->next = nullptr;
}

template <class T>
LinkedList<T>::LinkedList(const LinkedList<T> & ap)
{
    deepCopy(ap);
}

template <class T>
LinkedList<T>::~LinkedList()
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
LinkedList<T> & LinkedList<T>::operator=(const LinkedList<T> & rval)
{
    if(rval == *this)
        return *this;
        
    makeEmpty();
    deepCopy(rval);
    return *this;
}

template <class T>
void LinkedList<T>::insert(const T & elem)
{
    Node<T> *newNode = new Node<T>;
    newNode->data = elem;
    newNode->next = nullptr;

    Node<T> *temp;
    if(current != nullptr){
        temp = current;
    }
    else{
        temp = start;
    }

    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->next = newNode;

}

template <class T>
bool LinkedList<T>::first(T & elem)
{
    return start->data;
}

#endif