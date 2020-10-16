#include <iostream>
#include <map>
using namespace std;

void gen(int k)
{
    for (int i = a[k - 1] + 1; i <=n - m + k; i++)
    {
        a[k] = i;
        if (k == m)
        {
            for (int j = 1; j <= m; j++)
            {
                cout << a[j] << " ";
            }
            cout << endl;
        }
        else
        {
            gen(k + 1);
        }
    }
}

int main()
{
    int Q, N, T, T2, count;
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        T = N * (N + 1) * (N + 2);
        T2 = T * T;
        count = 0;

        for (int i = 2; i < T; i++)
        {
            if (T2 % i == 0)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}