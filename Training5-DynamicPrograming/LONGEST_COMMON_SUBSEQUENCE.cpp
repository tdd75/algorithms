#include <bits/stdc++.h>
using namespace std;
 
int a[10010], b[10010];
int mem[10010][10010];
int best;
// memset(mem, -1, sizeof(mem));
int lcs(int i, int j)
{
    if (i == -1 || j == -1)
    {
        return 0;
    }
    if (mem[i][j] != -1)
    {
        return mem[i][j];
    }
    int res = 0;
    res = max(res, lcs(i, j - 1));
    res = max(res, lcs(i - 1, j));
    if (a[i] == b[j])
    {
        res = max(res, 1 + lcs(i - 1, j - 1));
    }
    mem[i][j] = res;
    return res;
}
 
int main()
{
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            mem[i][j] = -1;
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            best = max(best, lcs(i, j));
        }
    }
    cout << best;
    return 0;
}