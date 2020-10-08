#include <iostream>
using namespace std;
#define N 1000000

int n, a[N];

long long hist(int begin, int end)
{
    if (begin == end)
        return a[begin];    // exit recursive

    int mid = (begin + end) / 2;
    int h = a[mid];
    int left = mid, right = mid;
    long long S_mid = a[mid];

    while (left > begin || right < end)
    {
        while (left > begin && a[left - 1] >= h)
            left--;
        while (right < end && a[right + 1] >= h)
            right++;
        S_mid = max(S_mid, (long long)(right - left + 1) * h);

        if (left > begin)
        {
            if (right < end)
                h = max(a[left - 1], a[right + 1]);
            else
                h = a[left - 1];
        }
        else
        {
            if (right < end)
                h = a[right + 1];
            else
                h = 0;
        }
    }
    long long S_left = hist(begin, mid);
    long long S_right = hist(mid + 1, end);
                                                                                                                                                                                                             
    return max(S_mid, max(S_left, S_right));
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