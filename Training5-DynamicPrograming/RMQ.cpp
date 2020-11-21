#include <iostream>
#include <cmath>
using namespace std;

int a[1000010];
int M[1000010][23];
int n, m, u, v, i, k;
long long result;

int main()
{
    cin >> n;
    for (i = 0; i < n; i++)
    {
        cin >> a[i];
        M[i][0] = a[i];
    }

    for (k = 1; (1 << k) <= n; k++)
        for (i = 0; i + (1 << k) - 1 < n; i++)
            M[i][k] = min(M[i][k - 1], M[i + (1 << (k - 1))][k - 1]);

    cin >> m;
    while (m--)
    {
        cin >> u >> v;
        int k = log2(v - u + 1);
        result += min(M[u][k], M[v - (1 << k) + 1][k]);
    }
    cout << result;
    return 0;
}
