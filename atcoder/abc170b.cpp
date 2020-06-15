#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    if (Y % 2 == 1)
    {
        cout << "No" << endl;
        return 0;
    }
    int a = 2 * X - Y / 2, b = Y / 2 - X;
    if (a < 0 || b < 0)
    {
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}