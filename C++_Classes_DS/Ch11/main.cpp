#include "HashTable.h"
#include <iostream>
#include <string>

const int SIZE1 = 97;
const int SIZE2 = 199;


struct TestNode{

    std::string str;
    int num;

    bool operator==(const TestNode & rval) { return str == rval.str; }

};

int hash1(const TestNode & obj)
{
    int sum = 0;
    for(int i = 0; i < 3 && i < (int) obj.str.length(); i++){
        sum += obj.str[i];
    }

    return sum % SIZE1;
}

int hash2(const TestNode & obj)
{
    int sum = 0;
    for(int i = ((int)obj.str.length() - 1); 
        i > -1 && i > ((int)obj.str.length() - 7); 
            i--)
            {
                sum += obj.str[i];
            }
    
    return sum % SIZE2;
}

int main()
{
    HashTable<TestNode> ht1(hash1, SIZE1);
    HashTable<TestNode> ht2(hash2, SIZE2);

    TestNode testObj;

    testObj.str = "elephant";
    testObj.num = 25;
    ht1.insert(testObj);

    testObj.str = "giraffe";
    testObj.num = 50;
    ht2.insert(testObj);

    TestNode testObj2;

    testObj2.str = "elephant";
    ht1.retrieve(testObj2);
    std::cout << "retreived from ht1: " << testObj2.num << " for num." << std::endl;

    testObj2.str = "giraffe";
    ht2.retrieve(testObj2);
    std::cout << "retreived from ht2: " << testObj2.num << " for num." << std::endl;

    ht1.makeEmpty();
    ht2.makeEmpty();

    return 0;
}