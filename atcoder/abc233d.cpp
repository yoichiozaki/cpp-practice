#include <bits/stdc++.h>

using namespace std;

// 区間和 -> 累積和を使う
int main()
{
    long long N, K;
    cin >> N >> K;
    vector<long long> A(N);
    for (int i = 0; i < N; i++)
        cin >> A[i];
    vector<long long> S(N + 1);
    for (long long i = 0; i < N; i++)
        S[i + 1] = S[i] + A[i];
    map<long long, long long> T;
    long long ans = 0;
    for (long long r = 1LL; r < N + 1; r++)
    {
        T[S[r - 1LL]] += 1LL;
        ans += T[S[r] - K];
    }
    cout << ans << endl;
    return 0;
}