#include <bits/stdc++.h>

using namespace std;

int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> cnt(N + 100, 0);
    for (long long i = 0; i < N; i++)
    {
        long long A;
        cin >> A;
        cnt[A] += 1;
    }
    long long ans = 0;
    for (long long i = 0; i < N && 0 < K; i++)
    {
        K = min(K, cnt[i]);
        ans += K;
    }
    cout << ans << endl;
    return 0;
}