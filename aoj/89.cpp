#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    int d[102][102] = {}, r = 0;
    while (getline(cin, s))
    {
        int c = 1, digit = 0;
        string t;
        for (int i = 0; i < s.size(); ++i)
            if (s[i] == ',')
                d[r][c++] = atoi(t.c_str()), t = "";
            else
                t += s[i];
        d[r++][c] = atoi(t.c_str());
    }
    int m[102][102] = {};
    m[0][1] = d[0][1];
    int n = r / 2 + 1;
    for (int i = 1; i < n; i++)
        for (int j = 1; j < 102; j++)
            m[i][j] = d[i][j] + max(m[i - 1][j - 1], m[i - 1][j]);
    for (int i = n; i < r; i++)
        for (int j = 1; j < 101; j++)
            m[i][j] = d[i][j] + max(m[i - 1][j], m[i - 1][j + 1]);
    cout << m[r - 1][1] << endl;
    return 0;
}