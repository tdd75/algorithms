#include <iostream>
#include <algorithm>
using namespace std;
int m, n, c[55][55], e[55][55], x[55], best = 2e9, cnt[55];

int f()
{
    for (int i = 1; i <= m; i++)
    {
        if (c[x[i]][i] == false)
            return false;
    }
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            if (x[i] == x[j] && e[i][j] == true)
            {
                return false;
            }
        }
    }
    return true;
}

int check()
{
    for (int i = 1; i <= m; i++)
    {
        cnt[i] = 0;
    }
    for (int i = 1; i <= m; i++)
    {
        ++cnt[x[i]];
    }
    return *max_element(cnt + 1, cnt + 1 + m);
}

void gen(int i)
{
    if (i > n)
    {
        if (check())
        {
            best = min(best, f());
        }
        return;
    }
    for (int j = 1; j <= m; i++)
    {
        x[i] = j;
        if (c[j][i])
            gen(i + 1);
    }
}

int main()
{
    cin >> m >> n;
    // input matrix c
    for (int i = 1; i <= m; i++)
    {
        cin >> quantity;
        while (quantity--)
        {
            cin >> c[i];
        }
    }
    // input matrix conflict
    cin >> k;
    for (int i = 1; i <= k; i++)
    {
        cin >> c1 >> c2;
        conflict[c1][c2] = 1;
    }
    gen(0);
    return 0;
}
