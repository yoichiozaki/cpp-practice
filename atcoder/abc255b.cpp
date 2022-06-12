#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<int> A(K);
    for (int i = 0; i < K; i++) {
        cin >> A[i];
        A[i]--;
    }
    vector<long long> X(N), Y(N);
    for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];
    long long ans = 0;
    for (int i = 0; i < N; i++) {
        long long d = 8e18;
        for (auto &j: A) {
            d = min(d, (X[i] - X[j]) * (X[i] - X[j]) + (Y[i] - Y[j]) * (Y[i] - Y[j]));
        }
        ans = max(ans, d);
    }
    cout << setprecision(12) << sqrt((double)ans) << endl;
    return 0;
}