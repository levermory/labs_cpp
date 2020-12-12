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

#ifndef FRACTION_H
#define FRACTION_H

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

    bool operator>(Fraction);
    bool operator<(Fraction);

    friend Fraction operator+(Fraction, Fraction);
    friend Fraction operator-(Fraction, Fraction);
    friend Fraction operator*(Fraction, Fraction);
    friend Fraction operator/(Fraction, Fraction);

    void reduce();
};

void change(Fraction*, int);

#endif //FRACTION_H
