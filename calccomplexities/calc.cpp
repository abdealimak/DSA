#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    cout << setw(5) << "n"
        << setw(10) << "log(n)"
        << setw(10) << "n"
        << setw(10) << "n^2"
        << setw(15) << "n^n"
        << setw(15) << "e^n" << endl;

    cout << "---------------------------------------------------------------" << endl;

    for (int n = 1; n <= 10; n++)
    {
        double logn = log(n);
        double square = pow(n, 2);
        double nn = pow(n, n);
        double en = exp(n);
        cout << setw(5) << n
            << setw(10) << fixed << setprecision(2) << logn
            << setw(10) << n
            << setw(10) << square
            << setw(15) << nn
            << setw(15) << en << endl;
    }
    return 0;
}