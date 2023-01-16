#include <iostream>
#include <cmath>
#include <ctime>

#include "Date.h"

Date::Date(){}

int Date::set_day()
{
  std::cout << "\nEnter the day in the format \"dd\":\n";
  std::cin >> day;
  return day;
}

int Date::set_month()
{
  std::cout << "\nEnter the month in the format \"mm\":\n";
  std::cin >> month;
  return month;
}

int Date::set_year()
{
  std::cout << "\nEnter the year in the format \"yyyy\":\n";
  std::cin >> year;
  return month;
}

// This function calculate the difference of years between two dates.
float Date::year_diff(int year1, int month1, int day1, int year2, int month2, int day2)
{
    std::tm make_tm(int year1, int month1, int day1);
    std::tm tm1 = {0};
    tm1.tm_year = year1;
    tm1.tm_mon = month1;
    tm1.tm_mday = day1;

    std::tm make_tm(int year2, int month2, int day2);
    std::tm tm2 = {0};
    tm2.tm_year = year2;
    tm2.tm_mon = month2;
    tm2.tm_mday = day2;

    std::time_t time1 = std::mktime(&tm1); // These are time objects.
    std::time_t time2 = std::mktime(&tm2);

    float difference = std::difftime(time1, time2) / 60*60*24; // We divide by the number of seconds in the year because we take the difference in seconds.
    return difference;
}