#include <iostream>
using namespace std;
int n, k, mark[35], c[35][35], best = 2e9, x[35], cmin = 2e9;

void backtrack(int i, int h, int sum)
{
    if (i > 2 * n)
    {
        best = min(best, sum + c[x[2 * n]][0]);
        return;
    }
    for (int j = 1; j <= 2 * n; j++)
    {
        // nhanh can
        if (mark[j] || h + (j > n ? -1 : 1) > k || j > n && !mark[j - n])
        {
            continue;
        }
        x[i] = j;
        mark[j] = 1;
        if (sum + c[x[i - 1]][x[i]] + cmin * (2 * n - 1) < best)
        {
            backtrack(i + 1, h + (j > n ? -1 : 1), sum + c[x[i - 1]][x[i]]);
        }
        mark[j] = 0;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i <= 2 * n; i++)
    {
        for (int j = 0; j <= 2 * n; j++)
        {
            cin >> c[i][j];
            cmin = min(cmin, c[i][j]);
        }
    }
    backtrack(1, 0, 0);
    cout << best;
    return 0;
}
