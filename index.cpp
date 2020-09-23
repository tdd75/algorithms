// #include <iostream>
// #include <vector>
// using namespace std;

// vector<int> res;

// int main()
// {
//     unsigned long int n;
//     do
//     {
//         unsigned long int x, head = 1, value = 0, count = 0, max = 0;
//         cin >> n;
//         if (n == 0)
//             break;
//         for (int i = 0; i < n; i++)
//         {
//             cin >> x;
//             if (x != value)
//             {
//                 if ((i - head) * value  > max)
//                     max = (i - head) * value;
//                 head = i;
//                 value = x;
//                 count = 1;
//             }
//             else
//             {
//                 count++;
//             }
//         }
//         res.push_back(max);
//     } while (n != 0);
//     for (int value : res)
//     {
//         cout << value << endl;
//     }
//     return 0;
// }

#include <iostream>
using namespace std;
 
int main()
{
    unsigned long long int a, b, div = 1000000007;
    cin >> a >> b;
    long res = 1;
    a %= div, b %= div - 1;
    while (b > 0)
    {
        if (b % 2 > 0)
            res = res * a % div;
        a = a * a % div;
        b /= 2;
    }
    cout << res;
    return 0;
}