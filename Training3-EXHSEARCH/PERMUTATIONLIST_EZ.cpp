
#include <iostream>
using namespace std;
int n, a[100], d[100];

void gen(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            a[k] = i;
            d[i] = 1;
            if (k == n)
            {
                for (int j = 1; j <= n; j++)
                {
                    cout << a[j] << " ";
                }
                cout << endl;
            }
            else
            {
                gen(k + 1);
            }
            d[i] = 0;
        }
    }
}
int main()
{
    cin >> n;
    gen(1);
    return 0;
}