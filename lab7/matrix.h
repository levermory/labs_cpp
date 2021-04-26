//
// Created by levermory on 12/14/20.
//

#ifndef LAB7_MATRIX_H
#define LAB7_MATRIX_H

#include <iostream>
#include <vector>
#include <string>

using namespace std;

template<class T = double>
class Matrix
{
    int size;
    vector<vector<T>> data;
    string name;
    static int number;
public:
    Matrix();
    explicit Matrix(int);
    string getname();
    int getsize();

    Matrix<T> operator+(Matrix&);
    Matrix<T> operator-(Matrix&);
    Matrix<T> operator*(int);
    Matrix<T> operator/(int);
    Matrix<T> operator+=(Matrix&);
    Matrix<T> operator-=(Matrix&);
    Matrix<T> operator*=(int);
    Matrix<T> operator/=(int);
    Matrix<T> operator*(Matrix&);
    Matrix<T> operator*=(Matrix&);
    vector<T>& operator[](int);
    bool operator==(Matrix&);
    bool operator!=(Matrix&);
    friend istream& operator>>(istream& in, Matrix<T>& matrix)
    {
        for(int i=0; i<matrix.size; ++i){
            for (int j=0; j<matrix.size; ++j) {
                in>>matrix.data[i][j];
            }
        }
        return in;
    }
    friend ostream& operator<<(ostream& out, Matrix<T>& matrix)
    {
        out<<matrix.getname()<<"\n";
        for(int i=0; i<matrix.size; ++i){
            for (int j = 0; j<matrix.size; ++j) {
                out<<matrix.data[i][j]<<" ";
            }
            out<<"\n";
        }
        return out;
    }

    vector<T> row(int);
    vector<T> col(int);

    T sum(vector<T>); // надоело 😭😭
};

template<class T>
Matrix<T>::Matrix(): size(50)
{
    data.resize(50);
    for(int i=0; i<50; ++i){
        data[i].resize(50);
        for(int j=0; j<50; ++j){
            data[i][j] = rand()%10;
        }
    }
    ++number;
    name = "matrix" + to_string(number);
}

template<class T>
Matrix<T>::Matrix(int _size): size(_size)
{
    data.resize(size);
    for(int i=0; i<size; ++i){
        data[i].resize(size);
        for(int j=0; j<50; ++j){
            data[i][j] = rand()%10;
        }
    }
    ++number;
    name = "matrix" + to_string(number);
}

template<class T>
string Matrix<T>::getname(){
    return name;
}

template<class T>
int Matrix<T>::getsize()
{
    return size;
}

template<class T>
Matrix<T> Matrix<T>::operator+(Matrix& matr) {
    if(size != matr.size) throw invalid_argument("wrong dimensions");
    Matrix<T> result(size);
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] + matr.data[i][j];
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator-(Matrix& matr) {
    if(size != matr.size) throw invalid_argument("wrong dimensions");
    Matrix<T> result(size);
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            result.data[i][j] = data[i][j] - matr.data[i][j];
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(int num) {
    Matrix<T> result(size);
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            result.data[i][j]=data[i][j]*num;
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator/(int num) {
    Matrix<T> result(size);
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            result.data[i][j]=data[i][j]/num;
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator+=(Matrix& matr) {
    if(size != matr.size) throw invalid_argument("wrong dimensions");
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            data[i][j] += matr.data[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator-=(Matrix& matr) {
    if(size != matr.size) throw invalid_argument("wrong dimensions");
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            data[i][j] -= matr.data[i][j];
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator*=(int num) {
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            data[i][j] *= num;
        }
    }
    return *this;
}

template<class T>
Matrix<T> Matrix<T>::operator/=(int num) {
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            data[i][j] /= num;
        }
    }
    return *this;
}

template<class T>
bool Matrix<T>::operator==(Matrix& matr) {
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            if(data[i][j] != matr.data[i][j])
                return false;
        }
    }
    return true;
}

template<class T>
bool Matrix<T>::operator!=(Matrix& matr) {
    for(int i=0; i<size; ++i){
        for (int j = 0; j < size; ++j) {
            if(data[i][j] != matr.data[i][j])
                return true;
        }
    }
    return false;
}

template<class T>
ostream& operator<<(ostream& out, vector<T> vector)
{
    for(int i=0; i<vector.size(); ++i){
        out<<vector[i]<<' ';
    }
    return out;
}

template<class T>
vector<T> Matrix<T>::row(int i) {
    return data[i];
}

template<class T>
vector<T> Matrix<T>::col(int i) {
    vector<T> result(size);
    for (int k = 0; k < size; ++k) {
        result[k] = data[k][i];
//        result.push_back(data[k][i]);  //some shit with this
    }
    return result;
}

template<class T>
vector<T>& Matrix<T>::operator[](int i) {
    return data[i];
}

template<class T>
T operator*(vector<T> vec1, vector<T> vec2)
{
    T result = T();
    for (int i = 0; i < vec1.size(); ++i) {
        result+= vec1[i]*vec2[i];
    }

    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*(Matrix& matr) {
    Matrix<T> result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = this->row(i) * matr.col(j);
        }
    }
    return result;
}

template<class T>
Matrix<T> Matrix<T>::operator*=(Matrix& matr) {
    Matrix<T> result(size);
    for (int i = 0; i < size; ++i) {
        for (int j = 0; j < size; ++j) {
            result[i][j] = this->row(i) * matr.col(j);
        }
    }
    *this = result;
    return *this;
}

template<class T>
Matrix<T> pow(Matrix<T> &matr, int i)
{
    if (i<=0) throw 'wrong exponent value';
    Matrix<T> result = matr;
    for (int j = 1; j < i; ++j) {
        result*=matr;
    }
    return result;
}

#endif //LAB7_MATRIX_H
