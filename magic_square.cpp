#include<iostream>
#include<vector>
#include<string>

#define Begin   0
#define End     3
#define topLeft     4
#define topRight    5
#define bottomLeft  6
#define bottomRight 7

using namespace std;
vector<vector<int>> square;

int is_corner(int x, int y)
{
    if (x == Begin && y == Begin)
        return topLeft;
    else if (x == Begin && y == End)
        return topRight;
    else if (x == End && y == Begin)
        return bottomLeft;
    else if (x == End && y == End)
        return bottomRight;
    return 0;
}

bool    calculate_corners(int corner)
{
    if (corner == topLeft || corner == bottomRight)
    {

    }
}

bool    check_sum(int x, int y)
{
    int res;
    if ((res = is_corner(x, y)))
        if(calculate_corners(res))
    return true;
}

int     solve()
{
    int coast = 0;
    int change;
    for (int x = 0; x < 3; x++)
    {
        change = 1;
        for(int y = 0; y < 3; y++)
        {
            if (check_sum(x, y))
                coast++;
            else
            {
                if (change == 10)
                    break ;
                square[x][y] = change;
                change++;
                y--;
            }
        }
    }
    return coast;
}

int main()
{
    string input;

    for (int i = 0; i < 3; i++)
    {
        square[i].resize(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> square[i][j];
        }
    }
    cout << solve() << endl;
    return (0);
}