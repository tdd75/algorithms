#include <bits/stdc++.h>
using namespace std;

int n, L1, L2;
int a[100010], mem[100010];
int best;

void GM(int i)
{
    mem[i] = a[i];
    if (i >= L1)
    {
        for (int j = (i - L2 > 0) ? (i - L2) : 0; j <= i - L1; j++)
            mem[i] = max(mem[i], mem[j] + a[i]);
        best = max(best, mem[i]);
    }
}

int main()
{
    cin >> n >> L1 >> L2;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++)
        GM(i);
    cout << best;
    return 0;
}
