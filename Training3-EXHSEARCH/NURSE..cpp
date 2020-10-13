#include <iostream>

using namespace std;

int n, k1, k2;
int ans = 0;
int x[100];

void Try(int i, int l)
{
    if (i > n)
    {
        ans += (l >= k1 || l == 0);
        return;
    }
    if (i == 1 || l >= k1)
        Try(i + 1, 0);
    if (l < k2)
        Try(i + 1, l + 1);
}

int main()
{
    cin >> n >> k1 >> k2;
    Try(1, 0);
    cout << ans;

    return 0;
}