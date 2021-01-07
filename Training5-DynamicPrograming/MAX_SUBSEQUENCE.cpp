#include <iostream>
using namespace std;
 
int arr[1000010];
int mem[1000010];
bool comp[1000010];
// memset(comp, 0, sizeof(comp));
int max_sum(int i)
{
    if (i == 0)
    {
        return arr[i];
    }
    if (comp[i])
    {
        return mem[i];
    }
    int res = max(arr[i], arr[i] + max_sum(i - 1));
    mem[i] = res;
    comp[i] = true;
    return res;
}
 
int main()
{
    int n, maximum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    max_sum(n - 1);
    for (int i = 0; i < n; i++)
    {
        maximum = max(maximum, mem[i]);
    }
    cout << maximum;
}