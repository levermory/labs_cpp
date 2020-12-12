#include <iostream>
#include "matrix.h"

template<class T>
int Matrix<T>::number = 0;

void task()
{
    Matrix matrix(4);
    Matrix matrix1(4);
    cout<<matrix;
    cout<<"+\n";
    cout<<matrix1;
    matrix+=matrix1;
    cout<<"=\n";
    cout<<matrix;
    cout<<"* 5 =\n";
    matrix*5;
    cout<<matrix;
}

int main() {

    task();
    return 0;
}

//007 019 023
//101 113 128
//201 217 221