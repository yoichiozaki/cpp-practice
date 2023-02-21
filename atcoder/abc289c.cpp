#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<int>> A(M);
    for (int i = 0; i < M; i++) {
        int c; cin >> c;
        A[i].resize(c);
        for (auto& x : A[i]) cin >> x;
    }
    int ans = 0;
    for (int b = 0; b < (1 << M); b++) {
        set<int> S;
        for (int i = 0; i < M; i++) {
            if ((b >> i) & 1) {
                for (auto& x : A[i]) S.insert(x);
            }
        }
        ans += (int)S.size() == N;
    }
    cout << ans << endl;
    return 0;
}