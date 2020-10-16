#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    unsigned long long Q, N, T, T2, count, newT;
    cin >> Q;
    while (Q--)
    {
        cin >> N;
        T = N * (N + 1) * (N + 2);
        count = 0;
        for (unsigned long long i = 2; i < T; i++)
        {
            newT = T % i;
            if (newT != 0 && ((newT * T) % i == 0)
            {
                count++;
            }
        }
        cout << count << endl;
    }
    return 0;
}
