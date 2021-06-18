#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c;
    cin >> a >> b >> c;
    if (c % 2)
    {
        if (a == b)
        {
            cout << "=";
        }
        else if (a < b)
        {
            cout << "<";
        }
        else
        {
            cout << ">";
        }
    }
    else
    {
        if (abs(a) == abs(b))
        {
            cout << "=";
        }
        else if (abs(a) < abs(b))
        {
            cout << "<";
        }
        else
        {
            cout << ">";
        }
    }
    cout << endl;
    return 0;
}