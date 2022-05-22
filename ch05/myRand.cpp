// Driver program to test the function myRand() which returns
// a pseudo-random int in the range given.

#include <cstdlib>
#include <ctime>
#include <iostream>

int myRand(int min, int max);
// Postcondition: Returned pseudo-random int between min and max.

int main()
{
    srand(time(0));

    char ans;
    int min, max;

    std::cout << "Please enter a minimum integer for random number: ";
    std::cin >> min;
    std::cout << "Please enter a maximum integer for random number: ";
    std::cin >> max;
    do {
        std::cout << myRand(min, max) << std::endl << "Another (y/n)? ";
        std::cin >> ans;
    } while (ans != 'n' && ans != 'N');

    return 0;
}

int myRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}
