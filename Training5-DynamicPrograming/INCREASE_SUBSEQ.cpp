#include<bits/stdc++.h>
using namespace std;
 
int a[10010];
int mem[10010];
int best;
// memset(mem, -1, sizeof(mem));
int lis(int i)
{
    if (mem[i] != -1)
    {
        return mem[i];
    }
    int res = 1;
    for (int j = 0; j < i; j++)
    {
        if (a[j] < a[i])
        {
            res = max(res, 1 + lis(j));
        }
    }
    mem[i] = res;
    return res;
}
 
int main()
{
    int n;
    cin >> n;
    for(int i = 0; i < n; i ++)
    {
        cin >> a[i];
        mem[i] = -1;
    }
    for(int i = 0; i < n; i ++)
    {
        best = max(best, lis(i));
    }
    cout << best;
    return 0;
}