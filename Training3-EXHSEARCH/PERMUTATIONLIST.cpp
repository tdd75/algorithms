#include <iostream>
using namespace std;
int n, a[100], b[100];
bool d[100], check;

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
                    if (!check)
                    {
                        if (a[j] != b[j])
                        {
                            break;
                        }
                        if (j == n)
                            check = true;
                    }
                    else
                    {
                        cout << a[j] << " ";
                        if (j == n)
                            return;
                    }
                }
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
    for (int i = 1; i <= n; i++)
    {
        cin >> b[i];
    }
    gen(1);
    return 0;
}