
#include <iostream>
using namespace std;
int n, a[1000];

void gen(int k)
{
    for (int i = 0; i <= 1; i++)
    {
        a[k] = i;
        if (k == n - 1)
        {
            for (int j = 0; j < n; j++)
            {
                cout << a[j];
            }
            cout << endl;
        }
        else
            gen(k + 1);
    }
}
int main()
{
    cin >> n;
    gen(0);
    return 0;
}