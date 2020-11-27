#include <bits/stdc++.h>
using namespace std;

int N, T, D;
int a[1010], t[1010], mem[1010][1010];
int best;

void GM(int i)
{
    for (int k = t[i]; k <= T; k++)
    {
        for (int j = max(0, i - D); j < i; j++)
            mem[i][k] = max(mem[i][k], mem[j][k - t[i]] + a[i]);
        best = max(best, mem[i][k]);
    }
}
int main()
{
    cin >> N >> T >> D;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < N; i++)
    {
        cin >> t[i];
    }
    for (int j = 0; j <= T; j++)
    {
        if (j >= t[0])
            mem[0][j] = a[0];
    }
    for (int i = 0; i < N; i++)
    {
        GM(i);
    }
    cout << best;
    return 0;
}
