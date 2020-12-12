//
// Created by levermory on 9/6/20.
//

#ifndef INC_2020_09_01_DATE_CLASS_H
#define INC_2020_09_01_DATE_CLASS_H

#include <string>

struct Date
{
    int day;
    int month;
    int year;

    Date(std::string);
    void show_date();
};

#endif //INC_2020_09_01_DATE_CLASS_H
