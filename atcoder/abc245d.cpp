#include <bits/stdc++.h>

using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<int> A(N + 1), B(M + 1), C(N + M + 1);
    for (int i = 0; i <= N; i++) cin >> A[i];
    for (int i = 0; i <= N + M; i++) cin >> C[i];
    for (int i = M; 0 <= i; i--) {
        B[i] = C[i + N] / A[N];
        for (int j = 0; j <= N; j++) {
            C[i + j] -= B[i] * A[j];
        }
    }
    for (int i = 0; i < M; i++) cout << B[i] << " ";
    cout << B[M] << endl;
    return 0;
}