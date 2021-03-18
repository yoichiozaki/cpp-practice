#include <bits/stdc++.h>
using namespace std;

int main()
{
    int X, Y;
    cin >> X >> Y;
    if (max(X, Y) < min(X, Y) + 3)
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}