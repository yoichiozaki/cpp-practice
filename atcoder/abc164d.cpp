#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(), s.end());
    int x = 1, total = 0;
    vector<int> cnt(2019); // cnt[i]: 2019で割ったあまりがiとなる数字の個数
    long long ans = 0;
    for (int i = 0; i < n; i++)
    {
        cnt[total] += 1;
        total += (s[i] - '0') * x; // xの桁の数字まで
        total %= 2019;
        ans += cnt[total];
        x = x * 10 % 2019;
    }
    cout << ans << endl;
    return 0;
}