#include <bits/stdc++.h>
using namespace std;

vector<int> adj[1000000];
vector<int> f(1000000, -1);

int main()
{
    int n, s, g, u, d;
    cin >> n >> s >> g >> u >> d;
    queue<int> q;
    q.push(s);
    f[s] = 0;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        for (int y : {x + u, x - d})
        {
            if (y >= 1 && y <= n && f[y] == -1)
            {
                f[y] = f[x] + 1;
                q.push(y);
            }
        }
    }
    if (f[g] == -1)
        cout << "use the stairs";
    else
    {
        cout << f[g];
    }

    return 0;
}