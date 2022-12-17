#ifndef DATE_H
#define DATE_H

#include <iostream>
#include <cmath>
#include <ctime>


class Date
{
    public:

        Date();
        int set_day();
        int set_month();
        int set_year();
        float year_diff(int year1, int month1, int day1, int year2, int month2, int day2);

        int year, month, day;
};

#endif