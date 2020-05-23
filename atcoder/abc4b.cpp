#include <bits/stdc++.h>
using namespace std;

int main()
{
    vector<vector<string>> c(4, vector<string>(4));
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> c[i][j];
        }
    }
    vector<vector<string>> d(4, vector<string>(4));
    for (int i = 3; - 1 < i; i--)
    {
        for (int j = 3; - 1 < j; j--)
        {
            d[i][j] = c[3 - i][3 - j];
        }
    }
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
            if (j != 3)
                cout << d[i][j] << " ";
            else
                cout << d[i][j];
        cout << endl;
    }
    return 0;
}