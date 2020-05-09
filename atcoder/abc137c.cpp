#include <bits/stdc++.h>
using namespace std;

// アナグラムの判定法
// 1: 文字種とその回数が一致することをsetなどで確認
// 2: ソートした結果が等しいかを確認

int main()
{
    int N;
    cin >> N;
    map<string, long long> table;
    for (int i = 0; i < N; i++)
    {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        table[s]++;
    }
    long long ans = 0;
    for (auto item : table)
    {
        ans += item.second * (item.second - 1) / 2;
    }
    cout << ans << endl;
    return 0;
}