#include <bits/stdc++.h>
using namespace std;

int main()
{
    int A, B, C;
    cin >> A >> B >> C;
    if (A > B && B > C)
    {
        cout << 1 << endl
             << 2 << endl
             << 3 << endl;
    }
    else if (A < B && B < C)
    {
        cout << 3 << endl
             << 2 << endl
             << 1 << endl;
    }
    else if (A > B && A < C)
    {
        cout << 2 << endl
             << 3 << endl
             << 1 << endl;
    }
    else if (A < B && A > C)
    {
        cout << 2 << endl
             << 1 << endl
             << 3 << endl;
    }
    else if (C < B && A < C)
    {
        cout << 3 << endl
             << 1 << endl
             << 2 << endl;
    }
    else if (C > B && A > C)
    {
        cout << 1 << endl
             << 3 << endl
             << 2 << endl;
    }
    return 0;
}