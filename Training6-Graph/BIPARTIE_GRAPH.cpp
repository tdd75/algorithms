#include <bits/stdc++.h>
using namespace std;
 
int N, M, components = 0;
vector<int> adj[100010];
vector<int> side(100010, -1);
 
int is_bipartite = 1;
void check_bipartite(int u)
{
    for (int i = 0; i < adj[u].size(); i++)
    {
        int v = adj[u][i];
        if (side[v] == -1)
        {
            side[v] = 1 - side[u];
            check_bipartite(v);
        }
        else if (side[u] == side[v])
        {
            is_bipartite = 0;
        }
    }
}
 
int main()
{
    cin >> N >> M;
    int v1, v2;
    while (M--)
    {
        cin >> v1 >> v2;
        adj[v1].push_back(v2);
        adj[v2].push_back(v1);
    }
    for (int u = 1; u <= N; u++)
    {
        if (side[u] == -1)
        {
            side[u] = 0;
            check_bipartite(u);
        }
    }
    cout << is_bipartite;
    return 0;
}
