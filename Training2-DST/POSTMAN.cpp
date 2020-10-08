#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct custommer
{
    long long x, m;
} temp;
vector<custommer> neg, pos;

long long n, k;

bool sortIncrease(custommer a, custommer b)
{
    return a.x < b.x;
}

unsigned long long result(vector<custommer> v)
{
    sort(v.begin(), v.end(), sortIncrease);
    unsigned long long s = 0;
    long long remain, i = v.size() - 1;
    while (i >= 0)
    {
        long long loop = v[i].m / k;
        if (loop * k != v[i].m)
        {
            loop++;
            s += v[i].x * loop * 2;
            remain = k * loop - v[i].m;
            i--;
            // back to postoffice
            while ((remain > 0) && (i >= 0))
            {
                if (remain >= v[i].m)
                {
                    remain -= v[i].m;
                    i--;
                }
                else
                {
                    v[i].m -= remain;
                    remain = 0;
                }
            }
        }
        else
        {
            s += v[i].x * (loop)*2;
            i--;
        }
    }
    return s;
}

int main()
{
    cin >> n >> k;
    while (n--)
    {
        long long x, m;
        cin >> x >> m;
        if (x < 0)
        {
            temp.x = -x;
            temp.m = m;
            neg.push_back(temp);
        }
        else
        {
            temp.x = x;
            temp.m = m;
            pos.push_back(temp);
        }
    }
    cout << result(neg) + result(pos);
    return 0;
}