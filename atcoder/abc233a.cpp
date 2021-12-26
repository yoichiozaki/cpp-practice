#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    if (Y <= X)
    {
        cout << 0 << endl;
        return 0;
    }
    if ((Y - X) % 10 == 0)
    {
        cout << (Y - X) / 10 << endl;
    }
    else
    {
        cout << (Y - X) / 10 + 1 << endl;
    }
    return 0;
}