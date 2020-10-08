#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int N, Q, temp;
vector<int> v;

int main()
{
    int p, c, result = 1;
    cin >> N;
    while (N--)
    {
        cin >> temp;
        v.push_back(temp);
    }
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i] != v[i - 1])
        {
            result++;
        }
    }
    cin >> Q;
    while (Q--)
    {
        cin >> p >> c;
        p--; // sync index with vector
        if (p == 0)
        {
            // remove old road
            if (v[p + 1] != v[p])
            {
                result--;
            }
            // add new road
            v[p] = c;
            if (v[p + 1] != c)
            {
                result++;
            }
        }
        else if (p == v.size() - 1)
        {
            // remove old road
            if (v[p - 1] != v[p])
            {
                result--;
            }
            // add new road
            v[p] = c;
            if (v[p - 1] != c)
            {
                result++;
            }
        }
        else
        {
            // remove old road
            if (v[p - 1] != v[p] && v[p + 1] != v[p])
            {
                result--;
            }
            // add new road
            v[p] = c;
            if (v[p - 1] != c && v[p + 1] != c)
            {
                result++;
            }
        }
        cout << result << endl;
    }
    return 0;
}