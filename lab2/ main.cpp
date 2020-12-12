// Определить класс «Дробь» – Fraction в виде пары (m,n).
// Класс должен содержать несколько конструкторов.
// Реализовать методы для сложения, вычитания, умножения
// и деления дробей. Перегрузить операции сложения, вычитания,
// умножения, деления, присваивания и операции сравнения.
// Создать массив объектов и передать его в функцию, которая
// изменяет каждый элемент массива с четным индексом путем
// добавления следующего за ним элемента массива.

// протестировать все операции
// добавить операторы сравнени и протестировать                   есть
// добавить функции-методы-операторы, sum, divide…                есть
// переписать оператор в виде operator+(Fraction, Fraction)       есть
//

#include "fraction.h"

using namespace std;

int main() {
    cout<<"enter size of array: "<<endl;
    int n = 10;
//    cin>>n;
    auto *array = new Fraction[n];
//    for(int i=0; i<n; i++) cin>>array[i];
    for(int i=0; i<n; i++) array[i] = Fraction(rand()%10, rand()%10);
    cout<<"array:"<<endl;
    for(int i=0; i<n; i++) cout<<array[i]<<'\t';
    cout<<endl;
    change(array, n);
    cout<<"changed array:"<<endl;
    for(int i=0; i<n; i++) cout<<array[i]<<'\t';
    cout<<endl;
    cout<<array[1]<<" > "<<array[0]<<" = ";
    cout<<(array[1]>array[0])<<endl;
    cout<<array[1]<<" < "<<array[0]<<" = ";
    cout<<(array[1]<array[0])<<endl;
    cout<<array[1]<<" + "<<array[0]<<" = ";
    cout<<(array[1]+array[0])<<endl;
    cout<<array[1]<<" - "<<array[0]<<" = ";
    cout<<(array[1]-array[0])<<endl;
    cout<<array[1]<<" * "<<array[0]<<" = ";
    cout<<(array[1]*array[0])<<endl;
    cout<<array[1]<<" / "<<array[0]<<" = ";
    cout<<(array[1]/array[0])<<endl;
    cout<<endl;
//    cout<<array[1]+array[0]<<endl;
    return 0;
}
