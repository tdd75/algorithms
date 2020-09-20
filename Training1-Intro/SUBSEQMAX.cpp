#include <iostream>
#include <vector>
using namespace std;

vector<int> a;

int main()
{
    long n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        a.push_back(x);
    }
    long cur = a[0];
    long max = cur;
    for (int i = 1; i < a.size(); i++)
    {
        if (cur > 0)
            cur += a[i];
        else
            cur = a[i];
        max = max > cur ? max : cur;
    }
    cout << max;
    return 0;
}