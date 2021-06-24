#include <bits/stdc++.h>

using namespace std;

int main()
{
    // 場合分けが少ない変数に対して全探索
    long long N;
    cin >> N;
    long long ans = (1LL << 60);
    for (int i = 0; i <= 60; i++)
    {
        long long a = N / (1LL << i);
        long long b = i;
        long long c = N - a * (1LL << i);
        ans = min(ans, a + b + c);
    }
    cout << ans << endl;
    return 0;
}