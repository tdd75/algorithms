#include <iostream>
#include <queue>
using namespace std;

int main()
{
    int a[] = {2, 1, 4};
    int b = a[1];
    a[1] = 10;
    cout << b;
}