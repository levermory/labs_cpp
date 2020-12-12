//Лабораторная 1 вариант 1
//Таборов Лев

//Создать массив объектов. Вывести:
//а) список студентов заданного факультета;
//б) списки студентов для каждого факультета и курса;
//в) список студентов, родившихся после заданного года.

#include "proto.h"
#include <iostream>

using namespace std;

//int const n = 3;

int main()
{
    cout<<"enter number of students: ";
    int n;
    cin>>n;
    cin.ignore(32767, '\n');
    auto* students = new Student[n];

//    a
//а) список студентов заданного факультета;
    cout<<"----------------------------"<<endl;
    cout<<"task a"<<endl;
    cout<<"enter faculty's name: ";
    string faculty;
    getline(cin, faculty);
    int flag;
    flag = 0;
    for(int i=0; i<n; i++ ){
        if(students[i].get_fac()==faculty){
            students[i].show();
            flag=1;
        }
    }
    if (!flag)
        cout<<"no students from this faculty"<<endl;

//    б
//б) списки студентов для каждого факультета и курса;
    cout<<"----------------------------"<<endl;
    cout<<"task b"<<endl;
    cout<<"all students: \n";
    sort(students, students+n, Student::cmp);

    for (int i =0; i<n; i++){
        students[i].show();
    }
//    в
//в) список студентов, родившихся после заданного года.
    cout<<"----------------------------"<<endl;
    cout<<"task в"<<endl;
    int year;
    cout<<"enter year: ";
    cin>>year;

    flag=0;
    for(int i=0; i<n; i++ ){
        if(students[i].get_date().year >= year){
            students[i].show();
            flag=1;
        }
    }
    if (!flag)
        cout<<"no students older than "<<year;

    return 0;
}