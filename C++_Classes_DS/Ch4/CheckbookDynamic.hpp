
template <class DataType>
struct CheckInfo{
    int numChecks;
    DataType *check = new DataType[1];
};


template <class DataType>
class CheckbookDynamic
{
public:
    CheckbookDynamic();
    CheckbookDynamic(float initBal);

    void setBalance(float amount);
    bool writeCheck(const DataType & amount);
    void deposit(float amount);
    float getBalance() const;
    DataType getLastCheck() const;
    DataType* getChecks();
    CheckInfo<DataType> getLastChecks() const;
    float getLastDeposit() const;

private:
    float balance;
    int numChecks;
    int lastIndex;
    DataType *lastChecks;
    int size;
    float lastDeposit;

    void doubleArray();
};


#include "CheckbookDynamic.cpp"