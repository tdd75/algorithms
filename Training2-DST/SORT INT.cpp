#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
vector<int> arr;
 
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        arr.push_back(number);
    }
    sort(arr.begin(), arr.end());
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}