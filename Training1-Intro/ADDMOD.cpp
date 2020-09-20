#include <iostream>
using namespace std;

int main()
{    
    unsigned long long int a, b, div = 1000000007;
    cin >> a >> b;
    cout << (a % div + b % div) % div;
    return 0;
}