#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    int cx = 0, cy = 0;
    for (int x = 1; x <= X; x++)
    {
        if (X % x == 0)
            cx += 1;
    }
    for (int y = 1; y <= Y; y++)
    {
        if (Y % y == 0)
            cy += 1;
    }
    if (cx > cy)
        cout << "X" << endl;
    else if (cx < cy)
        cout << "Y" << endl;
    else
        cout << "Z" << endl;
    return 0;
}