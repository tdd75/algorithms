#include <bits/stdc++.h>
using namespace std;
 
vector<int > adj[100010];
vector<int > component(100010, -1);
int N, M, components = 0;
 
void find_component(int cur_comp, int u)
{
    if (component[u] != -1)
        return;
    component[u] = cur_comp;
    for (int i = 0; i < adj[u].size(); i++)
    {
        find_component(cur_comp, adj[u][i]);
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
        if (component[u] == -1)
        {
            find_component(components, u);
            components++;
        }
    }
    cout << components;
    return 0;
}
