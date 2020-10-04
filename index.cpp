#include <iostream>
#include <queue>
using namespace std;

queue<int> q;

int main()
{
    q.push(1);
    int p = q.front();
    q.push(3);
    q.push(5);
    cout << p;
    }