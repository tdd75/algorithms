#include <iostream>
#include <stack>
using namespace std;

int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        stack<char> s;
        s.push(0);
        string line;
        cin >> line;
        for (char bracket : line)
        {
            if (s.top() == '(' && bracket == ')' || s.top() == '[' && bracket == ']' || s.top() == '{' && bracket == '}')
            {
                s.pop();
            }
            else
            {
                s.push(bracket);
            }
        }
        if (s.top() == 0)
        {
            cout << 1 << endl;
        }
        else
        {
            cout << 0 << endl;
        }
    }
    return 0;
}