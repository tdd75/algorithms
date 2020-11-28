#include <iostream>
using namespace std;
int n, a[1010];

void out()
{
    for (int j = 1; j <= n; j++)
    {
        cout << a[j] << " ";
    }
    cout << endl;
}

void gen(int k)
{
    if (k > n)
    {
        out();
        return;
    }
    for (int i = 0; i <= 1; i++)
    {
        a[k] = i;
        gen(k + 1);
    }
}
int main()
{
    cin >> n;
    gen(1);
    return 0;
}
