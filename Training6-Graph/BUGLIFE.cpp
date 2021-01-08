#include <bits/stdc++.h>
using namespace std;

vector<int> adj[2000];
vector<int> side(2000, -1);
bool is_bipartite = true;

void reset()
{
    for (int i = 0; i < 2000; i++)
    {
        adj[i].clear();
        side[i] = -1;
    }
    is_bipartite = true;
}

void check_bipartite(int u)
{
    for (int i = 0; i < adj[u].size(); i++) //duyet het dinh
    {
        int v = adj[u][i]; // lay canh u - v
        if (side[v] == -1)
        {
            side[v] = 1 - side[u]; // colorize
            check_bipartite(v);
        }
        else if (side[u] == side[v])
        {
            is_bipartite = false;
            return;
        }
        if(!is_bipartite)
            break;
    }
}

int main()
{
    int sumTest;
    cin >> sumTest;
    for (int i = 1; i <= sumTest; i++)
    {
        int n, line;
        cin >> n >> line;
        while (line--)
        {
            int v1, v2;
            cin >> v1 >> v2;
            adj[v1].push_back(v2);
            adj[v2].push_back(v1);
        }
        cout << "Scenario #" << i << ":" << endl;
        for (int u = 0; u < n; u++)
        {
            if (side[u] == -1)
            {
                side[u] = 0;
                check_bipartite(u);
                if (!is_bipartite)
                {
                    cout << "Suspicious bugs found! " << endl;
                    break;
                }
            }
        }
        if (is_bipartite)
            cout << "No suspicious bugs found!" << endl;
        reset();
    }
    return 0;
}