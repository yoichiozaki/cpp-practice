#include <bits/stdc++.h>

using namespace std;

bool check(string s, string t)
{
    int slen = s.length();
    int tlen = t.length();

    for (int i = 0; i < slen - tlen + 1; i++)
    {
        bool ok = true;
        for (int j = 0; j < tlen; j++)
        {
            if (t[j] == '.')
                continue;
            if (s[i + j] != t[j])
                ok = false;
        }
        if (ok)
        {
            return true;
        }
    }
    return false;
}

vector<string> Ts;

void dfs(int pos, string sofar)
{
    if (0 < pos)
        Ts.push_back(sofar);
    if (pos == 3)
        return;

    for (int i = 0; i < 26; i++)
    {
        dfs(pos + 1, sofar + char('a' + i));
    }
    dfs(pos + 1, sofar + ".");
}

int main()
{
    string S;
    cin >> S;

    dfs(0, "");

    int ans = 0;
    for (auto T : Ts)
    {
        if (check(S, T))
            ans += 1;
    }

    cout << ans << endl;
    return 0;
}