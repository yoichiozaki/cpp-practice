#include <bits/stdc++.h>

using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    if (Y == 0)
        cout << "ERROR" << endl;
    else
    {
        cout << X / Y << "." << ((100 * X / Y) % 100 / 10) << ((100 * X / Y) % 10) << endl;
    }
    return 0;
}