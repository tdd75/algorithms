#include <iostream>
using namespace std;
 
int main()
{
    unsigned long int n, x, div = 1000000007, res = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        res = (res + x % div) % div;
    }
    cout << res;
    return 0;
}