#include "../Array.h"
#include "../Ch10/LinkedList.h"


template <class T>
class HashTable
{
public:
    HashTable(int (*hf)(const T & key), int size);

    bool insert(const T & newObject);
    bool retrieve(T & retrieved);
    bool remove(T & removed);
    bool update(T & updateObject);
    void makeEmpty();

private:
    Array<LinkedList<T>> hashTable;
    int (*hashFunction)(const T & key);

};

template <class T>
HashTable<T>::HashTable(int (*hf)(const T & key), int size)
    : hashTable(size)
{
    hashFunction = hf;
}

template <class T>
bool HashTable<T>::insert(const T & newObject)
{
    
}