// This is client code to test the ADT Date.

#include "date.h"

#include <iostream>

int main()
{
    using namespace std;

    Date date1, date2;

    // Set to today's date.
    date1.setToToday();

    // Check toString() member function.
    cout << "date1 (today) = " << date1.toString(false)
         << " or " << date1.toString(true) << endl;

    // Check set() function.
    date2.set(2022, 4, 29);
    cout << "date2 = " << date2.toString(true) << endl;

    // Check equals() and lessThan() functions
    cout << "date1.equals(date2) = " 
         << (date1.equals(date2) ? "true" : "false") << endl
         << "date1.lessThan(date2) = " 
         << (date1.lessThan(date2) ? "true" : "false") << endl;

    // Check daysBetween() and addDays() functions.
    cout << "date1.daysBetween(date2) = "
         << date1.daysBetween(date2) << endl
         << "date1.addDays(3).toString(true) = "
         << date1.addDays(3).toString(true) << endl;

    return 0;
}
