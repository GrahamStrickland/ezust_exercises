// This is the implementation of the class Date.
// The interface is in the file date.h

#include "date.h"

#include <time.h>
#include <cassert>
#include <iostream>

using namespace std;

int Date::s_BaseYear = 1900;

Date::Date()
{
   setToToday(); 
}

Date::Date(int y, int m, int d) 
{
    set(y, m, d);
}

void Date::set(int y, int m, int d)
{   // Check for valid date.
    assert(y >= s_BaseYear);  // Valid year
    assert(m > 0 && m <= 12);   // Valid month
    assert(d > 0 && d < monthDays(m, y));  // Valid day

    // Set date member function.
    m_DaysSinceBaseDate = ymd2dsbd(y, m, d);
}

string Date::toString(bool brief)
{
    int y, m, d;
    string yearString = "", monthString = "", dayString = "", 
           dateString = "";

    // Get year, month, and day as integers.
    YMD(y, m, d);

    for (int i = 0, exp = 1000; i < 4; i++) {  // Convert year to string.
        yearString += to_string(y/exp);
        y %= exp;
        exp /= 10;
    }

    for (int i = 0, exp = 10; i < 2; i++) {    // Convert day to string.
        dayString += to_string(d/exp);
        d %= exp;
        exp /= 10;
    }

    if (brief) {    // Brief output format: "yyyy/mm/dd"
        for (int i = 0, exp = 10; i < 2; i++) {  // Convert month to string.
            monthString += to_string(m/exp);
            m %= exp;
            exp /= 10;
        }
        dateString = yearString + '/' + monthString + '/' + dayString;
    }
    else {  // Extended format: "Jan 1, 1990"
        monthString = monthName(m);
        if (dayString.at(0) == '0') dayString.erase(0, 1);
        dateString = monthString + " " + dayString + ", " + yearString;
    }

    return dateString;
}

void Date::setToToday()
{
    struct tm *tp = 0;
    time_t now;
    now = time(0);
    tp = localtime(&now);
    set(1900 + tp->tm_year, 1 + tp->tm_mon, tp->tm_mday);
}

string Date::getWeekDay() const
{
    int dayInt;
    string dayString;

    // Get int value of day of week.
    dayInt = m_DaysSinceBaseDate % 7;

    // Get string corresponding to day.
    switch(dayInt) {
        case 0:
            dayString = "Mon";
            break;
        case 1:
            dayString = "Tues";
            break;
        case 2:
            dayString = "Wed";
            break;
        case 3:
            dayString = "Thurs";
            break;
        case 4:
            dayString = "Fri";
            break;
        case 5:
            dayString = "Sat";
            break;
        case 6:
            dayString = "Sun";
            break;
    }

    return dayString;
}

bool Date::lessThan(const Date& d) const
{
    return m_DaysSinceBaseDate < d.m_DaysSinceBaseDate;
}

bool Date::equals(const Date& d) const
{
    return m_DaysSinceBaseDate == d.m_DaysSinceBaseDate;
}

int Date::daysBetween(const Date& d) const
{
    if (lessThan(d)) return d.m_DaysSinceBaseDate - m_DaysSinceBaseDate;
    else return m_DaysSinceBaseDate - d.m_DaysSinceBaseDate;
}

Date Date::addDays(int days)
{   // Check that days is non-negative.
    assert(days >= 0);

    // Create temporary Date object to store new days amount.
    Date temp;

    // Find values for year, month and date of calling object.
    int y, m, d;
    YMD(y, m, d);
    
    // Add days and convert to new date.
    d = ymd2dsbd(y, m, d) + days;

    // Set year to base year and increment years.
    y = s_BaseYear;
    while (d > yearDays(y)) {
        d -= yearDays(y);
        y++;
    }

    // Set month to Jan and increment months.
    m = 1;
    while (d > monthDays(m,y)) {
        d -= monthDays(m,y);
        m++;
    }

    // Set new date and return.
    temp.set(y, m, d);

    return temp;
}

bool Date::leapYear(int year)
{   // Check whether year is divisible by 4, or by400.
    if (year % 4 == 0) {
        if (year % 100 == 0) {
           if (year % 400 == 0) return true;
           else return false;
        }
        else return true;
    }
    else return false;
}

string Date::monthName(int month)
{
    string monthString;

    // Check for valid entry.
    assert(month > 0 && month <= 12);

    // Assign 3-character string representation.
    switch(month) {
    case 1:
        monthString = "Jan";
        break;
    case 2:
        monthString = "Feb";
        break;
    case 3:
        monthString = "Mar";
        break;
    case 4:
        monthString = "Apr";
        break;
    case 5:
        monthString = "May";
        break;
    case 6:
        monthString = "Jun";
        break;
    case 7:
        monthString = "Jul";
        break;
    case 8:
        monthString = "Aug";
        break;
    case 9:
        monthString = "Sep";
        break;
    case 10:
        monthString = "Oct";
        break;
    case 11:
        monthString = "Nov";
        break;
    case 12:
        monthString = "Dec";
        break;
    }

    return monthString;
}

int Date::yearDays(int year)
{
    if (leapYear(year)) return 366;
    else return 365;
}

int Date::monthDays(int month, int year)
{
    int days = 0;

    // Check for valid month.
    assert(month > 0 && month <= 12);

    // Return corresponding number of days.
    switch(month)
    {
        case 1:
        case 3:
        case 5:
        case 7:
        case 8:
        case 10:
        case 12:
            days = 31;
            break;
        case 4:
        case 6:
        case 9:
        case 11:
            days = 30;
            break;
        case 2:
            if (leapYear(year))
                days = 29;
            else days = 28;
    }

    return days;
}

int Date::ymd2dsbd(int y, int m, int d)
{
    int days = 0;

    // Check for valid date.
    assert(m > 0 && m < 12);
    assert(d > 0 && d <= monthDays(m, y));

    // Add days for each year.
    for (int i = s_BaseYear; i < y; i++)
        days += yearDays(i);

    // Add days for each month in current year.
    for (int i = 1; i < m; i++)
        days += monthDays(m, y);
    
    // Add days in current month.
    days += d;

    return days;
}

void Date::YMD(int& y, int& m, int& d)
{   // Set year to base, month to Jan, days to total.
    y = s_BaseYear;
    m = 1;
    d = m_DaysSinceBaseDate;

    while (d >= yearDays(y)) {
        d -= yearDays(y);
        y++;
    }

    while (d >= monthDays(m,y)) {
        d -= monthDays(m,y);
        m++;
    }
}
