#include<iostream>
#include<fstream>
#include<vector>
#include<string>

#define Begin   0
#define End     2
#define topLeft     4
#define topRight    5
#define bottomLeft  6
#define bottomRight 7
typedef struct
{
    int x;
    int y;
}   coord;
using namespace std;
vector<vector<int> > square(3);

int is_corner(int y, int x)
{
    if (y == Begin && x == Begin)
        return topLeft;
    else if (y == Begin && x == End)
        return topRight;
    else if (y == End && x == Begin)
        return bottomLeft;
    else if (y == End && x == End)
        return bottomRight;
    return 0;
}

bool    check_row(int y)
{
    if (square[y][0]+square[y][1]+square[y][2] == 15)
        return (true);
    return (false);
}

bool    check_col(int x)
{
    if (square[0][x]+square[1][x]+square[2][x] == 15)
        return (true);
    return (false);
}
bool    check_frst_diag()
{
    if (square[0][0]+square[1][1]+square[2][2] == 15)
        return (true);
    return (false);
}
bool    check_scnd_diag()
{
    if (square[0][2]+square[1][1]+square[2][0] == 15)
        return (true);
    return (false);
}
bool    calculate_corners(int corner)
{
    if (corner == topLeft || corner == bottomRight)
        if (!check_frst_diag())
            return false;
    if (corner == topRight || corner == bottomRight)
        if (!check_scnd_diag())
            return false;
    if (corner == topLeft)
        if(!check_row(0) || !check_col(0))
            return (false);
    if (corner == topRight)
        if(!check_row(0) || !check_col(2))
            return (false);
    if (corner == bottomLeft)
        if(!check_row(2) || !check_col(0))
            return (false);
    if (corner == bottomRight)
        if(!check_row(2) || !check_col(2))
            return (false);
    return (true);
}
bool    is_axis(int y,int x)
{
    if (x == y + 1 || x == y - 1)
        return true;
    if (y == x + 1 || y == x - 1)
        return true;
    return false;
}

bool    calculate_axes(int y, int x)
{
    if (!check_row(y) || !check_col(x))
        return (false);
    return true;
}

bool    calculate_center()
{
    if(!check_frst_diag() || !check_scnd_diag() || !check_row(1) || !check_col(1))
        return (false);
    return true;
}

bool    check_sum(int y, int x)
{
    int res;
    if ((res = is_corner(y, x)))
        if(!calculate_corners(res))
            return (false);
    if (is_axis(y,x))
        if(!calculate_axes(y,x))
            return (false);
    if (x == 1 && y == 1)
        if(!calculate_center())
            return (false);
    return true;
}

void    print_square()
{
    for (int i = 0; i < 3; i++)
        cout << square[i][0] << " " << square[i][1] << " " << square[i][2] << endl;
}
void    print_to_file()
{
    ofstream out;
    out.open("out.txt", ios_base::app);
    for (int i = 0; i < 3; i++)
        out << square[i][0] << " " << square[i][1] << " " << square[i][2] << endl;
    out.close();
}

coord   get_next_point(int y, int x)
{
    coord res;
    if (x == 2 && y == 2)
    {
        res.x = -1;
        res.y = -1;
        return res;
    }
    if(x > 2)
    {
        res.x = x+1;
        res.y = y;
    }
    else
    {
        res.x = 0;
        res.y = y+1;
    }
    return res;
}

int     solve()
{
    int coast = 0;
    int change, old;
    for (int y = 0; y < 3; y++)
    {
        change = 1;
        old = 0;
        for(int x = 0; x < 3; x++)
        {
            if (old == 0)
                old = square[y][x];
            if (check_sum(y, x))
            {
                coast += abs(old - change);
            }
            else
            {
                if (change == 10)
                {
                    square[y][x] = old;
                    break ;
                }
                if (old != change)
                    square[y][x] = change;
                change++;
                x--;
            }
        }
        print_to_file();
    }
    return coast;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        square[i].resize(3);
        for (int j = 0; j < 3; j++)
        {
            cin >> square[i][j];
        }
    }
    int coast = solve();
    print_square();
    cout << coast << endl;
    return (0);
}