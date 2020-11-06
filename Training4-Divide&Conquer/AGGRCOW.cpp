#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, c;
        cin >> n >> c;
        vector<int> x(n);
        for (int &e : x)
            cin >> e;
        sort(x.begin(), x.end());
        auto f = [&](int k) {
            int i = 0;
            for (int t = 1; t <= c; t++)
            {
                if (i >= n)
                    return false;
                int post = x[i];
                while (i < n && x[i] - post < k)
                    ++i;
            }
            return true;
        };
        int L = 0, H = x.back(), ans = -1;
        while (L <= H)
        {
            int M = (L + H) / 2;
            if (f(M))
            {
                ans = M;
                L = M + 1;
            }
            else
                H = M - 1;
        }
        cout << ans << endl;
    }
    return 0;
}