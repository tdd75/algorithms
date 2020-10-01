#include <iostream>
#include <vector>
using namespace std;

struct position
{
    int x;
    int y;
};

vector<position> array1, array2, direction;

void input(vector<position> array, int L, int C)
{
    for (int i = 0; i < L; i++)
    {
        for (int j = 0; j < C; j++)
        {
            int check;
            cin >> check;
            if (check)
            {
                position element;
                element.x = i;
                element.y = j;
                array1.push_back(element);
            }
        }
    }
}

void divide(position array1, position array2)
{
    position array;
    array.x = array1.x - array2.x;
    array.y = array1.y - array2.y;
    
}


int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        int L, C;
        cin >> L >> C;
        input(array1, L, C);
        input(array2, L, C);
    }
    return 0;
}