#include <bits/stdc++.h>

using namespace std;

int main() {;
    int N, M; cin >> N >> M;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    vector<long long> accum(N + 1, 0LL);
    for (int i = 1; i <= N; i++) accum[i] = accum[i - 1] + A[i - 1];
    vector<long long> B(N - M + 1);
    long long now = 0;
    for (int i = 0; i < M; i++) now += A[i] * (i + 1);
    B[0] = now;
    for (int i = 1; i < N - M + 1; i++) B[i] = B[i - 1] + M * A[M + i - 1] - (accum[M + i - 1] - accum[i - 1]);
    long long ans = -1000000000000000000ll;
    for (int i = 0; i < N - M + 1; i++) ans = max(ans, B[i]);
    cout << ans << endl;
    return 0;
}