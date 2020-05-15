#include <bits/stdc++.h>
using namespace std;

int n, m, p, d;
bool x[32][100], y[32][100];
bool judge()
{
    int A = p;
    for (int i = d; i >= 1; i--)
    {
        if (y[i][A - 1] == true)
            A--;
        else if (y[i][A] == true)
            A++;
    }
    if (A == m)
        return true;
    return false;
}
int main()
{
    while (true)
    {
        for (int i = 0; i < 3200; i++)
        {
            x[i / 100][i % 100] = false;
            y[i / 100][i % 100] = false;
        }
        cin >> n;
        if (n == 0)
            break;
        cin >> m >> p >> d;
        for (int i = 1; i <= d; i++)
        {
            string S;
            cin >> S;
            for (int j = 0; j < n - 1; j++)
            {
                x[i][j + 1] = (bool)(S[j] - '0');
                y[i][j + 1] = x[i][j + 1];
            }
        }
        if (judge() == true)
        {
            cout << "0" << endl;
            goto E;
        }
        for (int i = 1; i <= d; i++)
        {
            for (int j = 1; j < n; j++)
            {
                if (y[i][j - 1] == true || y[i][j + 1] == true || y[i][j] == true)
                    continue;
                y[i][j] = true;
                if (judge() == true)
                {
                    cout << i << ' ' << j << endl;
                    goto E;
                }
                y[i][j] = false;
            }
        }
        cout << "1" << endl;
    E:;
    }
    return 0;
}