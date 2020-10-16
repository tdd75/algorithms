#include <iostream>
using namespace std;
#define MAX 10000

int n, m;
int a[MAX];

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
    cin >> n >> m;
    gen(1);
    return 0;
}