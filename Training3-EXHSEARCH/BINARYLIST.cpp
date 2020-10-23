#include <iostream>
using namespace std;
int n, k_, i_, a[10000], pos;
bool check;

void gen(int k)
{
    for (int i = 0; i < 2; i++)
    {
        a[k] = i;
        if (k == n)
        {
            // 000xxxx
            for (int j = 1; j <= n; j++)
            {
                pos = 1;
                check = true;
                for (int l = 1; l <= k_; l++)
                {
                    if(a[pos] != 0) {
                        check = false;
                        break;
                    }
                }
                if (!=check) {
                    break;
                }
            }
            cout << endl;
        }
        else
            gen(k + 1);
    }
}
int main()
{
    cin >> n, k_, i_;
    gen(0);
    return 0;
}