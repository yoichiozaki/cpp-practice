#include <bits/stdc++.h>

using namespace std;

int main() {
    long long N, K, X; cin >> N >> K >> X;
    long long A[200005];
    for (int i = 1; i <= N; i++) cin >> A[i];

    long long ans = 0;
    for (int i = 1; i <= N; i ++) ans += A[i];

    long long used = 0;
    for (int i = 1; i <= N; i++) used += A[i] / X;
    used = min(used, K);
    ans -= used * X;
    K -= used;

    for (int i = 1; i <= N; i++) A[i] %= X;
    sort(A + 1, A + N + 1);

    for (int i = N; 1 <= i; i--) {
        if (K == 0) break;
        ans -= A[i];
        K--;
    }

    cout << ans << endl;

    return 0;
}