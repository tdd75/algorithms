#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, K, a[200000], res = 0;
    cin >> N >> K;
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
    sort(a, a + N);
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            // if (K - a[i] - a[j] <= 0)   continue;
            // if(binary_search(a + j + 1, a + N, K - a[i] - a[j])) {
            //     res ++;
            // }
            int x = K - a[i] - a[j];
            res += upper_bound(a, a + i, x) - lower_bound(a, a + i, x);
        }
    }
    cout << res;
    return 0;
}