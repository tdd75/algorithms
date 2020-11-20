#include <iostream>
#include <cmath>
#include <iomanip>
#define PI 3.141592653589793238
using namespace std;

int N, F, r[10010];

bool f(double V)
{
    int s = 0;
    for (int i = 0; i < N; i++)
    {
        s += (int)(PI * r[i] * r[i] / V);
    }
    return s >= F + 1 ? true : false;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> N >> F;
        for (int i = 0; i < N; i++)
        {
            cin >> r[i];
        }
        double L = 0, H = 10e18;
        while (H - L >= 10e-7)
        {
            double M = (L + H) / 2;
            if (f(M))
                L = M;
            else
                H = M;
        }
        cout << fixed << setprecision(6) << H;
    }
    return 0;
}
