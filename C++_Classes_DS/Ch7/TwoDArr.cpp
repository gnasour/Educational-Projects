#include <iostream>

template <class DataType>
TwoDArr<DataType>::TwoDArr(int row, int col)
{
    twoDArr = new DataType* [row];
    for(int i = 0; i < row; i++){
        twoDArr[i] = new DataType[col];
    }

    for(int i = 0; i < row; i++){
        for(int j = 0; j < col; j++){
            twoDArr[i][j] = i*(j+i);
        }
    }

    irow = row;
    icol = col;
}


template <class DataType>
void TwoDArr<DataType>::swapCol(int col1, int col2)
{
    DataType *temp = twoDArr[col1];
    twoDArr[col1] = twoDArr[col2];
    twoDArr[col2] = temp;
}

template <class DataType>
void TwoDArr<DataType>::delCol(int row)
{
    delete [] twoDArr[row];

    // Readjust row elements
    DataType **tempArr;
    tempArr = new DataType* [irow-1];
    for(int i = 0, tempInd = 0; i < irow; i++){
        
        if(i == row)
            continue;

        tempArr[tempInd] = twoDArr[i];
        tempInd++;

    }

    delete [] twoDArr; // Delete the row elements
    twoDArr = tempArr; // Our array now points to the new, resized array
    --irow;  // Update row size
}

template<class DataType>
void TwoDArr<DataType>::printArr()
{
    for(int i = 0; i < irow; i++){
        for(int j = 0; j < icol; j++){
            std::cout << twoDArr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}