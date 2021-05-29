#include <bits/stdc++.h>
#pragma GCC optimize("-O3")
using namespace std;

int main()
{
    int X, Y, Z;
    cin >> X >> Y >> Z;
    if (Z * Y % X == 0)
    {
        cout << Z * Y / X - 1 << endl;
    }
    else
    {
        cout << Z * Y / X << endl;
    }
    return 0;
}