#include <iostream>
using namespace std;

int main()
{
    unsigned long long int a, b, div = 1000000007;
    cin >> a >> b;
    long res = 1;
    a %= div, b %= div - 1;
    while (b > 0)
    {
        if (b % 2 > 0)
            res = res * a % div;
        a = a * a % div;
        b /= 2;
    }
    cout << res;
    return 0;
}