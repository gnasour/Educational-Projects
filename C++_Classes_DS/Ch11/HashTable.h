#ifndef HASH_TABLE_H
#define HASH_TABLE_H

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
    int location = hashFunction(newObject);
    
    if(location < 0 || location >= hashTable.length()){
        return false;
    }

    hashTable[location].insert(newObject);

    return true;
}

template <class T>
bool HashTable<T>::retrieve(T & retreived)
{
    int location = hashFunction(retreived);

    if(location < 0 || location >= hashTable.length()){
        return false;
    }

    if(!hashTable[location].retrieve(retreived)){
        return false;
    }

    return true;
}


template <class T>
bool HashTable<T>::remove(T & removed)
{
    int location = hashFunction(removed);

    if(location < 0 || location >= hashTable.length()){
        return false;
    }

    if(!hashTable[location].remove(removed)){
        return false;
    }

    return true;
}

template <class T>
bool HashTable<T>::update(T & updated)
{
    int location = hashFunction(updated);

    if(location < 0 || location >= hashTable.length()){
        return false;
    }

    if(!hashTable[location].find(updated)){
        return false;
    }

    hashTable[location].replace(updated);

    return true;
}

template <class T>
void HashTable<T>::makeEmpty()
{
    for(int i = 0; i < hashTable.length(); i++){
        hashTable[i].makeEmpty();
    }
}

#endif