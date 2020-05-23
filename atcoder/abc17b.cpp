#include <bits/stdc++.h>
using namespace std;

int main()
{
    string X;
    cin >> X;
    for (int i = 0; i < X.size();)
    {
        if (X[i] == 'c' && X[i + 1] == 'h')
            i += 2;
        else if (X[i] == 'o')
            i++;
        else if (X[i] == 'k')
            i++;
        else if (X[i] == 'u')
            i++;
        else
        {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}