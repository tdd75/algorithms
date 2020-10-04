#include <iostream>
using namespace std;
#define N 200000

int main()
{
    int n, b, a[N], maxLeft[N], maxRight[N];
    cin >> n >> b;
    for (int i = 0; i < n; i++)
        cin >> a[i];

    int answer = -1;

    maxLeft[0] = a[0];
    for (int i = 1; i < n; i++)
        maxLeft[i] = max(a[i], maxLeft[i - 1]);
    maxRight[n - 1] = a[n - 1];
    for (int i = n - 2; i >= 0; i--)
        maxRight[i] = max(a[i], maxRight[i + 1]);

    for (int i = 1; i < n - 1; i++)
    {
        int left = maxLeft[i - 1] - a[i];
        int right = maxRight[i + 1] - a[i];
        if (left >= b && right >= b)
            answer = max(answer, left + right);
    }
    cout << answer;
    return 0;
}