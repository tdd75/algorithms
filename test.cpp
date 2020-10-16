#include <bits/stdc++.h>
#define REP(i, n) for (int i = 0; i < (n); ++i)
#define ALL(v) v.begin(), v.end()
using namespace std;
using ll = long long;
using P = pair<int, int>;
static const double PI = acos(-1);

static int cntdiv[10000005];

void cntdivisors(int n)
{
    //int div[n];
    cntdiv[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        cntdiv[i] = 1;
    }

    for (int i = 2; i <= n; ++i)
    {
        int j = i;
        while (j <= n)
        {
            ++cntdiv[j];
            j = j + i;
        }
    }
    ll sum = 0;
    REP(i, n)
    {
        //cout << i << " " << div[i] << endl;
        sum += (ll)i * cntdiv[i];
    }
    cout << sum << endl;
}

int main()
{
    int n;
    cin >> n;
    cntdivisors(n + 1);

    return 0;
}