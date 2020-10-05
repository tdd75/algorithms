#include <iostream>
using namespace std;
#define N 1000000

int n, a[N];

long long hist(int l, int r)
{
    if (l == r)
        return a[l];

    int m = (l + r) / 2;
    int h = a[m];
    int index_left = m, index_right = m;
    long long mid = a[m];

    while (index_left > l || index_right < r)
    {
        while (index_left > l && a[index_left - 1] >= h)
            index_left--;
        while (index_right < r && a[index_right + 1] >= h)
            index_right++;
        mid = max(mid, (long long)(index_right - index_left + 1) * h);

        if (index_left > l)
        {
            if (index_right < r)
                h = max(a[index_left - 1], a[index_right + 1]);
            else
                h = a[index_left - 1];
        }
        else
        {
            if (index_right < r)
                h = a[index_right + 1];
            else
                h = 0;
        }
    }
    long long left = hist(l, m);
    long long right = hist(m + 1, r);

    return max(mid, max(left, right));
}

int main()
{
    cin >> n;
    while (n != 0)
    {
        for (int i = 0; i < n; i++)
            cin >> a[i];
        cout << hist(0, n - 1) << endl;
        cin >> n;
    }
}