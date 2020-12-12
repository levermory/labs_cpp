//
// Created by levermory on 9/15/20.
//

#include "fraction.h"
#include <numeric>


// constructors
Fraction::Fraction(int N, int M) : n(N), m(M){}
Fraction::Fraction(string input) {
    int pos;
    string delimeter = "/";

    pos=input.find(delimeter);
    n=stoi(input.substr(0, pos));
    input.erase(0, pos+1);
    m=stoi(input);
}

// overloading input/output operators
ostream& operator<<(ostream& out, Fraction frac) {
    out<<frac.n<<'/'<<frac.m;
    return out;
}
istream& operator>>(istream& in, Fraction frac) {
    cout<<"n: ";
    in>>frac.n;
    cout<<"m: ";
    in>>frac.m;
    return in;
}

// overloading basic arithmetic operators
bool Fraction::operator>(Fraction frac) {
    return n*frac.m>frac.n*m;
}
bool Fraction::operator<(Fraction frac) {
    return n*frac.m<frac.n*m;
}

Fraction operator+(Fraction add1, Fraction add2){
    auto d = gcd(add1.n*add2.m+add2.n*add1.m, add1.m*add2.m);
    return Fraction((add1.n*add2.m+add2.n*add1.m)/d, (add1.m*add2.m)/d);
}
Fraction operator-(Fraction add1, Fraction add2){
    auto d = gcd(add1.n*add2.m-add2.n*add1.m, add1.m*add2.m);
    return Fraction((add1.n*add2.m-add2.n*add1.m)/d, (add1.m*add2.m)/d);
}
Fraction operator*(Fraction add1, Fraction add2){
    auto d = gcd(add1.n*add2.n, add1.m*add2.m);
    return Fraction((add1.n*add2.n)/d, (add1.m*add2.m)/d);
}
Fraction operator/(Fraction add1, Fraction add2){
    auto d = gcd(add1.n*add2.m, add1.m*add2.n);
    return Fraction((add1.n*add2.m)/d, (add1.m*add2.n)/d);
}
void Fraction::reduce() {
    auto d = gcd(n, m);
    n = n/d;
    m = m/d;
}

void change(Fraction* array, int size)
{
    for(int i=0; i+1<size; i++){
        if((i+1)%2==0) array[i] = array[i]+array[i+1];
    }
}
