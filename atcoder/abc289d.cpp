#include <bits/stdc++.h>

using namespace std;

int main() {
    unsigned long N; cin >> N;
    vector<unsigned long> A(N);
    for (auto &&a : A) cin >> a;

    unsigned long M; cin >> M;
    vector<unsigned long> B(M);
    for (auto &&b : B) cin >> b;

    unsigned long X; cin >> X;

    vector<unsigned long> dp(X + 1), available(X + 1, 1);
    for (const auto b : B) available[b] = 0;

    dp[0] = 1;
    for (unsigned long i = 1; i <= X; i++) {
        if (!available[i]) dp[i] = 0;
        else {
            for (const auto a : A) {
                if (i >= a) dp[i] |= dp[i - a];
            }
        }
    }
    cout << (dp[X] ? "Yes" : "No") << endl;
    return 0;
}