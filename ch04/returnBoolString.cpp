#include <iostream>
#include <string>
    
using namespace std;

string boolToString(bool var);

int main()
{

    bool value = true;

    cout << boolToString(value);

    return 0;
}

string boolToString(bool var)
{
    return var ? "true" : "false";
}
