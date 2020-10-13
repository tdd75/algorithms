#include <iostream>
using namespace std;
#define MAX 10000

int n, int m;
int a[MAX], count = 0;

void combinationList(int k)
{
    int i;
    for (i = a[k - 1] + 1; i <= n - m + k; i++)
    {
        a[k] = i;
        if (k == m)
            <ghi nhan mot cau hinh> else Try(k + 1);
    }

    int main()
    {
        int n, m, k;
        cin >> n >> m >> k;
        combinationList(n, m, k);
        return 0;
    }