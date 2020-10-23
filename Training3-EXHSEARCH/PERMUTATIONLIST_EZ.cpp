
#include <iostream>
using namespace std;
int n, a[100];
bool d[100];

void gen(int k)
{
    for (int i = 1; i <= n; i++)
    {
        if (!d[i])
        {
            a[k] = i;
            d[i] = true;
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
            d[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    gen(1);
    return 0;
}