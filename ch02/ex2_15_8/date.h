#ifndef DATE_H
#define DATE_H

// This is the interface for the class Date, which stores a
//  date as a single integer representing the number of days
//  since the static variable s_BaseDate.

#include <string>

using namespace std;

class Date {
public:
    Date();
        // Default constructor.
        // Postcondition: Date object initialized with current date.

    Date(int y, int m, int d);
        // Constructor with arguments.
        // Precondition: y, m, and d refer to a valid date.
        // Postcondition: m_DaysSinceBaseDate assigned value.

    void set(int y, int m, int d);
        // Function to set the date.
        // Precondition: y, m, and d refer to a valid date.
        // Postcondition: m_DaysSinceBaseDate assigned value.

    string toString(bool brief);
        // Function to return a string representing the date.
        // Postcondition: If brief == true; date in format yyyy/mm/dd
        //  returned; else Month Day, Year (e.g. Jan 1, 1900) returned.

    void setToToday();
        // Function to set the date to today's date.
        // Postcondition: m_DaysSinceBaseDate assigned value.

    string getWeekDay() const;
        // Function to return the name of the day of the week.
        // Postcondition: Returned string representing the day's name.

    bool lessThan(const Date& d) const;
        // Function to check whether d is an earlier date than the
        //  calling object's date.
        // Postcondition: Returned true if d < calling object;
        //  else false.

    bool equals(const Date& d) const;
        // Function to check whether d and the calling object
        //  represent the same date.
        // Postcondition: Returned true if d == calling object.

    int daysBetween(const Date& d) const;
        // Function to return the number of days between d and
        //  the date of the calling object.
        // Postcondition: returned abs(d - calling object).

    Date addDays(int days);
        // Function to add days to the date of the calling object.
        // Postcondition: m_DaysSinceBaseDate += d.

    static bool leapYear(int year);
        // Function to check whether year is a leap year.
        // Postcondition: Returned true if year represents
        //  a leap year; else false.

    static string monthName(int month);
        // Function to return a 3-character string representing the 
        //  name of the month.
        // Postcondition: Returned string representing month.

    static int yearDays(int year);
        // Function to return the number of days in the given year.
        // Postcondition: Returned number of days in year.

    static int monthDays(int month, int year);
        // Function to return the number of days in the given month.
        // Postcondition: Returned number of days in month in year.

private:
    int m_DaysSinceBaseDate;
    static int s_BaseYear;

    static int ymd2dsbd(int y, int m, int d);
    // Function to compute the number of days since the base date.
    // Postcondition: Returned number of days since the base date.

    void YMD(int& y, int& m, int& d);
    // Function to compute the day, month, and year of the calling object.
    // Postcondition: y = year, m = moth, d = date.
};
#endif // DATE_H
