#include <bits/stdc++.h>

using namespace std;

int main()
{
    int S, T, X;
    cin >> S >> T >> X;
    if (S < T)
    {
        if (S <= X && X < T)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    else
    {
        if (X < T || S <= X)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
}