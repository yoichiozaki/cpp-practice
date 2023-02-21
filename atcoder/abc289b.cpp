#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(M);
    for (int i = 0; i < M; i++) cin >> A[i];
    vector<int> B(N + 1);
    for (auto& pos : A) B[pos] = 1;
    vector<int> ans;
    for (int i = 1, j = 1; i <= N; i = ++j) {
        while (B[j]) j += 1;
        for (int k = j; k >= i; k--) ans.push_back(k);
    }
    for (int i = 0; i < N; i++) cout << ans[i] << " \n"[i + 1 == N];
    return 0;
}