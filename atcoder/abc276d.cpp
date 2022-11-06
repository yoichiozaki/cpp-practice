#include <bits/stdc++.h>

using namespace std;

int main() {
    int N; cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];
    int g = 0;
    for (int i = 0; i < N; i++) g = gcd(g, A[i]);
    int ans = 0;
    for (int i = 0; i < N; i++) {
        A[i] /= g;
        while (A[i] % 2 == 0) {
            A[i] /= 2;
            ans++;
        }
        while (A[i] % 3 == 0) {
            A[i] /= 3;
            ans++;
        }
        if (A[i] != 1) {
            cout << -1 << endl;
            return 0;
        }
    }
    cout << ans << endl;
    return 0;
}