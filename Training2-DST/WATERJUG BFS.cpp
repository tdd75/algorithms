#include <iostream>
#include <queue>
#define MAX 900
using namespace std;
struct state
{
    int x, y, step;
};

bool visited[MAX][MAX] = {false};

int waterjugBFS(int a, int b, int c)
{
    queue<state> q;
    q.push({0, 0, 0});
    visited[0][0] = true;
    state p;
    while (!q.empty())
    {
        p = q.front();
        if (p.x == c || p.y == c)
            return p.step;

        // fill jug a
        if (p.x < a)
        {
            if (!visited[a][p.y])
            {

                visited[a][p.y] = true;
                q.push({a, p.y, p.step + 1});
            }
            // pour a to b
            if (p.y > 0)
            {
                int min_xy = min(a - p.x, p.y);
                if (!visited[p.x + min_xy][p.y - min_xy])
                {
                    visited[p.x + min_xy][p.y - min_xy] = true;
                    q.push({p.x + min_xy, p.y - min_xy, p.step + 1});
                }
            }
        }
        // fill jug b
        if (p.y < b)
        {
            if (!visited[p.x][b])
            {

                visited[p.x][b] = true;
                q.push({p.x, b, p.step + 1});
            }
            // pour b to a
            if (p.x > 0)
            {
                int min_xy = min(b - p.y, p.x);
                if (!visited[p.x - min_xy][p.y + min_xy])
                {
                    visited[p.x - min_xy][p.y + min_xy] = true;
                    q.push({p.x - min_xy, p.y + min_xy, p.step + 1});
                }
            }
        }
        // empty jug a
        if (p.x > 0)
        {
            if (!visited[0][p.y])
            {
                visited[0][p.y] = true;
                q.push({0, p.y, p.step + 1});
            }
        }
        // empty jug b
        if (p.y > 0)
        {
            if (!visited[p.x][0])
            {
                visited[p.x][0] = true;
                q.push({p.x, 0, p.step + 1});
            }
        }
        q.pop();
    }
    return -1;
}

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    cout << waterjugBFS(a, b, c);
    return 0;
}