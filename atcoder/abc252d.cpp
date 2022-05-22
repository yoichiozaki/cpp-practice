#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    const int UPPER = 200000;
    vector<long long> cnt(UPPER + 1, 0);
    for (int i = 0; i < N; i++) cnt[A[i]] += 1;
    for (int i = 0; i < UPPER; i++) cnt[i + 1] += cnt[i];
    long long ans = 0;
    for (int i = 0; i < N; i++) ans += cnt[A[i] - 1] * (N - cnt[A[i]]);
    cout << ans << endl;
    return 0;
}