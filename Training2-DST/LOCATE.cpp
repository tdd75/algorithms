#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define N 1000
using namespace std;

vector<pair<int, int>> a, b;
int dis[2 * N][2 * N];

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int L, C, max_s = 0;
        cin >> L >> C;
        int check;
        // input array1
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> check;
                if (check)
                {
                    a.push_back(make_pair(i, j));
                }
            }
        // input array2
        for (int i = 0; i < L; i++)
            for (int j = 0; j < C; j++)
            {
                cin >> check;
                if (check)
                {
                    b.push_back(make_pair(i, j));
                }
            }
        for (int i = 0; i < a.size(); i++)
            for (int j = 0; j < b.size(); j++)
            {
                int u = a[i].first - b[j].first;
                int v = a[i].second - b[j].second;
                // increase element of array and update max value
                max_s = max(max_s, ++dis[u + N][v + N]);
            }
        cout << max_s << endl;
        // reset array and vector
        a.clear(), b.clear();
        memset(dis, 0, sizeof(dis));
    }

    return 0;
}