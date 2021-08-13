#include <bits/stdc++.h>
#include <vector>

using namespace std;

int main()
{
    // 累積和を用意しておく
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (long long i = 0; i < N; i++)
        cin >> A[i];
    vector<long long> cumulative_sum(N + 10);
    cumulative_sum[0] = A[0];
    for (long long i = 1; i < N; i++)
    {
        cumulative_sum[i] = cumulative_sum[i - 1] + A[i];
    }
    for (int x = 0; x < N - K + 1; x++)
    {
        long long ans = cumulative_sum[x + K - 1];
        if (x != 0)
            ans -= cumulative_sum[x - 1];
        printf("%lld\n", ans);
    }
    return 0;
}