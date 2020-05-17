#include <bits/stdc++.h>
using namespace std;

int check(int x)
{
    if (x == 1 || x == 3 || x == 5 || x == 7 || x == 8 || x == 10 || x == 12)
        return 0;
    else if (x == 4 || x == 6 || x == 9 || x == 11)
        return 1;
    else
        return 2;
}

int main()
{
    int x, y;
    cin >> x >> y;
    int sx, sy;
    sx = check(x);
    sy = check(y);
    if (sx == sy)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    return 0;
}