
#include <bits/stdc++.h>
using namespace std;
 
int n, s, t, res = -1;
vector<int> f(2000000, 0), g(2000000, 0); //init vector
 
int main()
{
    cin >> n;
    while (n--)
    {
        cin >> s >> t;
        f[t] = t - s;
        g[s] = t - s;
    }
 
    for (int i = 1; i < 2000000; i++)
    {
        f[i] = max(f[i - 1], f[i]);
    }
    for (int i = 2000000 - 2; i >= 0; i--)
    {
        g[i] = max(g[i + 1], g[i]);
    }
 
    for (int i = 0; i < 2000000; i++)
    {
        res = max(res, f[i] + g[i + 1]);
    }
    cout << res;
 
    return 0;
}