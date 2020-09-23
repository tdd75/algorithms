#include <iostream>
using namespace std;

int main()
{
    unsigned long long int a, b, div = 1000000007, excess = 1;
    cin >> a >> b;
    a %= div;
    while (b / 2 != 0)
    {
        if (b % 2 != 0)
        {
            excess = excess * a % div;
        }
        b /= 2;
        a = a * a % div;
    }
    cout << excess * a % div;
    return 0;
}