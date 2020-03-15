#include <bits/stdc++.h>
using namespace std;

// dp[i]: i個目までのサプリを摂取する方法の総数
// dp[0] = 0
// dp[i] = 区間[j, i)において「複数種類のサプリが存在しない」という条件を満たすようなjについて，dp[j]の総和
// dp[i]を考えるとき，区間[j, i)において「複数種類のサプリが存在しない」ならば，i個目までのサプリを摂取する方法の総数は，dp[j]通りあるサプリの摂取方法と同数

const int MOD = 1000000007;
int dp[110000];
int sum[110000];

int main() {
    int N, M; cin >> N >> M;
    vector<int> f(N);
    for (int i = 0; i < N; i++) {
        cin >> f[i];
        f[i]--;
    }

    vector<int> fnum(M, 0);
    vector<int> L(N+1, 0);
    int left = 0;
    for (int right = 0; right < N; right++) {
        fnum[f[right]]++;
        while (left < right && 1 < fnum[f[right]]) {
            fnum[f[left]]--;
            left++;
        }
        L[right+1] = left;
    }

    dp[0] = 1;
    sum[0] = 0; sum[1] = 1;
    for (int i = 1; i <= N; i++) {
        dp[i] = (sum[i] - sum[L[i]] + MOD) % MOD;
        sum[i+1] = (sum[i] + dp[i]) % MOD;
    }

    cout << dp[N] << endl;
    return 0;
}