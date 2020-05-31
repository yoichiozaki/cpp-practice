#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N;
    cin >> N;
    map<string, long long> m;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        m[s]++;
    }
    long long ans = 0LL;
    for (auto item : m)
    {
        ans += (item.second * (item.second - 1)) / 2LL;
    }
    cout << ans << endl;
    return 0;
}