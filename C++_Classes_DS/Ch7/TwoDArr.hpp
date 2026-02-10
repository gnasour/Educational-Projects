

template <class DataType>
class TwoDArr
{
public:
    TwoDArr(int row, int col);

    void swapCol(int col1, int col2);
    void delCol(int row);
    void printArr();
private:
    DataType **twoDArr;
    int irow;
    int icol;
};

#include "TwoDArr.cpp"