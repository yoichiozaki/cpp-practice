#include <bits/stdc++.h>

using namespace std;

int main() {
    bool C[110][200010];
    int N; cin >> N;
    vector<int> A(N);
    for (auto& a: A) cin >> a;
    for (int i = 0, s, x; i < N; i++) {
        cin >> s;
        while (s--) {
            cin >> x;
            C[i][x] = true;
        }
    }
    int Q; cin >> Q;
    while (Q--) {
        int d; cin >> d;
        vector<int> v(d);
        for (auto& x: v) {
            cin >> x;
        }
        int ans = -1, score = -1;
        for (int i = 0; i < N; i++) {
            int ok = true;
            for (auto& x: v) {
                ok &= ~C[i][x];
            }
            if (ok && score < A[i]) {
                ans = i + 1, score = A[i];
            }
        }
        cout << ans << endl;
    }
    return 0;
}