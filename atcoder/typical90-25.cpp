#include <bits/stdc++.h>

using namespace std;

long long N, B;
long long ans = 0;

// f(x) := xの各桁の積
// "x"を降順にソートした結果が同じならf(x)も同じ

void rec(int pos, int last, string current)
{
    if (pos == 0)
    { // currentは11桁の数字列
        long long f = 1;
        for (int i = 0; i < current.size(); i++)
            f *= (long long)(current[i] - '0');
        long long m = f + B; // m - f(m) = B
        if (m <= N)
        {
            string m_str = to_string(m);
            sort(m_str.begin(), m_str.end());
            reverse(m_str.begin(), m_str.end());
            if (m_str == current)
            {
                ans += 1;
            }
        }
        return;
    }

    for (int i = last; 1 <= i; i--)
    {
        string next_str = current;
        next_str += ('0' + i);
        rec(pos - 1, i, next_str);
    }
}

int main()
{
    cin >> N >> B;

    // 11桁の数字列を降順にソートしたものを全探索
    for (int i = 1; i <= 11; i++)
        rec(i, 9, "");

    string B_str = to_string(B);
    bool has_zero = false;
    for (int i = 0; i < B_str.size(); i++)
        if (B_str[i] == '0')
            has_zero = true;
    if (has_zero && B <= N)
        ans += 1; // m - f(m) = B で f(m) = 0となる場合を足してる
    cout << ans << endl;
    return 0;
}