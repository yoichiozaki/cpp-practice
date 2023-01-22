#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    long long A, B; cin >> A >> B;
    string S; cin >> S;
    S += S;
    long long ans = 1LL << 60;
    for (int i = 0; i < N; i++) {
        long long tmp = A * i;
        for (int j = 0; j < N / 2; j++) {
            int l = i + j;
            int r = i + N - 1 - j;
            if (S[l] != S[r]) tmp += B;
        }
        ans = min(ans, tmp);
    }
    cout << ans << endl;
    return 0;
}