#include "matrix.h"

template<class T>
int Matrix<T>::number = 0;

template<class T>
void Show(T* array, int size)
{
    for (int i = 0; i < size; ++i) {
        cout<<array[i]<<'\n';
    }

}

int main() {
    vector<Matrix<int>> array(7, Matrix<int>(2));
    cout<<array;
    Matrix<int>* pointer_array[7];
    for (int i = 0; i < 7; ++i) {
        pointer_array[i] = &array[i];
    }
    Show(pointer_array, 7);

    return 0;
}