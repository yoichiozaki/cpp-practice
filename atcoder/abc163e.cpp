#include <bits/stdc++.h>
using namespace std;

using ll = long long;

// その幼児の移動方向が決まれば，もともと並んでいた位置に関わらず，最適な移動後の位置が決定する
// 移動方向が右なら，最も列の先頭に近い位置だし，移動方向が左なら，最も列の末尾に近い位置になる

const ll INF = 1e18;
const int MX = 2005;
ll dp[MX][MX];
inline void chmax(ll &a, ll b)
{
    a = max(a, b);
}

// dp[i][l]: 大きい順に並べたときの上位i個を対象に，l個を左に詰めていき，i-l個を右に詰めていくときの嬉しさの最大値

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n + 1; i++)
        for (int j = 0; j < n + 1; j++)
            dp[i][j] = -INF;
    dp[0][0] = 0;

    vector<pair<int, int>> p;
    for (int i = 0; i < n; i++)
    {
        p.emplace_back(a[i], i);
    }

    sort(p.rbegin(), p.rend()); // 幼児を大きい順に並べる

    for (int i = 0; i < n; i++)
    {
        int pi = p[i].second; // i番目の幼児の元の位置
        for (int l = 0; l <= i; l++)
        {
            int r = i - l;
            chmax(dp[i + 1][l + 1], dp[i][l] + ll(pi - l) * a[pi]);       // 左に詰めた時
            chmax(dp[i + 1][l], dp[i][l] + ll((n - r - 1) - pi) * a[pi]); // 右に詰めた時
        }
    }

    ll ans = 0;
    for (int i = 0; i <= n; i++)
        chmax(ans, dp[n][i]);
    cout << ans << endl;
    return 0;
}