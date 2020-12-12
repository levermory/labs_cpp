//
// Created by levermory on 9/1/20.
//

#ifndef INC_2020_09_01_PROTO_H
#define INC_2020_09_01_PROTO_H

#include <string>
#include "date_class.h"

using namespace std;



class Student
//Фамилия, Имя, Отчество,
//Дата рождения, Адрес, Телефон, Факультет, Курс
{
    string name;
    Date* date;
    string adress;
    string phone_number;
    string faculty;
    int course;
public:
    Student();
    ~Student();
    void set();
    string get_fac();
    int get_course();
    Date get_date();
    void show();
    static bool cmp(Student, Student);
};

#endif //INC_2020_09_01_PROTO_H
