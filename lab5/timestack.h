//
// Created by levermory on 11/7/20.
//

#ifndef LAB5_TIMESTACK_H
#define LAB5_TIMESTACK_H

#include "stack.h"
#include <ctime>

template<class T>
class TimeStack: Stack<T>
{
    time_t log;
public:
    TimeStack(): log(time(nullptr)){};
    TimeStack(T data): Stack<T>(data), log(time(nullptr)){};
    void push(T data)
    {
        log = time(nullptr);
        Stack<T>::push(data);
    }
    T pop()
    {
        log = time(nullptr);
        Stack<T>::pop();
    }
    void print()
    {
        log = time(nullptr);
        Stack<T>::print();
    }
    T gettop()
    {
        log = time(nullptr);
        return Stack<T>::gettop();
    }
    short getsize()
    {
        log = time(nullptr);
        return Stack<T>::getsize();
    }
    void getlog()
    {
        auto logdata = localtime(&log);
        cout<<logdata->tm_mday
            <<"/"<<logdata->tm_mon+1
            <<"/"<<logdata->tm_year+1900
            <<" "<<logdata->tm_hour
            <<":"<<logdata->tm_min
            <<":"<<logdata->tm_sec;
    }
};

#endif //LAB5_TIMESTACK_H
