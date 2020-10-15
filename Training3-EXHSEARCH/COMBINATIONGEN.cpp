#include <iostream>

using namespace std;

int n, m;

int x[10000] = {0};

void gen()
{
    int i = m;
    while (i > 0 && (x[i] == n - m + i))
        i--;
    if (i > 0)
    {
        x[i]++;
        for (int k = i + 1; k <= m; k++)
        {
            x[k] = x[k - 1] + 1;
        }
        for (int k = 1; k <= m; k++)
        {
            cout << x[k] << " ";
        }
    }
    else
    {
        cout << -1;
    }
}

int main()
{
    cin >> n >> m;
    for (int p = 1; p <= m; p++)
    {
        cin >> x[p];
    }
    gen();

    return 0;
}