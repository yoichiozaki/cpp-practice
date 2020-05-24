#include <bits/stdc++.h>
using namespace std;

void vprintl(vector<int> v)
{
    for (int i = 0; i < v.size() - 1; i++)
        cout << v[i] << " ";
    cout << v[v.size() - 1] << endl;
}

int main()
{
    int n;
    while (cin >> n, n)
    {
        vector<int> s(n);
        for (int i = 0; i < n; i++)
            cin >> s[i];
        int cnt = 0;
        vector<int> prev(n, 0);
        while (prev != s)
        {
            prev = s;
            map<int, int> m;
            for (int i = 0; i < n; i++)
                m[s[i]]++;
            for (int i = 0; i < n; i++)
                s[i] = m[s[i]];
            cnt++;
        }
        cout << cnt - 1 << endl;
        vprintl(s);
    }
    return 0;
}