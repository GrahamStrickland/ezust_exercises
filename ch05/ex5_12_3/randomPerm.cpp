// Driver program to test the function randomPerm(n, key) which
// produces a permutation of the numbers 0...n seeded with key.

#include <cstdlib>
#include <QVector>
#include <QString>
#include <QTextStream>

int myRand(int min, int max);
// Postcondition: Returned pseudo-random int between min and max.

QVector<int> randomPerm(int n, unsigned key);
// Postcondition: Returned permutation of the numbers 0...n,
//  seeded with key.

int main()
{
    QTextStream cout(stdout);
    QTextStream cin(stdin);

    int num;
    unsigned int key;

    cout << "Please enter a positive number of integers: ";
    cout.flush();
    cin >> num;
    cout << "Please enter a positive number to seed the "
         << "random number generator: ";
    cout.flush();
    cin >> key;
    
    QVector<int> perm = randomPerm(num, key);

    cout << "Random permutation: ";
    foreach(const int &val, perm) {
        cout << val << ' ';
    }
    cout << endl;

    return 0;
}

int myRand(int min, int max)
{
    return (rand() % (max - min + 1)) + min;
}

QVector<int> randomPerm(int n, unsigned key)
{
    QVector<int> perm;
    int random;

    srand(key);

    while (perm.size() <= n) {
        random = myRand(0, n);
        if (!perm.contains(random))
            perm << random;
    }

    return perm;
}
