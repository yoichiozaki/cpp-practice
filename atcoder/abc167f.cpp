#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

// (: +1, ): -1
// カッコ列は折れ線にする
// 正しいカッコ列の条件: (1) 合計が0 (2) 途中で0未満にならない
// 基準点から「最下点は相対的にいくつ上か」と「最終点はいくつ上か」

bool check(vector<P> s)
{
    int h = 0;
    for (P p : s)
    {
        int b = h + p.first;
        if (b < 0)
            return false;
        h += p.second;
    }
    return true;
}

int main()
{
    int n;
    cin >> n;
    vector<P> ls, rs;
    int total = 0;
    rep(i, n)
    {
        string s;
        cin >> s;
        int h = 0, b = 0;
        for (char c : s)
        {
            if (c == '(')
                ++h;
            else
                --h;
            b = min(b, h);
        }
        if (h > 0)
            ls.emplace_back(b, h);
        else
            rs.emplace_back(b - h, -h);
        total += h;
    }

    // 最終点が大きい順ではなくて，最下点が大きい順：最下点が大きい順が一番余裕がある並べ方になるはずで，それでもだめなら絶対にできない
    sort(ls.rbegin(), ls.rend()); // 各パーツを最下点について降順にソート
    sort(rs.rbegin(), rs.rend());
    if (check(ls) && check(rs) && total == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}
