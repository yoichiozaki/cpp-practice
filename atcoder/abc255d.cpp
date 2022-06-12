#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, Q; cin >> N >> Q;
    vector<long long> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    sort(A.begin(), A.end());
    vector<long long> accum(N + 1, 0);
    for (long long i = 0; i < N; i++) accum[i + 1] = accum[i] + A[i];
    for (int i = 0; i < Q; i++) {
        long long X; cin >> X;
        long long k = distance(A.begin(), lower_bound(A.begin(), A.end(), X));
        long long ans = X * k - accum[k] - X * (N - k) + (accum[N] - accum[k]);
        cout << ans << endl;
    }
    return 0;
}