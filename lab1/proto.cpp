//
// Created by levermory on 9/1/20.
//

#include "proto.h"
#include <iostream>

Student::Student() {
    cout<<"enter student's name: ";
    getline(cin, name);
    cout<<"enter student's birthday: ";
    string input;
    getline(cin, input);
    date = new Date(input);
//    cout<<"enter student's adress: ";
//    getline(cin, adress);
//    cout<<"enter student's phone number: ";
//    getline(cin, phone_number);
    cout<<"enter student's faculty: ";
    getline(cin, faculty);
    cout<<"enter student's course: ";
    cin>>course;
    cin.ignore(32767, '\n');
}


//Фамилия, Имя, Отчество, Дата рождения, Адрес, Телефон, Факультет, Курс.
void Student::set() {
    cout<<"enter student's name: ";
    getline(cin, name);
    cout<<"enter student's birthday: ";
    string input;
    getline(cin, input);
    date = new Date(input);
    cout<<"enter student's adress: ";
    getline(cin, adress);
    cout<<"enter student's phone number: ";
    getline(cin, phone_number);
    cout<<"enter student's faculty: ";
    getline(cin, faculty);
    cout<<"enter student's course: ";
    cin>>course;

}

string Student::get_fac() {
    return faculty;
}

int Student::get_course() {
    return course;
}

void Student::show() {
    cout<<"name: "<<name<<endl;
    cout<<"faculty: "<<faculty<<endl;
    cout<<"course: "<<course<<endl;
}

Date Student::get_date() {
    return *date;
}

bool Student::cmp(Student st1, Student st2) {
    if (st1.faculty != st2.faculty)
        return st1.faculty < st2.faculty;
    else
        return st1.course<st2.course;
//    return (st1.faculty<=st2.faculty)
}

Student::~Student() = default;

