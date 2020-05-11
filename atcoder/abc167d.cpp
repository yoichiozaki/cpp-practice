#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    int n;
    ll k;
    cin >> n >> k;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> s;
    vector<int> ord(n + 1, -1);

    int cycle = 1, leg = 0;
    {
        int now = 1;
        while (ord[now] == -1)
        { // nowが未訪問ならwhileに入る
            ord[now] = s.size();
            s.push_back(now);
            now = a[now - 1];
        }
        cycle = s.size() - ord[now];
        leg = ord[now];
    }

    if (k < leg)
        cout << s[k] << endl;
    else
    {
        k -= leg;
        k %= cycle;
        cout << s[leg + k] << endl;
    }
    return 0;
}