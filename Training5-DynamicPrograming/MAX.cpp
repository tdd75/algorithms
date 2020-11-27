#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n, m, a[10010], f[10010];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = i; j < n; j++)
        {
            if(a[j] >= a[i])
                f[i] = max(f[i], f[j] + 1);
        }
    }
    int result = f[0];
    for(int i = 0; i < n; i++)
    {
        result = max(result, f[i]);
    }
    cout << result;
    return 0;
}
