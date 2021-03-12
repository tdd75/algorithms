#include <iostream>
#include <vector>
using namespace std;

vector<int> a(1000005, 0);

int main()
{
    int n, x;
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    long cur = a[1];
    long best = cur;
    for (int i = 2; i <= n; i++)
    {
        if (cur > 0)    
            cur += a[i];
        else
            cur = a[i];
        best = max(best, cur);
    }
    cout << best;
    return 0;
}