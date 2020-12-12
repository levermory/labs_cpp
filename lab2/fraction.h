//Определить класс «Дробь» – Fraction в виде пары (m,n).
// Класс должен содержать несколько конструкторов.
// Реализовать методы для сложения, вычитания, умноженияи деления дробей.
// Перегрузить операции сложения, вычитания,
// умножения, деления, присваивания и операции отношения.
//
// Создать массив объектов и передать его в функцию, которая
// изменяет каждый элемент массива с четным индексом путем
// добавления следующего за ним элемента массива.
//
// Created by levermory on 9/15/20.
//

#ifndef LAB2_FRACTION_H
#define LAB2_FRACTION_H

#include <string>
#include <iostream>

using namespace std;

class Fraction
{
    int n, m; // numerator, denumerator

public:
    Fraction()= default; //Fraction(){}
    Fraction(int, int);
    Fraction(string);

    friend ostream& operator <<(ostream&, Fraction);
    friend istream& operator >>(istream&, Fraction);
//    Fraction operator+(Fraction);
//    Fraction operator-(Fraction);
//    Fraction operator*(Fraction);
//    Fraction operator/(Fraction);

    bool operator>(Fraction);
    bool operator<(Fraction);

    Fraction sum(Fraction);
    Fraction difference(Fraction);
    Fraction product(Fraction);
    Fraction quotient(Fraction);

    friend Fraction operator+(Fraction, Fraction);
    friend Fraction operator-(Fraction, Fraction);
    friend Fraction operator*(Fraction, Fraction);
    friend Fraction operator/(Fraction, Fraction);
};

void change(Fraction*, int);

#endif //LAB2_FRACTION_H
