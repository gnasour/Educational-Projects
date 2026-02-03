


template <class DataType>
CheckbookDynamic<DataType>::CheckbookDynamic()
{
    lastIndex = -1;
    numChecks = 0;
    lastChecks = new DataType[1];
    size = 1;
}

template <class DataType>
CheckbookDynamic<DataType>::CheckbookDynamic(float initBal)
{
    balance = initBal;
    lastIndex = -1;
    numChecks = 0;
    lastChecks = new DataType[1];
    size = 1;
}

template <class DataType>
void CheckbookDynamic<DataType>::setBalance(float amount)
{
    balance = amount;
}

template <class DataType>
bool CheckbookDynamic<DataType>::writeCheck(const DataType & amount)
{
    if(amount>balance)
        return false;
    
    balance -= amount;

    
    lastIndex++;
    lastChecks[lastIndex] = amount;
    numChecks++;

    if(numChecks >= size)
        doubleArray();


    return true;
}

template <class DataType>
void CheckbookDynamic<DataType>::deposit(float amount)
{
    balance += amount;
    lastDeposit = amount;
}

template <class DataType>
float CheckbookDynamic<DataType>::getBalance() const
{
    return balance;
}

template <class DataType>
DataType CheckbookDynamic<DataType>::getLastCheck() const
{
    return lastChecks[lastIndex];
}

template <class DataType>
DataType* CheckbookDynamic<DataType>::getChecks()
{
    DataType *checkCopy = new DataType[size];

    for(int i = 0; i < size; i++){
        checkCopy[i] = lastChecks[i];
    }

    return checkCopy;
}

template <class DataType>
CheckInfo<DataType> CheckbookDynamic<DataType>::getLastChecks() const
{
    CheckInfo<DataType> info;
    info.numChecks = numChecks;
    for(int i = 0, j = lastIndex; i < numChecks; i++, j--){
        if(j == -1)
            j = size - 1;
        info.checks[i] = lastChecks[j];
    }

    return info;
}

template <class DataType>
float CheckbookDynamic<DataType>::getLastDeposit() const
{
    return lastDeposit;
}

template <class DataType>
void CheckbookDynamic<DataType>::doubleArray()
{
    int newSize = size*2;
    DataType *newArray = new DataType[newSize];

    for(int i = 0; i < size; i++){
        newArray[i] = lastChecks[i];
    }

    delete [] lastChecks;
    lastChecks = newArray;
    size = newSize;
}