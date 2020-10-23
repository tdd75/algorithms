#include <iostream>
using namespace std;
int a[33], c[33], n, b;
int best = 0;

void backtrack(int i, int M, int V)
{
    if (i > n)
    {
        if (M <= b)
            best = max(best, V);
        return;
    }
    backtrack(i + 1, M, V);
    if (M + a[i] <= b)
        backtrack(i + 1, M + a[i], V + c[i]);
}

int main()
{
    cin >> n >> b;
    for (int i = 1; i <= n; i++)
        cin >> a[i] >> c[i];
    backtrack(1, 0, 0);
    cout << best;
}
