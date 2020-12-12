//
// Created by levermory on 9/6/20.
//

#include "date_class.h"
#include <iostream>

using namespace std;


Date::Date(std::string date) {
    int pos;
    string delimeter = "./_";

    pos=date.find_first_of(delimeter);
    day=stoi(date.substr(0, pos));
    date.erase(0, pos+1);

    pos=date.find_first_of(delimeter);
    month=stoi(date.substr(0, pos));
    date.erase(0, pos+1);

    year=stoi(date);
}

void Date::show_date() {
    cout<<day<<"."<<month<<"."<<year;
}


